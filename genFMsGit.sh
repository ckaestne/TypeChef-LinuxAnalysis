# script to generate feature models for all architectures

thisdir=`pwd`
echo $thisdir
linuxDir=gitlinux

cd $linuxDir
for arch in arm x86 
do
  export LINUXVERSION=2.6.33.3
  export ARCH=$arch
  ../linux-variability-analysis-tools/exconfig/bin/exconf-i386 arch/$arch/Kconfig > $arch.exconfig
  echo `wc -l $arch.exconfig`
  ../linux-variability-analysis-tools/fm-translation/run.sh gsd.linux.tools.TristateTranslationMain $arch.exconfig $arch.bool2
  ../linux-variability-analysis-tools/fm-translation/run.sh gsd.linux.tools.CNFMain $arch.bool2 $arch.var2.dimacs
done

cd $thisdir
