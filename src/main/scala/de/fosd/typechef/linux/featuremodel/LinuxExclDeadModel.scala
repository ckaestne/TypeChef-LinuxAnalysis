package de.fosd.typechef.linux.featuremodel

import de.fosd.typechef.linux.LinuxSettings
import io.Source
import de.fosd.typechef.featureexpr.sat.SATFeatureModel
import de.fosd.typechef.featureexpr.{FeatureExprFactory, FeatureExpr, FeatureModel}


/**
 * Created by IntelliJ IDEA.
 * User: kaestner
 * Date: 03.01.12
 * Time: 14:11
 * To change this template use File | Settings | File Templates.
 */

class LinuxExclDeadModel extends LinuxFullModel {
    override def createFeatureModel = {
        val fm = super.createFeatureModel
        fm and getDeadFeatures(fm)
    }


    /**
     * reads the list of open features (LinuxSettings) and makes every
     * feature dead that is not in that list
     */
    private def getDeadFeatures(fm: FeatureModel): FeatureExpr = {
        import FeatureExprFactory.sat._
        var result: FeatureExpr = True
        val openFeatures = Source.fromFile(LinuxSettings.openFeatureList).getLines.toList
        for (feature <- fm.asInstanceOf[SATFeatureModel].variables.keys if (feature.startsWith("CONFIG_") && !feature.startsWith("CONFIG__X") && !feature.endsWith("_2")))
            if (!openFeatures.contains(feature))
                result = result andNot createDefinedExternal(feature)
        result
    }

}