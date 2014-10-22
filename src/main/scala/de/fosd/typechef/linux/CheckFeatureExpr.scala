package de.fosd.typechef.linux

import java.io.{File, FileWriter}

import de.fosd.typechef.featureexpr._
import de.fosd.typechef.featureexpr.sat.SATFeatureModel

import scala.util.parsing.combinator._


object CheckFeatureExpr {

    private case class Config(fms: List[(String, FeatureModel)] = List(("No FM", NoFeatureModel)),
                              inputs: List[FeatureExpr] = Nil,
                              undertakerModel: List[(String, File)] = Nil)

    val NoFeatureModel = FeatureExprFactory.default.featureModelFactory.empty

    private def loadFExprFM(file: File) = FeatureExprFactory.default.featureModelFactory.create(parseFExprFile(file))

    private def loadDimacsFM(file: File): FeatureModel = {
        println("loading feature model...");
        val start = System.currentTimeMillis
        val featureModel = FeatureExprFactory.default.featureModelFactory.createFromDimacsFile(file.getAbsolutePath)
        println("done. [" + (System.currentTimeMillis - start) + " ms]")
        featureModel
    }

    private def parseFExpr(expr: String) = new FeatureExprParser().parse(expr)

    private def parseFExprFile(file: File) = new FeatureExprParser().parseFile(file)

    def main(args: Array[String]): Unit = {
        val parser = new scopt.OptionParser[Config]("CheckFeatureExpr") {
            opt[File]("fexprFM") maxOccurs(Int.MaxValue) valueName ("<file>") action { (file, config) =>
                assert(file.exists(), "file %s does not exist".format(file))
                config.copy(fms = (file.getName, loadFExprFM(file)) :: config.fms)
            } text ("feature model in the feature expression format of approx.fm")
            opt[File]("dimacsFM") maxOccurs(Int.MaxValue) valueName ("<file>") action { (file, config) =>
                assert(file.exists(), "file %s does not exist".format(file))
                config.copy(fms = (file.getName, loadDimacsFM(file)) :: config.fms)
            } text ("feature model in the dimacs format (all variable names are prefixed by CONFIG_)")
            opt[File]("undertakerFM") maxOccurs(Int.MaxValue)  valueName ("<file>") action { (file, config) =>
                assert(file.exists(), "file %s does not exist".format(file))
                config.copy(undertakerModel = (file.getName, file) :: config.undertakerModel)
            } text ("feature model in the undertaker format")
            opt[File]("inputFile")  maxOccurs(Int.MaxValue) valueName ("<file>") action { (file, config) =>
                assert(file.exists(), "file %s does not exist".format(file))
                config.copy(inputs = scala.io.Source.fromFile("formula").getLines().filterNot(_.trim.isEmpty).toList.map(parseFExpr) ++ config.inputs)
            } text ("file with the formulas to be analyzed (one formula per line)")
            arg[String]("<formula>") optional() action { (x, c) =>
                c.copy(inputs = parseFExpr(x) :: c.inputs)
            } text ("the formula to be analyzed")
        }
        parser.parse(args, Config()) map { config =>
            _main(config)
        } getOrElse {
        }
    }

    def _main(config: Config) {


        if (config.inputs.isEmpty) {
            println("no expression to analyze provided")
        }


        for (fexpr <- config.inputs.reverse) {

            println("\n" + fexpr.toString.take(400) + "...")


            def status(fexpr: FeatureExpr, fm: FeatureModel): String =
                if (!fexpr.isSatisfiable(fm)) "contradiction"
                else if (fexpr.isTautology(fm)) "tautology"
                else "satisfiable"


            for ((name, fm) <- config.fms)
                println(name + ": " + status(fexpr, fm))


            for ((name, file) <- config.undertakerModel) {
                val undertakerFMgen = new UndertakerFMParser(file.getAbsolutePath)
                val slicedFExpr = undertakerFMgen.sliceModel(fexpr)
                assert(slicedFExpr.isSatisfiable(), "fm " + slicedFExpr + " is not satisfiable")
                println(name + ": " + status(slicedFExpr and fexpr, NoFeatureModel))
            }

        }
    }
}

