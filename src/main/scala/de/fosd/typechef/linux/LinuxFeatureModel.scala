///*
//  * Created by IntelliJ IDEA.
// * User: kaestner
// * Date: 17.03.11
// * Time: 16:06
// */
//package de.fosd.typechef.linux
//
//import io.Source
//import de.fosd.typechef.featureexpr.{FeatureExpr, FeatureModel}
//
///**
// * three feature models are available
// *
// * featureModel) the normal feature model (from dimacs)
// *
// * featureModelApprox) a small approximated feature model for parsing (contains only few dependencies). not accurate but fast
// *
// * featureModelFull) the normal feature model restricted by the partial configuration (i.e. certain features are already
// *    defined or excluded due to the partial configuration)
// *
// *
// * the approximated feature model is hardcoded in this file. the dimacs feature model and the partial configuration
// * are loaded according to the settings in LinuxSettings
// *
// */
//object LinuxFeatureModel {
//
//
//    lazy val featureModelExcludingDead: FeatureModel = {
//        val fm = featureModel
//        fm and getDeadFeatures(fm) and partialConfiguration
//    }
//
//
//
//
//
//    /**
//     * reads the list of open features (LinuxSettings) and makes every
//     * feature dead that is not in that list
//     */
//    private def getDeadFeatures(fm: FeatureModel): FeatureExpr = {
//        import FeatureExpr._
//        var result: FeatureExpr = base
//        val openFeatures = Source.fromFile(LinuxSettings.openFeatureList).getLines.toList
//        for (feature <- fm.variables.keys if (feature.startsWith("CONFIG_") && !feature.startsWith("CONFIG__X") && !feature.endsWith("_2")))
//            if (!openFeatures.contains(feature))
//                result = result andNot createDefinedExternal(feature)
//        result
//    }
//
//}
