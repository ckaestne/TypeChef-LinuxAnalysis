#!/bin/bash
#!/bin/bash -vxe

#java -jar sbt-launch-0.7.4.jar  compile

##################################################################
# Location of the Linux kernel.
##################################################################
#srcPath=linux-2.6.33.3
# XXX:$PWD/ makes the path absolute, it is needed for some stupid bug!
srcPath=$PWD/linux

##################################################################
# List of files to preprocess
##################################################################
filesToProcess() {
  local listFile=pcs/x86.flist
  cat $listFile
  #awk -F: '$1 ~ /.c$/ {print gensub(/\.c$/, "", "", $1)}' < linux_2.6.33.3_pcs.txt
}

system=linux-redhat
typechefFlags="--bdd -x CONFIG_ --xtc \
  --featureModelFExpr approx.fm \
  --typeSystemFeatureModelDimacs=pcs/x86.dimacs \
  --include=pcs/x86.completed.h --include=pcs/x86.nonbool.h --include=partialConf.h \
  -c ../$system.properties \
  --openFeat pcs/x86.open \
  --writePI --recordTiming --lexdebug --errorXML --interface \
  --adjustLines --printIncludes \
  --serializeAST"

if [ ! -f pcs/kbuildparam.sh ]; then
  echo "file pcs/kbuildparam.sh not found. run genKbuild.sh first"
  exit
fi
source pcs/kbuildparam.sh

##################################################################
# Collect the required additional parameter. Then
# Actually invoke the preprocessor and analyze result.
##################################################################
filesToProcess|while read i; do
  if [ ! -f $srcPath/$i.dbg ]; then
    extraFlags="-I $srcPath/include -I $srcPath/arch/x86/include -I $srcPath/arch/x86/include/generated -I $srcPath/arch/x86/include/uapi -I $srcPath/arch/x86/include/generated/uapi -I $srcPath/include/uapi -D __KERNEL__ -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DKBUILD_BASENAME=\"\\\"$base\\\"\" -DKBUILD_MODNAME=\"\\\"$base\\\"\" --include=header/kconfig.h --include=header/bounds.h --include=header/asm-offsets.h $(kbuildflags "$i")"
#    echo $extraFlags
    touch $srcPath/$i.dbg
    . ./jcpp.sh $srcPath/$i.c $extraFlags
    if [ "$1" =  "--one" ]
    then
        exit
    fi
  else
    echo "Skipping $srcPath/$i.c"
  fi
done


# vim: set tw=0:
