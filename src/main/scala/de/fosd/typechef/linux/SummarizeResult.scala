package de.fosd.typechef.linux

import java.io.File

/**
 * summarizes the result found in all .dbg files
 */
object SummarizeResult extends App {

    if (args.length!=2)
        println("provide path to project and filelist as parameters")
    val dir = args(0);
    val filelist = args(1);

    for (line<-io.Source.fromFile(filelist).getLines()) {
        val  file = dir+"/"+line+".dbg"

        if (!new File(file).exists) {
            println("FAIL[file does not exist] "+line)
        } else {
            val lines=io.Source.fromFile(file).getLines().toList

            if (lines.filterNot(_.trim.length==0).isEmpty)
		println("FAIL[file empty] "+line)
            else
            if (!lines.exists(_=="True\tlexing succeeded"))
                println("FAIL[lexing failed] "+line)
            else
            if (!lines.exists(_=="True\tparsing succeeded"))
                println("FAIL[parsing failed] "+line)
            else
            if (!lines.exists(_=="No type errors found."))
                println("FAIL[type checking failed] "+line)
            else
                println("SUCCESS "+line)
        }
    }

}
