package de.fosd.typechef.linux

import java.io.File
import de.fosd.typechef.featureexpr.{FeatureExpr, FeatureExprParser, FeatureModel, FeatureExprFactory}
import de.fosd.typechef.typesystem.linker._
import de.fosd.typechef.parser._
import de.fosd.typechef.error.Position


object LinuxLinker extends com.github.paulp.optional.Application {
    val fexprParser = new FeatureExprParser(FeatureExprFactory.bdd)


    def main(fileList: File, featureModelDimacs: File, prefix: Option[String], dirOnly: Option[String]) {
        FeatureExprFactory.setDefault(FeatureExprFactory.bdd)


        assert(featureModelDimacs.exists(), "feature model file does not exist")
        assert(fileList.exists(), "file list file does not exist")

        val vm = FeatureExprFactory.default.featureModelFactory.createFromDimacsFile(featureModelDimacs.getAbsolutePath) //.and(fexprParser.parseFile(new File("approx.fm")))
        val files = io.Source.fromFile(fileList).getLines().toList

        val filesByDirectory = files.groupBy(f => f.take(f.lastIndexOf("/")))

        var finalInterface: CInterface = EmptyInterface

        for ((dir, filesInDir) <- filesByDirectory.iterator.toList.reverse
             if dir.startsWith(prefix.getOrElse(""))
             if dirOnly.map(_ == dir).getOrElse(true)
             if !(excludeDirs contains dir)) {

            val dirInterface = processDir(dir, filesInDir, vm)

            print(".")
            finalInterface = linkTreewise(List(finalInterface, dirInterface), vm)
            println("." + finalInterface.exports.size)
        }

        println("writing final interface")
        val reader = new InterfaceWriter() {}
        reader.writeInterface(finalInterface, new File("final.interface"))
        reader.debugInterface(finalInterface, new File("final.dbginterface"))

    }

    class SimpleFilePosition(filename: String) extends Position {
        def getFile: String = filename

        def getLine: Int = 0

        def getColumn: Int = 0
    }

    def replacePosition(signatures: Seq[CSignature], filename: String): Seq[CSignature] =
        signatures.map(sig => CSignature(sig.name, sig.ctype, sig.fexpr, Seq(new SimpleFilePosition(filename))))

    def simplifyInterface(interface: CInterface, filename: String): CInterface =
        CInterface(interface.featureModel, interface.importedFeatures, interface.declaredFeatures, replacePosition(interface.imports, filename), replacePosition(interface.exports, filename).filter(_.name != "foodfafe"))

    def printIncompatibility(problem: (String, FeatureExpr, Seq[CSignature])) {
        println(" * " + problem._1 + " when " + problem._2)
        println(problem._3.map("\t" + _.toString()).mkString("\n"))
    }

    val excludeDirs = Set[String](
        "drivers/net", "drivers/usb/gadget"
    )


    def linkTreewise(l: Seq[CInterface], vm: FeatureModel): CInterface = {
        if (l.size > 2) {
            val m: Int = l.size / 2
            val left = l.take(m)
            val right = l.drop(m)
            linkTreewise(List(linkTreewise(left, vm), linkTreewise(right, vm)), vm)
        }
        else if (l.size == 2) {
            val left = l(0)
            val right = l(1)

            //            print(".")
            //            val conflicts = (left getConflicts right).filter(_._2.not.isSatisfiable(vm))
            //            if (!conflicts.isEmpty)
            //                println(conflicts)

            val confl = left getConflicts right
            for (c <- confl)
                if (!c._2.isTautology(vm))
                    printIncompatibility(c)
            if (!(left isCompatibleTo right))
                println(confl)
            left link right
        } else if (l.size == 1) l(0)
        else {
            EmptyInterface
        };

    }


    def linkIncrementally(l: List[CInterface]): CInterface = l.fold(EmptyInterface)((left, right) => {
        if (!(left isCompatibleTo right))
            println(left getConflicts right)
        left link right
    })


    def processDir(dir: String, filesInDir: List[String], vm: FeatureModel): CInterface = {
        println("\n** processing " + dir + " **")
        println("parsing " + filesInDir.size + " files")

        val reader = new InterfaceWriter() {}

        val interfaceExtension = ".interface"
        var interfaces = filesInDir.map(path + _).filter(f => new File(f + interfaceExtension).exists).map(f => loadInterface(reader, f, interfaceExtension)) //.map(SystemLinker.linkStdLib(_))

        println("composing")

        var finalInterface: CInterface = EmptyInterface

        val t1 = System.currentTimeMillis()




        finalInterface = linkTreewise(interfaces, vm)

        val t2 = System.currentTimeMillis()

        println("total composition time: " + (t2 - t1))

        reader.writeInterface(finalInterface, new File(path + dir + "/_dir.interface"))
        reader.debugInterface(finalInterface, new File(path + dir + "/_dir.dbginterface"))
        finalInterface
    }

    def loadInterface(reader: InterfaceWriter, f: String, interfaceExtension: String): CInterface = {
        var i = simplifyInterface(reader.readInterface(new File(f + interfaceExtension)), f)
        //not necessary, since PC is already part of all constraints, and there are no local feature models in files
        //        val pcFile = new File(f + ".pc")
        //        if (pcFile.exists())
        //            i = i.conditional(fexprParser.parseFile(pcFile))
        i
    }


    val path = "l/"

}


object LinuxDirLinker extends com.github.paulp.optional.Application {
    val fexprParser = new FeatureExprParser(FeatureExprFactory.bdd)


    def main(fileList: File, featureModelDimacs: File) {
        FeatureExprFactory.setDefault(FeatureExprFactory.bdd)

        assert(featureModelDimacs.exists(), "feature model file does not exist")
        assert(fileList.exists(), "file list file does not exist")

        val vm = FeatureExprFactory.default.featureModelFactory.createFromDimacsFile(featureModelDimacs.getAbsolutePath).and(fexprParser.parseFile(new File("approx.fm")))

        val files = io.Source.fromFile(fileList).getLines().toList

        val directories = files.map(f => f.take(f.lastIndexOf("/"))).toSet


        val reader = new InterfaceWriter() {}
        println("loading...")

        val interfaces =
            for (dir <- directories.take(50)
                 if !(LinuxLinker.excludeDirs contains dir))
            yield reader.readInterface(new File(LinuxLinker.path + dir + "/_dir.interface"))

        println("linking...")
        val finalInterface = LinuxLinker.linkTreewise(interfaces.toSeq, vm)

        println("writing...")
        reader.writeInterface(finalInterface, new File("final.interface"))
        reader.debugInterface(finalInterface, new File("final.dbginterface"))

    }


}