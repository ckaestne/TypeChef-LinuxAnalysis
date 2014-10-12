# script to generate file presence conditions for all architectures


for arch in x86
do
  ./run.sh de.fosd.typechef.linux.ProcessFileList pcs/$arch.pc --openFeatureList pcs/$arch.open --workingDir linux/ 
done

