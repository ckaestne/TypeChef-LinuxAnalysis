package de.fosd.typechef.linux

import featuremodel.{LinuxDimacsModel, LinuxApproxModel}
import java.io.File
import util.parsing.combinator._
import de.fosd.typechef.featureexpr.{FeatureExprFactory, FeatureModel, FeatureExpr, FeatureExprParser}


object CheckFeatureExpr extends App {
    if (args.size != 1 && !new File("formula").exists()) {
        println("expected feature expression as parameter")
        System.exit(0)
    }

    val NoFeatureModel = FeatureExprFactory.default.featureModelFactory.empty

    val fexprStrs = if (args.size > 0) Seq(args(0)) else scala.io.Source.fromFile("formula").getLines()

    val fmApprox = new LinuxApproxModel().createFeatureModel
    val fmDimacs = new LinuxDimacsModel().createFeatureModel
    val fmDimacsNew = new LinuxDimacsModel().createFeatureModel2

    for (fexprStr <- fexprStrs; if (!fexprStr.trim.isEmpty)) {

        val fexpr = new FeatureExprParser().parse(fexprStr)
        println("\n" + fexpr.toString.take(400) + "...")


        def status(fexpr: FeatureExpr, fm: FeatureModel): String =
	    if (!fexpr.isSatisfiable(fm)) "contradiction"
	    else if (fexpr.isTautology(fm)) "tautology"
	    else "satisfiable"
//            (if (fexpr.isSatisfiable(fm)) "SAT" else "!SAT") + ", " + (if (fexpr.isTautology(fm)) "TAU" else "!TAU")

        println("Plain: " + status(fexpr, NoFeatureModel))

        println("Approx.fm: " + status(fexpr, fmApprox))

        println("Dimacs.old: " + status(fexpr, fmDimacs))

        println("Dimacs: " + status(fexpr, fmDimacsNew))

        val undertakerFMgen = new UndertakerFMParser("x86.model")
        val slicedFExpr = undertakerFMgen.sliceModel(fexpr)
        assert(slicedFExpr.isSatisfiable(), "fm " + slicedFExpr + " is not satisfiable")
        println("Undertaker: " + status(slicedFExpr and fexpr, NoFeatureModel))
        //
        //
        //            val features = fexpr.collectDistinctFeatures
        //            for (f <- features) {
        //                val expr = f
        //
        //                val slicedFExpr = undertakerFMgen.sliceModel(expr)
        //
        //                assert(expr.isSatisfiable(fmDimacs) == (slicedFExpr implies expr).isSatisfiable(), expr + ": " + expr.isSatisfiable(fmDimacs) + " -- " + (slicedFExpr implies expr).isSatisfiable())
        //
        //            }
        //
        //            for (ts <- features.tails; j <- ts; if (ts.head != j)) {
        //                val expr = ts.head and j
        //
        //                val slicedFExpr = undertakerFMgen.sliceModel(expr)
        //
        //                assert(expr.isSatisfiable(fmDimacs) == (slicedFExpr implies expr).isSatisfiable(), expr + ": " + expr.isSatisfiable(fmDimacs) + " -- " + (slicedFExpr implies expr).isSatisfiable())
        //
        //            }
    }

    //    //    for (i<- 1 until 207)
    //    //        new UndertakerFMParser("x86.model",i)
    //    new UndertakerFMParser("x86.model", 25)
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
