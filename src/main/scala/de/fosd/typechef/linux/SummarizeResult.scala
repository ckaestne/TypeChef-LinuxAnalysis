package de.fosd.typechef.linux

import java.io.File

/**
 * summarizes the result found in all .dbg files
 */
object SummarizeResult extends App {

    if (args.length != 2)
        println("provide path to project and filelist as parameters")
    val dir = args(0);
    val filelist = args(1);

    def error(msg: String, file: String, isComment: Boolean) {
        if (isComment)
            println("COMMENT " + file)
        else
            println("FAIL[%s] %s".format(msg, file))
    }

    for (line <- io.Source.fromFile(filelist).getLines()) {
        val file = dir + "/" + line + ".dbg"
        val commentfile = dir + "/" + line + ".comment"
        val commentExists = new File(commentfile).exists

        if (!new File(file).exists) {
            error("file does not exist", line, commentExists)
        } else {
            val lines = io.Source.fromFile(file).getLines().toList

            if (lines.filterNot(_.trim.length == 0).isEmpty)
                error("file empty", line, commentExists)
            else
            if (!lines.exists(_ == "True\tlexing succeeded"))
                error("lexing failed", line, commentExists)
            else
            if (!lines.exists(_ == "True\tparsing succeeded"))
                error("parsing failed", line, commentExists)
            else
            if (!lines.exists(_ == "No type errors found."))
                error("type checking failed", line, commentExists)
            else
                println("SUCCESS " + line)
        }
    }

}
