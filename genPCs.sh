# script to generate file presence conditions for all architectures
# also generates file lists of all arch/x files

thisdir=`pwd`
echo $thisdir
kbuildminerDir=../BusyboxAnalysis/KBuildMiner

cd $kbuildminerDir
for arch in x86 arm alpha  avr32   cris  h8300 m68k   microblaze  mn10300  powerpc  score  sparc    xtensa  blackfin  frv   ia64   m32r     m68knommu  mips        parisc   s390 sh     um
do
 mvn scala:run -q -DmainClass=gsd.buildanalysis.linux.KBuildMinerMain "-DaddArgs=--codebase|$thisdir/linux-2.6.33.3|--linuxArch|$arch|--pcOutput|$thisdir/pcs/$arch.pc"
 
 cat $thisdir/pcs/$arch.pc | grep "^arch" | sed 's/\(.*\).[cS]:.*/\1/' > $thisdir/pcs/$arch.flist
done

cd $thisdir
