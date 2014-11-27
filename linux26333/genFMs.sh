# script to generate feature models for all architectures

thisdir=`pwd`
echo $thisdir
linuxDir=linux
dumpconf=$thisdir/../../kconfigreader/binary/dumpconf

cd $linuxDir
for arch in x86
do
  export LINUXVERSION=2.6.33.3
  export ARCH=$arch
  sh ../../../kconfigreader/run.sh de.fosd.typechef.kconfig.KConfigReader --writeDimacs --writeNonBoolean --writeCompletedConf --dumpconf $dumpconf arch/$arch/Kconfig $thisdir/pcs/$arch
  wc -l $thisdir/pcs/$arch.model
done

cd $thisdir
