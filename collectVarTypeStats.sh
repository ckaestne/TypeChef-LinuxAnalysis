cat sample | while read i; do grep vartypestats l/$i.dbg; done > vartypestats.csv
