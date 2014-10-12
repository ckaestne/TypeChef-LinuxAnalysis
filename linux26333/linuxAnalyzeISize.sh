echo "file;sizePI;sizeI;linesPI;linesI">isize.csv
cat pcs/x86.flist | while read i; do 
	echo "$i";
	echo  "linux/$i;"\
		`cat "linux/$i.pi"|wc -c`";"\
		`cat "linux/$i.i"|wc -c`";"\
		`cat "linux/$i.pi" | grep -v ^$ | grep "^#" -v|wc -l`";"\
		`cat "linux/$i.i" | grep -v ^$ | grep "^#" -v|wc -l`>>isize.csv; 
done

