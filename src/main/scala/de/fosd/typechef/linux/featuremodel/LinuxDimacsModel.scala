package de.fosd.typechef.linux.featuremodel

import de.fosd.typechef.linux.LinuxSettings
import de.fosd.typechef.featureexpr.{FeatureExprFactory, FeatureModelFactory, FeatureModel}


/**
 */
class LinuxDimacsModel {
    protected def loadDimacsModel(fm: String): FeatureModel = {
        println("loading feature model...");
        val start = System.currentTimeMillis
        val featureModel = FeatureExprFactory.default.featureModelFactory.createFromDimacsFile(fm)
        println("done. [" + (System.currentTimeMillis - start) + " ms]")
        featureModel
    }


    def createFeatureModel = loadDimacsModel(LinuxSettings.featureModelFile)

    def createFeatureModel2 = loadDimacsModel(LinuxSettings.featureModelFile2)
    
    def createFeatureModelArm = loadDimacsModel("pcs/arm.dimacs")


}
