package de.fosd.typechef.linux

import io.Source
import de.fosd.typechef.featureexpr._
import scala.sys.process._
import java.io.{FileWriter, File}

/**
 * simple script to run one or more configurations of linux
 *
 * reads the "tasks" file from the "runconfig" directory
 * and creates log files there.
 *
 * runs make in the "l" directory
 */


object RunConfig  {
    case class Config(rootDir: Option[File]=None, clean: Boolean = false)

    def main(args:Array[String]): Unit = {
        val parser = new scopt.OptionParser[Config]("LinuxLinker") {
            opt[File]("rootDir") valueName("<dir>") action { (x, c) =>
                c.copy(rootDir = Some(x)) }
            opt[Unit]("clean") action { (x, c) =>
                c.copy(clean = true) }
        }
        parser.parse(args, Config()) map { config =>
            _main(config)
        } getOrElse {
        }
    }


    def _main(config:Config) {
        val root = config.rootDir.getOrElse(new File("."))
        val configDir = new File(root, "runconfig")
        val tasksFile = new File(configDir, "tasks")
        val linuxDir = new File(root, "l")
        assert(configDir.exists(), "expected runconfig directory")
        assert(tasksFile.exists(), "expected tasks file")
        assert(linuxDir.exists(), "expected l directory")

        val tasks = Source.fromFile(tasksFile).getLines().toList

        for (task <- tasks) {
            val c = task.split(";")
            assert(c.length == 3, "illegal task format " + task)
            val id = c(0)
            val fexpr = new FeatureExprParser().parse(c(1))
            val file = c(2)
            val logFile = new File(configDir, id + ".log")

            if (config.clean && logFile.exists())
                logFile.delete()

            if (!logFile.exists()) {
                //run analysis
                val logWriter = new FileWriter(logFile)
                def out(s: String) {
                    logWriter.write(s);
                    print(s)
                }
                out("checking " + id + " (" + file + " --  " + fexpr + ")\n\n\n")

                val fExprVamos = fexpr.toTextExpr.replaceAll("definedEx", "")

                val vamosCommand = Seq("ssh", "vamos1.informatik.uni-erlangen.de", "undertaker", "-j", "checkexpr", "-m", "linux-stable-3e7ad8e/models/x86.model", "\"" + fExprVamos + "\"")
                out(vamosCommand.mkString(" ") + "\n\n")
                val logger = ProcessLogger(s => out(s + "\n"), s => out("[E] " + s + "\n"))
                val config = vamosCommand !! logger

                out(".config\n" + config.drop(2) + "\n\n\n\n")

                val configWriter = new FileWriter(new File(linuxDir, ".config"))
                configWriter.write(config)
                configWriter.close

                out("clean .config\n")
                Process("./cleanconfig.sh", linuxDir) ! logger
                out("\n\n\n\n")

                out("make " + file + ".o\n")
                Process("make " + file+".o", linuxDir) ! logger
                out("\n\n\n\n")

                out("make " + file + ".i\n")
                Process("make " + file+".i", linuxDir) ! logger
                out("\n\n\n\n")

                logWriter.close

            } else {
                println("skipping " + id)
            }


        }

    }

}

