package de.fosd.typechef.linux

import java.io._

import de.fosd.typechef.featureexpr.FeatureExpr
import de.fosd.typechef.featureexpr.FeatureExprFactory.{False, True, createDefinedExternal}

import scala.io.Source
import scala.util.control.Breaks
import scala.util.parsing.combinator._

/**
 * processes thorstens file list (passed as parameter) and creates corresponding .pc files
 *
 * (presence conditions for files, in contrast to .pi.fm which represents a local feature model for dependencies)
 *
 * call with file created by thorsten as parameter
 */
object ProcessFileList extends RegexParsers {

    def toFeature(name: String, isModule: Boolean): FeatureExpr = {
        val cname = "CONFIG_" + (if (isModule) name + "_MODULE" else name)
        if (openFeatures.isDefined && !(openFeatures.get contains cname)) False
        else
            createDefinedExternal(cname)
    }

    def expr: Parser[FeatureExpr] =
        ("(" ~> (expr ~ "||" ~ expr) <~ ")") ^^ {
            case (a ~ _ ~ b) => a or b
        } |
            term

    def term: Parser[FeatureExpr] =
        "!" ~> commit(expr) ^^ (_ not) |
            ("(" ~> (expr ~ "&&" ~ expr) <~ ")") ^^ {
                case (a ~ _ ~ b) => a and b
            } |
            bool

    def bool: Parser[FeatureExpr] =
        "[TRUE]" ^^ (_ => True) |
            "InvalidExpression()" ^^ (_ => False) |
            ("(" ~> (ID ~ "!=" ~! featVal) <~ ")") ^^ {
                case (id ~ _ ~ isModule) =>
                    if (!isModule)
                        toFeature(id, false).not
                    // X != y should be probably translated to something like
                    // CONFIG_X && CONFIG_X_2 || !CONFIG_X; to represent X ==
                    // "m", in the SAT-solver we enable CONFIG_X and CONFIG_X_2
                    // (by having CONFIG_X_2 imply CONFIG_X), while autoconf.h
                    // defines just CONFIG_X_MODULE.
                    else
                    // X != m should be probably translated to something like CONFIG_X && !CONFIG_X_2.
                        throw new RuntimeException("Can't handle this case!")
            } |
            ("(" ~> (ID ~ "==" ~ featVal) <~ ")") ^^ {
                case (id ~ _ ~ isModule) => toFeature(id, isModule)
            } |
            ("(" ~> (ID ~ "==" ~ stringLit) <~ ")") ^^ {
                case (id ~ _ ~ value) => println("nonboolean %s=%s not supported".format(id, value)); True
            } |
            ID ^^ (id => toFeature(id, true) or toFeature(id, false))

    //Having this case here makes the grammar not LL(1) - and one expression
    //triggers exponential backtracking. Since source
    //phrases are always parenthesizes, I can include parentheses in each
    //production.
    //|
    //"(" ~> expr <~ ")"

    def ID = "[A-Za-z0-9_]*".r

    def featVal = ("\"" ~> "(y|m)".r <~ "\"") ^^ (_ == "m")

    def stringLit = ("\"" ~> "[a-z]*".r <~ "\"")


    private case class Config(workingDir: Option[java.io.File] = None, openFeatureList: Option[java.io.File] = None, inputFile: java.io.File = null)


    def main(args: Array[String]): Unit = {
        val parser = new scopt.OptionParser[Config]("LinuxLinker") {
            opt[File]("workingDir") valueName ("<dir>") action { (x, c) =>
                c.copy(workingDir = Some(x))
            }
            opt[File]("openFeatureList") valueName ("<dir>") action { (x, c) =>
                c.copy(openFeatureList = Some(x))
            } text("an open feature list can be provided to filter any features not supported in this architecture")
            arg[File]("<file>") required() action { (x, c) =>
                c.copy(inputFile = x)
            }
        }
        parser.parse(args, Config()) map { config =>
            _main(config)
        } getOrElse {
        }
    }


    var openFeatures: Option[Set[String]] = None

    def _main(config: Config) {
        val pcList = config.inputFile

        val lines = io.Source.fromFile(pcList).getLines
        val mybreaks = new Breaks
        val stderr = new PrintWriter(System.err, true)

        openFeatures = config.openFeatureList map (Source.fromFile(_).getLines().toSet)


        import mybreaks.{break, breakable}
        breakable {
            val FileNameFilter = """.*\.c""".r
            for (line <- lines; fields = line.split(':'); fullFilename = fields(0) if (
                fullFilename match {
                    case FileNameFilter(_*) => true
                    case _ => false
                }
                )) {
                val fullFilenameNoExt = config.workingDir.map(_.getPath + "/").getOrElse("") + fullFilename.dropRight(2)
                val filename = fullFilename.substring(fullFilename.lastIndexOf("/") + 1).dropRight(2)

                val pcExpr = parseAll(expr, fields(1))

                pcExpr match {
                    case Success(cond, _) =>
                        //file should be parsed
                        println(fullFilename + " " + cond)

                        val pcFile = new File(fullFilenameNoExt + ".pc")
                        if (!cond.isTautology()) {
                            val pcWriter = new PrintWriter(pcFile)
                            cond.print(pcWriter)
                            pcWriter.close
                        } else
                        if (pcFile.exists()) pcFile.delete()

                    case NoSuccess(msg, _) =>
                        stderr.println(fullFilename + " " + pcExpr)
                        break
                }
            }
        }
    }
}
