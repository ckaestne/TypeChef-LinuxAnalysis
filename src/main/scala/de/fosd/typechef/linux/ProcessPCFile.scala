package de.fosd.typechef.linux

import java.io._

import de.fosd.typechef.featureexpr.FeatureExprFactory.{False, True, createDefinedExternal}
import de.fosd.typechef.featureexpr.{FeatureExpr, FeatureExprFactory, FeatureExprParser}

import scala.io.Source
import scala.util.parsing.combinator._


/**
 * The CleanFileList tool takes a file list produced by KConfigMiner and a feature model
 *
 * It parses the KConfigMiner format, removes all .S files, removes all files
 * with unsatisfiable presence conditions, and prints the output in a format
 * that is easier to process (directly parsable by TypeChef) to stdout
 *
 * If also an open feature list is given, all features not on that list are substituted
 * by False
 */
object CleanFileList {

    private case class Config(openFeatureList: Option[java.io.File] = None,
                              featureModel: Option[java.io.File] = None,
                              inputFile: java.io.File = null)


    def main(args: Array[String]): Unit = {
        val parser = new scopt.OptionParser[Config]("CleanFileList") {
            opt[File]("openFeatureList") valueName ("<dir>") action { (x, c) =>
                c.copy(openFeatureList = Some(x))
            } text ("an open feature list can be provided to filter any features not supported in this architecture")
            opt[File]("featureModel") valueName ("<dimacs file>") action { (x, c) =>
                c.copy(openFeatureList = Some(x))
            } text ("feature model in dimacs format")
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
        val stderr = new PrintWriter(System.err, true)
        if (!config.featureModel.isDefined)
            stderr.println("Warning: No feature model provided.")
        if (!config.openFeatureList.isDefined)
            stderr.println("Warning: No open-feature list provided.")


        openFeatures = config.openFeatureList map (Source.fromFile(_).getLines().toSet)
        val fmFactory = FeatureExprFactory.dflt.featureModelFactory
        val featureModel = config.featureModel.map(f => fmFactory.createFromDimacsFile(f.getAbsolutePath)).getOrElse(fmFactory.empty)
        val parser = new KConfigMinerParser(openFeatures)
        val FileNameFilter = """.*\.c""".r

        val lines = io.Source.fromFile(config.inputFile).getLines
        for (line <- lines; fields = line.split(':'); fullFilename = fields(0) if (
            fullFilename match {
                case FileNameFilter(_*) => true
                case _ => false
            }
            )) {
            val pcExpr: parser.ParseResult[FeatureExpr] = parser.parseAll(parser.expr, fields(1))

            pcExpr match {
                case parser.Success(cond: FeatureExpr, _) =>
                    //file should be parsed
                    if (cond.isSatisfiable(featureModel))
                        println(fullFilename.dropRight(2) + ": " + cond)
                    else
                        stderr.println("Skipping file with unsatisfiable condition %s: %s (%s)".format(fullFilename, fields(1), cond))


                case parser.NoSuccess(msg, _) =>
                    stderr.println("Could not parse " + fullFilename + ": " + fields(1))
            }
        }
    }


}

/**
 * The ExtractFileList tool takes a preprocessed file with presence conditions (created by CleanFileList)
 * and creates .pc files
 */
object GeneratePCFiles {


    private case class Config(workingDir: java.io.File = new File("."),
                              inputFile: java.io.File = null)


    def main(args: Array[String]): Unit = {
        val parser = new scopt.OptionParser[Config]("CleanFileList") {
            opt[File]("workingDir") valueName ("<dir>") action { (x, c) =>
                c.copy(workingDir = x)
            } text ("working directory (root of the linux tree)")
            arg[File]("<file>") required() action { (x, c) =>
                c.copy(inputFile = x)
            }
        }
        parser.parse(args, Config()) map { config =>
            _main(config)
        } getOrElse {
        }
    }

    def _main(config: Config) {
        assert(config.workingDir.isDirectory && config.workingDir.exists(), "working directory not found")
        assert(config.inputFile.exists(), "input file not found: " + config.inputFile)

        val lines = io.Source.fromFile(config.inputFile).getLines
        for (line <- lines; fields = line.split(':')) {
            val filename = fields(0)
            val fexpr = new FeatureExprParser().parse(fields(1))

            val pcFile = new File(config.workingDir, filename + ".pc")
//            println(pcFile+" -> "+fexpr)
            if (!fexpr.isTautology()) {
                val pcWriter = new PrintWriter(pcFile)
                fexpr.print(pcWriter)
                pcWriter.close
            } else
            if (pcFile.exists()) pcFile.delete()
        }
    }
}


/**
 * processes thorstens file list (passed as parameter) and checks which files have satisfiable
 * presence conditions
 */
class KConfigMinerParser(openFeatures: Option[Set[String]]) extends RegexParsers {

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
                case (id ~ _ ~ value) => System.err.println("nonboolean %s=%s not supported".format(id, value)); True
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


}
