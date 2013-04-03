# script to generate feature models for all architectures

thisdir=`pwd`
echo $thisdir
linuxDir=l

cd $linuxDir
for arch in arm x86 alpha  avr32   cris  h8300  Kconfig  m68k   microblaze  mn10300  powerpc  score  sparc    xtensa  blackfin  frv   ia64   m32r     m68knommu  mips        parisc   s390 sh     um
do
  export LINUXVERSION=2.6.33.3
  export ARCH=$arch
  ../linux-variability-analysis-tools/exconfig/bin/exconf-i386 arch/$arch/Kconfig > $thisdir/pcs/$arch.exconfig
  echo `wc -l $thisdir/pcs/$arch.exconfig`
  java -cp ../linux-variability-analysis-tools/fm-translation/target/fm-translation-0.5-SNAPSHOT-jar-with-dependencies.jar gsd.linux.tools.TristateTranslationMain $thisdir/pcs/$arch.exconfig $thisdir/pcs/$arch.bool2
  java -cp ../linux-variability-analysis-tools/fm-translation/target/fm-translation-0.5-SNAPSHOT-jar-with-dependencies.jar gsd.linux.tools.CNFMain $thisdir/pcs/$arch.bool2 $thisdir/pcs/$arch.var2.dimacs
done

cd $thisdir
