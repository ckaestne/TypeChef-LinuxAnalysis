package de.fosd.typechef.linux

import java.io._
import xml.XML
import de.fosd.typechef.featureexpr._

/**
 * usage:
 *
 * errorList file outputFile
 * or
 * errorList -f filelist outputFile
 */
object FilterAllYesConfigFiles extends App {

    val files = scala.io.Source.fromFile("linux_files.lst").getLines.toList

    val config = scala.io.Source.fromFile("l/.config").getLines.
        filterNot(_ startsWith "#").
        filterNot(_.isEmpty).
        map((x: String) => x.take(x.indexOf("="))    ).
        toSet
//    println(config)                                      /**/
    for (file <- files) {

        val pcFile = new File("l/" + file + ".pc")
        if (pcFile.exists) {
            val pc = new FeatureExprParser(FeatureExprFactory.dflt).parseFile(pcFile)

            val compilable=pc.evaluate(config)

            if (!compilable) {
                println("Removing file "+file+", pc: "+pc)

                try {
                new File("l/"+file+".i").delete()
                new File("l/"+file+".i.dbg").delete()
                new File("l/"+file+".i.xml").delete()
                } catch {case e:Exception => e.printStackTrace()}
            }

            //            filePC.

        }


    }

}
