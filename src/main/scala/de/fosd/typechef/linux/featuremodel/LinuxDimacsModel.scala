package de.fosd.typechef.linux.featuremodel

import de.fosd.typechef.featureexpr.{FeatureExpr, FeatureModelFactory, FeatureModel}
import de.fosd.typechef.linux.LinuxSettings


/**
 * small feature model, used during parsing
 */
class LinuxDimacsModel extends FeatureModelFactory {
    protected def loadDimacsModel: FeatureModel = {
            println("loading feature model...");
            val start = System.currentTimeMillis
            val featureModel = FeatureModel.createFromDimacsFile_2Var(LinuxSettings.featureModelFile)
            println("done. [" + (System.currentTimeMillis - start) + " ms]")
            featureModel
        }


    def createFeatureModel = loadDimacsModel


}