package de.fosd.typechef.linux.featuremodel

import de.fosd.typechef.linux.LinuxSettings
import io.Source


/**
 * full feature model, including the partial configuration, used for analysis and preparation
 */
class LinuxFullModel extends LinuxDimacsModel {

    override def createFeatureModel = super.createFeatureModel and partialConfiguration


    private def partialConfiguration = {
        import de.fosd.typechef.featureexpr.FeatureExprFactory._
        val DEF = "#define"
        val UNDEF = "#undef"

        val directives = Source.fromFile(LinuxSettings.partialConfFile).getLines().filter(_.startsWith("#"))

        def findMacroName(directive: String) = directive.split(' ')(1)

        val booleanDefs = directives.filter(directive => directive.startsWith(DEF) && directive.endsWith(" 1")).map(findMacroName)
        val undefs = directives.filter(_.startsWith(UNDEF)).map(findMacroName)

        (booleanDefs.map(createDefinedExternal(_)) ++
            undefs.map(createDefinedExternal(_).not())).
            foldRight(True)(_ and _)
    }
}