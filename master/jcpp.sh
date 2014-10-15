#!/bin/bash -e
#!/bin/bash -vxe


#javaOpts='-Xdebug -Xrunjdwp:transport=dt_socket,server=y,suspend=n,address=1044'
javaOpts=''
javaOpts='$javaOpts -Xmx2G -Xms128m -Xss10m'

# For Java compiled stuff!
basePath=.

#mainClass="org.anarres.cpp.Main"
mainClass="de.fosd.typechef.Frontend"

# Brute argument parsing
# The right thing to do would be to be a gcc replacement, parse its flags and
# select the ones we care about.
if [ $# -lt 1 ]; then
  echo "Not enough arguments!" >&2
  exit 1
fi
inp=$1
shift

if [ -z "$inp" ]; then
  echo "inp not defined!" >&2
  exit 1
fi


outBase="$(dirname $inp)/$(basename $inp .c)"
outDbg="$outBase.dbg"
outErr="$outBase.err"
outTime="$outBase.time"




# Beware: the embedded for loop requotes the passed argument. That's dark magic,
# don't ever try to touch it. It simplifies your life as a user of this program
# though!
echo "==Partially preprocessing $inp"
echo $partialPreprocFlags

bash -c "time ../../TypeChef/typechef.sh \
  $(for arg in $partialPreprocFlags "$@"; do echo -n "\"$arg\" "; done) \
  '$inp' 2> '$outErr' |tee '$outDbg'" \
  2> "$outTime" || true

cat "$outErr" 1>&2
