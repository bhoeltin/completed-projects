#!/bin/sh

usage() {
    cat 1>&2 <<EOF 
Usage: rank.sh [-n N -D]

    -n N      Returns N items (defaut is 5).
    -D        Rank in descending order.
                                                     
EOF

    exit $1
}


NUMRETURN=5
DESCEND=false

while [ $# -gt 0 ]; do
    case $1 in 
	-n) NUMRETURN=$2 shift ;;
	-D) DESCEND=$true shift ;;
	-h) usage 0;
	*)  usage 1;;
    esac
    shift
done

if [ $DESCEND ] ; then
    read line
  echo "$line" | sort -rn
else 
    echo "$line" | sort -n