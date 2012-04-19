package de.fosd.typechef.linux.featuremodel

import de.fosd.typechef.linux.LinuxSettings
import de.fosd.typechef.featureexpr.{FeatureExprFactory, FeatureModelFactory, FeatureModel}


/**
 * small feature model, used during parsing
 */
class LinuxDimacsModel {
    protected def loadDimacsModel: FeatureModel = {
        println("loading feature model...");
        val start = System.currentTimeMillis
        val featureModel = FeatureExprFactory.default.featureModelFactory.createFromDimacsFile_2Var(LinuxSettings.featureModelFile)
        println("done. [" + (System.currentTimeMillis - start) + " ms]")
        featureModel
    }


    def createFeatureModel = loadDimacsModel


}