# script to generate file presence conditions for all architectures
# also generates file lists of all arch/x files

thisdir=`pwd`
linuxdir=$thisdir/linux
kbuildminerDir=../../KBuildMiner

cd $kbuildminerDir
for arch in x86 arm alpha  avr32   cris  h8300 m68k   microblaze  mn10300  powerpc  score  sparc    xtensa  blackfin  frv   ia64   m32r     m68knommu  mips        parisc   s390 sh     um
do
 cp $linuxdir/arch/$arch/Makefile $linuxdir/tmpMake
 ./run.sh gsd.buildanalysis.linux.KBuildMinerMain --codebase $linuxdir --topFolders "tmpMake,block,crypto,drivers,firmware,fs,init,ipc,kernel,lib,mm,net,security,sound" --pcOutput $thisdir/pcs/$arch.pcr

 $thisdir/../run.sh de.fosd.typechef.linux.CleanFileList $thisdir/pcs/$arch.pcr --featureModel $thisdir/pcs/$arch.dimacs --openFeatureList $thisdir/pcs/$arch.open > $thisdir/pcs/$arch.pc
 cat $thisdir/pcs/$arch.pc | sed 's/\(.*\):.*/\1/' > $thisdir/pcs/$arch.flist
done

cd $thisdir
