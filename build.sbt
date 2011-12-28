name := "TypeChef-LinuxAnalysis"

version := "0.3"

organization := "de.fosd.typechef"

scalaVersion := "2.9.1"

libraryDependencies += "de.fosd.typechef" %% "ctypechecker" % "0.3"

libraryDependencies += "gnu.getopt" % "java-getopt" % "1.0.13"

libraryDependencies +="junit" % "junit" % "4.8.2" % "test"

libraryDependencies += "com.novocode" % "junit-interface" % "0.6" % "test"
