cat linux_files.lst | while read i; 
    do 
        if [ ! -e "l/$i.ast" ] 
        then 
          rm l/$i.dbg
        fi
    done

