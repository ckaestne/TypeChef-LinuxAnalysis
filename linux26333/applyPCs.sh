# script to generate file presence conditions for all architectures


for arch in x86
do
  ../run.sh de.fosd.typechef.linux.GeneratePCFiles pcs/$arch.pc --workingDir linux/ 
done