/**
 * gen config parses a formula and creates a .config file (if the formula is satisfiable
 * in the feature model)
 *
 * more accurate version of this functionality now part of kconfigreader
 */
@Deprecated
object GenConfig /* extends App*/ {
    //    if (args.size != 1 && !new File("formula").exists()) {
    //        println("expected feature expression as parameter")
    //        System.exit(0)
    //    }
    //    val fmDimacs = new LinuxDimacsModel().createFeatureModel
    //
    //    val fexprStrs = if (args.size > 0) Seq(args(0)) else scala.io.Source.fromFile("formula").getLines()
    //    val fexpr = fexprStrs.map(s=>new FeatureExprParser().parse(s)).reduce(_ and _)
    //
    //    val allSymbols = fmDimacs


    def genConfig(fexpr: FeatureExpr, fm: FeatureModel): Unit = {
        val variables = fm.asInstanceOf[SATFeatureModel].variables.keys.filterNot(_ startsWith "CONFIG__").map(FeatureExprFactory.createDefinedExternal(_)).toSet ++ fexpr.collectDistinctFeatureObjects
        val assignment = fexpr.getSatisfiableAssignment(fm, variables, true)
        val config = satAssignmentToConfig(assignment)

        val configFile = new File("..config")
        val writer = new FileWriter(configFile)

        for ((k, v) <- config)
            if (Set("y", "m") contains v)
                writer.write("%s=%s\n".format(k, v))
            else if (v == "n")
                writer.write("# %s is not set\n".format(k))
            else
                writer.write("%s=%s\n".format(k, v))

        writer.close()

    }

    def satAssignmentToConfig(r: Option[(List[SingleFeatureExpr], List[SingleFeatureExpr])]): Map[String, String] = {
        assert(r.isDefined)

        val (enabled, disabled) = r.get

        var result: Map[String, String] = Map()
        for (f <- disabled) {
            if (f.feature startsWith "CONFIG_CHOICE") {
                /*nothing*/
            }
            else if (f.feature.endsWith("_m"))
                result += (f.feature.dropRight(7) -> "n")
            else if (f.feature contains "=")
                result += (f.feature.take(f.feature.indexOf("=")) -> "n")
            else
                result += (f.feature -> "n")
        }
        for (f <- enabled) {
            if (f.feature startsWith "CONFIG_CHOICE") {
                /*nothing*/
            }
            else if (f.feature.endsWith("_m"))
                result += (f.feature.dropRight(7) -> "m")
            else if (f.feature contains "=") {
                val k = f.feature.take(f.feature.indexOf("="))
                var v = f.feature.substring(f.feature.indexOf("=") + 1)
                //                if (fm.findItem(k)._type == StringType && v != "n")
                v = "\"" + v + "\""
                result += (k -> v)
            } else
                result += (f.feature -> "y")
        }
        result
    }


}


class UndertakerFMParser(filename: String, num: Int = Int.MaxValue) {

    //    val data: (FeatureExpr, Map[String, String],Set[String]) = readModelFile(filename)

    def d(s: String) = FeatureExprFactory.createDefinedExternal(s)

    val parser = new SimpleFExprParser()

    val lines = io.Source.fromFile(filename).getLines().toList

    val map = lines.drop(4).map(line => {
        val firstSpace = line.indexOf(' ')
        if (firstSpace >= 0)
            (line.take(firstSpace) -> line.drop(firstSpace + 2).dropRight(1))
        else
            (line -> "")
    }).toMap

    val alwaysOn = lines.drop(3).head.split(" ").drop(2).map(_.drop(1).dropRight(1)).take(num).toSet


    var clauses: List[FeatureExpr] = Nil

    for (f <- alwaysOn) {
        clauses = FeatureExprFactory.createDefinedExternal(f) :: clauses
        clauses = lookupFExpr(f) :: clauses

        //        println(f + " && " + lookupFExpr(f))

        assert(clauses.reduce(_ and _).isSatisfiable())
    }
    var knownFeatures: Set[String] = alwaysOn
    var openFeatures = clauses.reduce(_ and _).collectDistinctFeatures -- knownFeatures

