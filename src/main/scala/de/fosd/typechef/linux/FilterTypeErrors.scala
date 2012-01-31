package de.fosd.typechef.linux

import featuremodel.LinuxDimacsModel
import java.io.File
import de.fosd.typechef.featureexpr.{FeatureExpr, FeatureExprParser}

/**
 * this class parses a .dbg file and filters type errors with satisfiable conditions according to the
 * dimacs model
 */

object FilterTypeErrors extends App {

    if (args.size != 1 || !new File(args(0)).exists) {
        println(".dbg file expected as parameter")
        sys.exit()
    }

    val fmDimacs = new LinuxDimacsModel().createFeatureModel


    val lines = scala.io.Source.fromFile(args(0)).getLines()
    while (lines.hasNext) {
        val line: String = lines.next

        if (line.startsWith("  -")) {
            val formula = line.substring(7, line.indexOf(']'))

            val fexpr = if (formula=="True") FeatureExpr.base else new FeatureExprParser().parse(formula)

            if (fexpr.isSatisfiable(fmDimacs)) {
                println(fexpr)
                println(line.substring(line.indexOf(']')+1))
                println(lines.next)
                println()
            }
        }


    }


}