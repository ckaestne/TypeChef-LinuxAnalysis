cat pcs/x86.flist |while read i; do echo linux/$i; rm linux/$i.dbg; rm linux/$i.c.xml; rm linux/$i.pi; done 
