package de.fosd.typechef.linux

import featuremodel.LinuxExclDeadModel
import java.io.File
import scala.collection.JavaConversions._
import de.fosd.typechef.featureexpr.FeatureExprFactory
import de.fosd.typechef.LexerToken
import de.fosd.typechef.lexer.LexerFrontend

/**
 * compares two parially preprocessed files if they have equivalent token streams.
 *
 * expects to find no #define directives
 *
 * comments are skipped, whitespace is normalized, presence conditions are compared for equivalence
 *
 *
 *
 */

object TokenStreamDiff {

    val fm = new LinuxExclDeadModel().createFeatureModel.and(FeatureExprFactory.createDefinedExternal("CONFIG_OPTIMIZE_INLINING").not)

    def main(args: Array[String]): Unit = {
        if (args.length != 2)
            println("expecting two files as parameters")
        else if (!new File(args(0)).exists)
            println("parameter " + args(0) + " is not a file")
        else if (!new File(args(1)).exists)
            println("parameter " + args(1) + " is not a file")
        else {
            var r: Seq[LexerToken] = parse(args(0))
            var s: Seq[LexerToken] = parse(args(1))

            var last = List[LexerToken]()

            while (!r.isEmpty) {


                var mismatch = false;

                //compare feature conditions, if possible without feature model
                //lazily search for dead featrues
                def compareFeatures: Boolean = {
                    if (!r.head.getFeature.equivalentTo(s.head.getFeature)) {
                        if (!r.head.getFeature.isSatisfiable(fm)) {
                            r = r.tail
                            compareFeatures
                        } else
                        if (!s.head.getFeature.isSatisfiable(fm)) {
                            s = s.tail
                            compareFeatures
                        } else
                            r.head.getFeature.equivalentTo(s.head.getFeature, fm)
                    } else true
                }

                if (!compareFeatures)
                    mismatch = true


                val a = r.head
                val b = s.head

                if (a.getText != b.getText) {
                    //workaround for SuperC bug with not whitespace between two tokens
                    if (a.getText + r.tail.head.getText == b.getText)
                        r = r.tail
                    else
                        mismatch = true;
                }



                if (mismatch) {
                    println("token mismatch: \n" +
                        "\t" + a.getText + " (line " + a.getLine + ")  " + a.getFeature + "\n" +
                        "\t" + b.getText + " (line " + b.getLine + ")  " + b.getFeature + "\n" +
                        "\tprevious: " + last.take(30).reverse.map(_.getText).mkString(" "))
                    assert(false, "stoping on mismatch")
                }
                last = a :: last

                r = r.tail
                s = s.tail
            }


            println("done.")
        }
    }


    def parse(file: String): Seq[LexerToken] = new LexerFrontend().parseFile(file, List(), FeatureExprFactory.default.featureModelFactory.empty)

    def removeDead(l: Seq[LexerToken]): Seq[LexerToken] =
        l.filter(t => {
            val dead = t.getFeature.isContradiction(fm)
            if (dead) println("warning token " + t + " is dead")
            !dead
        })

}