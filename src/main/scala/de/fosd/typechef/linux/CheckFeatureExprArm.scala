package de.fosd.typechef.linux

import featuremodel._
import java.io.File
import util.parsing.combinator._
import de.fosd.typechef.featureexpr.{FeatureExprFactory, FeatureModel, FeatureExpr, FeatureExprParser}


object CheckFeatureExprArm extends App {
    if (args.size != 1 && !new File("formula").exists()) {
        println("expected feature expression as parameter")
        System.exit(0)
    }

    val NoFeatureModel = FeatureExprFactory.default.featureModelFactory.empty

    val fexprStrs = if (args.size > 0) Seq(args(0)) else scala.io.Source.fromFile("formula").getLines()

    val fmDimacs = new LinuxDimacsModel().createFeatureModelArm

    for (fexprStr <- fexprStrs; if (!fexprStr.trim.isEmpty)) {

        val fexpr = new FeatureExprParser().parse(fexprStr)
        println("\n" + fexpr.toString.take(400) + "...")


        def status(fexpr: FeatureExpr, fm: FeatureModel): String =
            (if (fexpr.isSatisfiable(fm)) "SAT" else "!SAT") + ", " + (if (fexpr.isTautology(fm)) "TAU" else "!TAU")

        println("Plain: " + status(fexpr, NoFeatureModel))

        println("Dimacs: " + status(fexpr, fmDimacs))

        val undertakerFMgen = new UndertakerFMParser("arm.model")
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


