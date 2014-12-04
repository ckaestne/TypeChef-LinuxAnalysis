name := "TypeChef-LinuxAnalysis"

version := "0.3.8"

organization := "de.fosd.typechef"

scalaVersion := "2.11.4"

scalacOptions ++= Seq("-deprecation", "-unchecked", "-optimise", "-feature")

libraryDependencies += "de.fosd.typechef" %% "frontend" % "0.3.7"

libraryDependencies += "de.fosd.typechef" % "javabdd_repackaged" % "1.0b2"

libraryDependencies += "junit" % "junit" % "4.11" % "test"

libraryDependencies += "com.github.scopt" %% "scopt" % "3.2.0"

libraryDependencies += "com.novocode" % "junit-interface" % "0.11" % "test"

//generate typechef.sh file with full classpath
TaskKey[File]("mkrun") <<= (baseDirectory, fullClasspath in Runtime, mainClass in Runtime) map {
    (base, cp, main) =>
        val template = """#!/bin/sh
java -ea -Xmx1G -Xms128m -Xss10m -classpath "%s" %s "$@"
                       """
        val contents = template.format(cp.files.absString, "")
        val out = base / "run.sh"
        IO.write(out, contents)
        out.setExecutable(true)
        out
}
