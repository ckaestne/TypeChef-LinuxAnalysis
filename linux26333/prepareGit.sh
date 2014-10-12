#!/bin/sh -v
version=gitlinux

cd $version
make allnoconfig ARCH=x86
make prepare ARCH=x86
# Creates include/generated/compile.h needed for init/version.o; the command
# will give an error which we want to ignore.
make SUBDIRS=init ARCH=x86 &> /dev/null

cd ..

cd KBuildMiner
mvn scala:run -q -DmainClass=gsd.buildanalysis.linux.KBuildMinerMain
cd ..

cat gitlinux/pc.txt | grep "\.S:\ " -v | sed s/\\.c:.*//  > gitlinux/filelist

sbt compile 
./run.sh de.fosd.typechef.linux.ProcessFileList gitlinux/pc.txt --workingDir gitlinux/


