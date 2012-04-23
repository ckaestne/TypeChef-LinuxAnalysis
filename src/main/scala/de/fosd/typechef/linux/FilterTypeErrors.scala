package de.fosd.typechef.linux

import featuremodel.LinuxDimacsModel
import java.io.File
import de.fosd.typechef.featureexpr.{FeatureExprFactory, FeatureExprParser}

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

    var errors = 0
    var realerrors = 0
    val start = System.currentTimeMillis()
    while (lines.hasNext) {
        val line: String = lines.next

        if (line.startsWith("  -")) {
            errors += 1
            val formula = line.substring(7, line.indexOf(']'))

            val fexpr = if (formula == "True") FeatureExprFactory.True else new FeatureExprParser().parse(formula)

            if (fexpr.isSatisfiable(fmDimacs)) {
                realerrors += 1
                println(fexpr)
                println(line.substring(line.indexOf(']') + 1))
                println(lines.next)
                println()
            }
        }
    }
    println("found " + realerrors + " type errors (out of " + errors + ") in " + (System.currentTimeMillis() - start) + " ms")


}