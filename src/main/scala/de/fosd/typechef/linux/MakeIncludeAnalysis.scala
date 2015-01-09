package de.fosd.typechef.linux

import java.io._

object MakeIncludeAnalysis extends App {

    assert(args.length >= 1 && args.length <= 2, "expected a parameter pointing to the linux root directory and an optional parameter for the output file")
    val path = args(0)
    val outputStream = if (args.length >= 2) new FileOutputStream(args(1)) else System.out
    val output = new OutputStreamWriter(outputStream)
    val linuxDir = new File(path)


    /**
     * finds all parameters and corresponding conditions
     */
    def analyzeMakefile(file: File): List[(String, String)] = {
        val in = io.Source.fromFile(file)
        val lines = in.getLines().
            map(s => if (s contains "#") s.substring(0, s.indexOf("#")) else s).
            foldRight(List[String]())(
                (s, result) => if (result.isEmpty) s :: result else if (s endsWith "\\") (s.dropRight(1) + " " + result.head) :: result.tail else s :: result
            )

        lines.filter(_ startsWith "ccflags-").flatMap(s => {
            val parts = s.split("\\s[+:]?=\\s")
            assert(parts.length == 2)
            val condition = getCondition(parts(0).trim)
            val extraparams = parts(1).split("\\s").toList
            extraparams.map(p => (condition, p))
        })
    }

    def findMakefile(dir: File): Map[File, List[(String, String)]] = {
        val files = for (file <- dir.listFiles();
                         if file.isFile && file.getName == "Makefile") yield
            (file -> analyzeMakefile(file))
        val dirs = dir.listFiles().filter(_.isDirectory).flatMap(findMakefile)
        (files ++ dirs).toMap
    }

    def getCondition(ccflagsStr: String): String = {
        if (ccflagsStr == "ccflags-y") ""
        else if (ccflagsStr.matches("ccflags-\\$\\(\\w+\\)")) ccflagsStr.drop(10).dropRight(1)
        else "!UNSUPPORTED<" + ccflagsStr + ">"
    }

    def getRelativePath(f: File): String =
        f.getAbsolutePath.replace(linuxDir.getAbsolutePath, "").replace("\\", "/").dropWhile(Set('\\', '/') contains _)

    def processFlag(flag: String): Option[String] = {
        if (flag.trim.isEmpty || (flag startsWith "-O")) None
        else if (flag startsWith "-I") {
            val x = flag.drop(2).replace("$(src)/", "").replace("$(srctree)/", "")
            Some("-I $srcPath/" + x)
        } else if (flag startsWith "-D")
            Some(flag)
        else if (flag startsWith "-U")
            Some(flag)
        else {
            System.err.println("flag not supported: " + flag)
            None
        }
    }

    val extraFlags: Map[String, String] =
        for ((file, flags) <- findMakefile(linuxDir);
             (cond, flag) <- flags;
             pflag <- processFlag(flag))
        yield (getRelativePath(file.getParentFile), pflag)
    output.write(
        """#!/bin/bash
          |kbuildflags() {
          |  name="$1"
          |  base="$(basename "$1")"
          |  extraFlag=""
          | """.stripMargin)

    for ((path, flags) <- extraFlags.toList.sortBy(_._1))
        output.write( """ if grep -q "%s" <<< "$name"; then
                        |    extraFlag="$extraFlags %s"
                        |  fi
                        | """.stripMargin.format(path, flags))

    output.write(
        """ echo "$extraFlag"
          |}
        """.stripMargin)


    output.close()
}