    while (!openFeatures.isEmpty) {
        val feature = openFeatures.head
        //        println(feature)
        openFeatures = openFeatures - feature
        knownFeatures = knownFeatures + feature

        val fresult = lookupFExpr(feature)
        //        println(feature + " => " + fresult)
        val newFeatures = fresult.collectDistinctFeatures
        openFeatures = openFeatures ++ (newFeatures -- knownFeatures)

        clauses = (d(feature) implies fresult) :: clauses
        if (!clauses.reduce(_ and _).isSatisfiable()) {
            val bigform = clauses.tail.reduce(_ and _)
            val f = FeatureExprFactory.createDefinedExternal(feature)
            //
            //            for (f<-"CONFIG_M68K,CONFIG_ISA,CONFIG_M32R,CONFIG_AVR32,CONFIG_BLACKFIN,CONFIG_FRV,CONFIG_PARPORT_PC,CONFIG_MN10300,CONFIG_MODULES,CONFIG_SPARC32,CONFIG_SPARC64,CONFIG_PCI".split(",")) {
            //                println(f+": "+(bigform and d(f).not).isSatisfiable() + " "+ (bigform and d(f).not).isTautology())
            //            }

            println("" + bigform + f)
            assert(false)
        }
    }
    //    println(knownFeatures.size)


    var alwaysExpr = FeatureExprFactory.True
    alwaysExpr = alwaysOn.map(FeatureExprFactory.createDefinedExternal(_)).reduce[FeatureExpr](_ and _) and
        sliceModel(alwaysOn, Set())
    assert(alwaysExpr.isSatisfiable(), "closure of always_on " + num + " is not satisfiable: " + alwaysExpr)


    def sliceModel(fexpr: FeatureExpr): FeatureExpr =
        alwaysExpr and
            sliceModel(fexpr.collectDistinctFeatures, Set() /*alwaysOn*/)

    private def sliceModel(features: Set[String], initallyKnown: Set[String]): FeatureExpr = {
        var result = FeatureExprFactory.True

        var openFeatures = features -- initallyKnown
        var knownFeatures: Set[String] = initallyKnown
        while (!openFeatures.isEmpty) {
            val feature = openFeatures.head
            openFeatures = openFeatures - feature
            knownFeatures = knownFeatures + feature

            val fresult = lookupFExpr(feature)
            //            println(feature + " -> " + fresult)
            val newFeatures = fresult.collectDistinctFeatures
            openFeatures = openFeatures ++ (newFeatures -- knownFeatures)

            val newResult = result and (FeatureExprFactory.createDefinedExternal(feature) implies fresult)
            if (!newResult.isSatisfiable())
                println(result + " and " + fresult)
            result = newResult
        }

        result
    }

    def lookupFExpr(feature: String): FeatureExpr = {
        val exprStr = map.getOrElse(feature, "")
        if (exprStr.trim().isEmpty) FeatureExprFactory.True
        else parser.parse(exprStr)
    }

}

class SimpleFExprParser extends RegexParsers {

    def toFeature(name: String) = FeatureExprFactory.createDefinedExternal(name)


    //implications
    def expr: Parser[FeatureExpr] =
        aexpr ~ opt("->" ~> expr) ^^ {
            case a ~ Some(b) => a implies b
            case a ~ None => a
        }

    def aexpr: Parser[FeatureExpr] =
        term ~ rep("||" ~> expr) ^^ {
            case a ~ bs => bs.foldLeft(a)(_ or _)
        }

    def term: Parser[FeatureExpr] =
        bool ~ rep("&&" ~> expr) ^^ {
            case a ~ bs => bs.foldLeft(a)(_ and _)
        }

    def bool: Parser[FeatureExpr] =
        "!" ~> bool ^^ (_ not) |
            ("(" ~> expr <~ ")") |
            ID ^^ toFeature


    def ID = "[A-Za-z0-9_]*".r

    def parse(featureExpr: String): FeatureExpr = parseAll(expr, featureExpr) match {
        case Success(r, _) => r
        case NoSuccess(msg, _) => throw new Exception("error parsing " + featureExpr + " " + msg)
    }
}
