cpwd=`pwd`
cd linux
$cpwd/../../kconfigreader/run.sh de.fosd.typechef.kconfig.KConfigurationGenerator $cpwd/formula $cpwd/pcs/x86.rsf scripts/kconfig/conf arch/x86/Kconfig .config
cd ..
