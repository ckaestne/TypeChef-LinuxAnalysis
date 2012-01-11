package de.fosd.typechef.linux

import featuremodel.{LinuxDimacsModel, LinuxApproxModel}
import java.io.File
import util.parsing.combinator.RegexParsers
import util.parsing.combinator._
import de.fosd.typechef.featureexpr.{NoFeatureModel, FeatureModel, FeatureExpr, FeatureExprParser}


object CheckFeatureExpr extends App {
    //    if (args.size != 1 && !new File("formula").exists()) {
    //        println("expected feature expression as parameter")
    //        System.exit(0)
    //    }
    //
    //
    //    val fexprStrs = if (args.size > 0) Seq(args(0)) else scala.io.Source.fromFile("formula").getLines()
    //
    //    val fmApprox = new LinuxApproxModel().createFeatureModel
    //    val fmDimacs = new LinuxDimacsModel().createFeatureModel
    //
    //    for (fexprStr <- fexprStrs; if (!fexprStr.trim.isEmpty)) {
    //        println("\n" + fexprStr.take(100) + "...")
    //
    //        val fexpr = new FeatureExprParser().parse(fexprStr.replaceAll("def\\(", "defined(").replaceAll("\\|", "||").replaceAll("&", "&&"))
    //
    //
    //        def status(fexpr: FeatureExpr, fm: FeatureModel): String =
    //            (if (fexpr.isSatisfiable(fm)) "SAT" else "!SAT") + ", " + (if (fexpr.isTautology(fm)) "TAU" else "!TAU")
    //
    //        println("Plain: " + status(fexpr, null))
    //
    //        println("Approx.fm: " + status(fexpr, fmApprox))
    //
    //        println("Dimacs: " + status(fexpr, fmDimacs))
    //
    //        val undertakerFMgen = new UndertakerFMParser("x86.model")
    //        val slicedFExpr = undertakerFMgen.sliceModel(fexpr)
    //        assert(slicedFExpr.isSatisfiable(), "fm " + slicedFExpr + " is not satisfiable")
    //        //        val undertakerFM=NoFeatureModel.and(slicedFExpr)
    //        println("Undertaker: " + status(slicedFExpr implies fexpr, null))
    //
    //
    //        val features = fexpr.collectDistinctFeatures
    //        for (f <- features) {
    //            val expr = f
    //
    //            val slicedFExpr = undertakerFMgen.sliceModel(expr)
    //
    //            assert(expr.isSatisfiable(fmDimacs) == (slicedFExpr implies expr).isSatisfiable(), expr + ": " + expr.isSatisfiable(fmDimacs) + " -- " + (slicedFExpr implies expr).isSatisfiable())
    //
    //        }
    //
    //        for (ts <- features.tails; j <- ts; if (ts.head != j)) {
    //            val expr = ts.head and j
    //
    //            val slicedFExpr = undertakerFMgen.sliceModel(expr)
    //
    //            assert(expr.isSatisfiable(fmDimacs) == (slicedFExpr implies expr).isSatisfiable(), expr + ": " + expr.isSatisfiable(fmDimacs) + " -- " + (slicedFExpr implies expr).isSatisfiable())
    //
    //        }
    //    }

    //    for (i<- 1 until 207)
    //        new UndertakerFMParser("x86.model",i)
    new UndertakerFMParser("x86.model", 25)
}


class UndertakerFMParser(filename: String, num: Int) {

    //    val data: (FeatureExpr, Map[String, String],Set[String]) = readModelFile(filename)

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
    var alwaysExpr = FeatureExpr.base
    alwaysExpr = alwaysOn.map(FeatureExpr.createDefinedExternal(_)).reduce[FeatureExpr](_ and _) and
        sliceModel(alwaysOn, Set())
    assert(alwaysExpr.isSatisfiable(), "closure of always_on " + num + " is not satisfiable: " + alwaysExpr)


    def sliceModel(fexpr: FeatureExpr): FeatureExpr =
        alwaysExpr and
            sliceModel(fexpr.collectDistinctFeatures.map(_.feature), alwaysOn)

    private def sliceModel(features: Set[String], initallyKnown: Set[String]): FeatureExpr = {
        var result = FeatureExpr.base

        var openFeatures = features -- initallyKnown
        var knownFeatures: Set[String] = initallyKnown
        while (!openFeatures.isEmpty) {
            val feature = openFeatures.head
            println(feature)
            openFeatures = openFeatures - feature
            knownFeatures = knownFeatures + feature

            val fresult = lookupFExpr(feature)
            val newFeatures = fresult.collectDistinctFeatures.map(_.feature)
            openFeatures = openFeatures ++ (newFeatures -- knownFeatures)

            if (!(result and fresult).isSatisfiable())
                println(result + " and " + fresult)
            result = result and (FeatureExpr.createDefinedExternal(feature) implies fresult)
        }
        println(knownFeatures.size)

        result
    }

    def lookupFExpr(feature: String): FeatureExpr = {
        val exprStr = map.getOrElse(feature, "")
        if (exprStr.trim().isEmpty) FeatureExpr.base
        else parser.parse(exprStr)
    }

}

class SimpleFExprParser extends RegexParsers {

    def toFeature(name: String) = FeatureExpr.createDefinedExternal(name)


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