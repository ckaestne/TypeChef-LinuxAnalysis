echo - | gcc -dM      -x c - -E -nostdinc -isystem /usr/lib/gcc/x86_64-redhat-linux/4.4.4/include -O2 > header64.h
echo - | gcc -m32 -dM -x c - -E -nostdinc -isystem /usr/lib/gcc/x86_64-redhat-linux/4.4.4/include -O2 > header32.h
echo "#ifdef CONFIG_X86_32" > headerboth.h
echo "#include \"header32.h\"" >> headerboth.h
echo "#else" >> headerboth.h
echo "#include \"header64.h\"" >> headerboth.h
echo "#endif" >> headerboth.h
