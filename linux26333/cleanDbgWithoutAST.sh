cat pcs/x86.flist | while read i; 
    do 
        if [ ! -e "linux/$i.ast" ] 
        then 
          rm linux/$i.dbg
        fi
    done

