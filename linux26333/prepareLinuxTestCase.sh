#!/bin/sh -v
version=linux-2.6.33.3

tarball=$version.tar.bz2
if [ ! -f $tarball ]; then
    wget http://www.kernel.org/pub/linux/kernel/v2.6/$tarball
    tar xjf $tarball
    ln -s $version linux
fi

# cp compiler-gcc4.h -> compiler-gcc11.h
# fixup issue in include/asm/bug.h

cd linux
make allnoconfig ARCH=x86
make prepare ARCH=x86
# make modules_prepare ARCH=x86
# Creates include/generated/compile.h needed for init/version.o; the command
# will give an error which we want to ignore.
make SUBDIRS=init ARCH=x86 &> /dev/null
cd ..

dir=`pwd`
cd ..
sbt mkrun

cd $dir
sh applyPCs.sh
