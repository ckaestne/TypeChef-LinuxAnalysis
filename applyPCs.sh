# script to generate file presence conditions for all architectures


for arch in arm x86 alpha  avr32   cris  h8300  m68k   microblaze  mn10300  powerpc  score  sparc    xtensa  blackfin  frv   ia64   m32r     m68knommu  mips        parisc   s390 sh     um
do
  ./run.sh de.fosd.typechef.linux.ProcessFileList pcs/$arch.pc --workingDir l/ 
done

