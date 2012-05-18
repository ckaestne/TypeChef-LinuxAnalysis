package de.fosd.typechef.linux

import java.io.File

/**
 * adhoc reader for KConfig to create a partial configuration with default entries for nonboolean values
 *
 * input: KConfig file
 *
 */

object KConfigReader extends com.github.paulp.optional.Application {
    def main(out: Option[File], arg1: File) {


        var config = io.Source.fromFile(arg1).getLines().toList

        var outFeatureModel = ""
        var outHeader = "";


        var flag = ""
        var skipHelp = false
        var flagType = ""
        var flagDep = ""
        var groupDep = ""
        var inChoiceHeader = false
        var menuStack = List[String]()

        var features = List[String]()
        var choiceAlternatives: List[String] = Nil
        var defaultVar = ""

        def processConfig() {
            if (flag == "") return;
            if ((flagType == "int" || flagType=="hex"|| flagType == "string") && defaultVar != "") {
//                println(flag + " => " + defaultVar + " if " + flagDep)
                if (flagType == "int") defaultVar = defaultVar.replaceAll("\"", "")
                if (flagType == "hex") defaultVar ="0x"+ defaultVar.replaceAll("\"", "")
                //
                //
                //                outHeader += "#ifdef CONFIG_" + flag + "\n" +
                //                    "   #define ENABLE_" + flag + " 1\n" +
                //                    "   #define IF_" + flag + "(...) __VA_ARGS__\n" +
                //                    "   #define IF_NOT_" + flag + "(...)\n" +
                //                    "#else\n" +
                //                    "   #define ENABLE_" + flag + " 0\n" +
                //                    "   #define IF_NOT_" + flag + "(...) __VA_ARGS__\n" +
                //                    "   #define IF_" + flag + "(...)\n" +
                //                    "#endif\n\n"
                //
                if (!flagDep.trim.isEmpty)
                    outFeatureModel += "#if " + flagDep.replaceAll("=y","").replaceAll("\\w+", "defined(CONFIG_$0)") + "\n  "
                outFeatureModel += "#define CONFIG_" + flag + " " + defaultVar + "\n"
                if (!flagDep.trim.isEmpty)
                    outFeatureModel += "#endif\n"
                //                if (!groupDep.trim.isEmpty)
                //                    outFeatureModel += "defined(CONFIG_" + flag + ") => " + groupDep.replaceAll("\\w+", "defined(CONFIG_$0)") + "\n"

                features = flag :: features
            }
            choiceAlternatives = flag :: choiceAlternatives
            flag = ""
            skipHelp = false
            flagType = ""
            flagDep = ""
            defaultVar = ""
        }

        def processChoice() {
            if (choiceAlternatives.isEmpty) return;
            outFeatureModel += choiceAlternatives.map("defined(CONFIG_" + _ + ")").mkString("oneOf(", ",", ")\n")
        }

        var dir = ""

        while (!config.isEmpty) {
            val line = config.head
            config = config.tail

            var skip = false
            if (line.trim == "" || line.trim.startsWith("#") || line.trim.startsWith("comment") || line.trim.startsWith("mainmenu")) skip = true

            if (!skip && line.startsWith("config")) {
                inChoiceHeader = false
                processConfig()

                flag = line.drop(7).trim
            }
            if (!skip && line.startsWith("menu")) {
                //            println("<menu " + line.drop(5) + ">")
                menuStack = line.drop(5) :: menuStack
            }
            if (!skip && line.startsWith("endmenu")) {
                //            println("</menu " + menuStack(0) + ">")
                menuStack = menuStack.tail
            }

            if (!skip && line.startsWith("source")) {
                //                processConfig()
                //                var file = arg1.getParent + line.drop(7)
                //                dir = line.drop(7).take(line.drop(7).lastIndexOf("/"))
                //                config =
                //                    io.Source.fromFile(file).getLines().toList ++ config
            }

            if (!skip && line.trim() == ("choice")) {
                processConfig
                choiceAlternatives = Nil
                inChoiceHeader = true
            }

            if (!skip && line.trim() == ("endchoice")) {
                processConfig
                processChoice
                groupDep = ""
                inChoiceHeader = false
            }

            if (!skip && !skipHelp && flag != "" && line.trim() == ("help"))
                skipHelp = true

            if (!skip && !skipHelp && flag != "" && line.trim().startsWith("bool"))
                flagType = "bool"
            if (!skip && !skipHelp && flag != "" && line.trim().startsWith("int"))
                flagType = "int"
            if (!skip && !skipHelp && flag != "" && line.trim().startsWith("hex"))
                flagType = "hex"
            if (!skip && !skipHelp && flag != "" && line.trim().startsWith("string"))
                flagType = "string"

            if (!skip && !skipHelp && flag != "" && line.trim().startsWith("default")) {
                var v = line.trim.drop(7)
                defaultVar = v.trim
            }


            if (!skip && !skipHelp && line.trim().startsWith("depends on")) {
                var v = line.trim.drop(11)
                //remove trailing comments
                if (v.indexOf('#') >= 0)
                    v = v.take(v.indexOf('#'))
                if (flag != "") {
                    if (flagDep != "") flagDep = "(" + flagDep + ") && (" + v + ")"
                    else flagDep = v
                }
                if (inChoiceHeader)
                    groupDep = v
            }


        }

        processConfig()



        println(outFeatureModel)
    }

}

