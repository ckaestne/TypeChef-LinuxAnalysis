cat pcs/x86.flist |while read i; do echo l/$i; rm l/$i.dbg; rm l/$i.c.xml; rm l/$i.pi; done 
