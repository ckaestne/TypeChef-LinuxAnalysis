# script to generate feature models for all architectures

thisdir=`pwd`
echo $thisdir
linuxDir=l
dumpconf=$thisdir/../kconfigreader/binary/dumpconf

cd $linuxDir
for arch in x86 arm alpha  avr32   cris  h8300  m68k   microblaze  mn10300  powerpc  score  sparc    xtensa  blackfin  frv   ia64   m32r     m68knommu  mips        parisc   s390 sh   
do
  export LINUXVERSION=2.6.33.3
  export ARCH=$arch
  echo ../../kconfigreader/run.sh de.fosd.typechef.kconfig.KConfigReader --writeDimacs --writeNonBoolean --writeCompletedConf --dumpconf $dumpconf arch/$arch/Kconfig $thisdir/pcs/$arch
  ../../kconfigreader/run.sh de.fosd.typechef.kconfig.KConfigReader --writeDimacs --writeNonBoolean --writeCompletedConf --dumpconf $dumpconf arch/$arch/Kconfig $thisdir/pcs/$arch
  wc -l $thisdir/pcs/$arch.model
done

cd $thisdir
