cat pcs/x86.flist |while read i; do echo l/$i; rm linux/$i.dbg; rm linux/$i.c.xml; rm linux/$i.pi; done 
