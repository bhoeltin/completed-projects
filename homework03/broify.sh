#! /bin/bash

if [ "$1" == "-h" ]; then
    cat <<EOF
Usage: broify.sh

  -d DELIM    Use this as the comment delimiter.
  -W          Don't strip empty lines.

EOF
    exit 1
fi


WSET="false"
DELIM="#"

while [ "$#" -gt "0" ]
do
    if [ "$1" == "-d" ]; then
	shift 
	DELIM="$1"
    fi
    if [ "$1" == "-W" ]; then
	WSET="true"
    fi
    shift
done

if [ $WSET == "true" ]; then
    sed -r "s|${DELIM}.*$||" | sed "s|\s*$||"
else
    sed -r "s|${DELIM}.*$||" | sed "s|\s*$||" | grep "[^[:blank:]]" 
fi