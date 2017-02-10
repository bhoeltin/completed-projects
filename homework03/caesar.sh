#!/bin/bash

if [ "$1" == "-h" ]; then
    cat <<EOF
Usage: caesar.sh [rotation]

This program will read from stdin and rotate (shift right) the text by
the specified rotation.  If none is specified, then the default value is
13.
EOF
    exit 1
fi

if [ "$#" -eq 0 ]; then
    MYVAR=13
elif [ "$#" -eq 1 ]; then
    MYVAR="$1"
else
    echo "Too many arguments"
    exit 1
fi


if [ "$MYVAR" -gt 26 ]; then
    MYVAR=$(($MYVAR%26))
fi

SET1=$(echo "abcdefghijklmnopqrstuvwxyz" | cut -c 1-$MYVAR)
SETA=$(echo "ABCDEFGHIJKLMNOPQRSTUVWXYZ" | cut -c 1-$MYVAR)
SET2=$(echo "abcdefghijklmnopqrstuvwxyz" | cut -c $(($MYVAR+1))-26)
SETB=$(echo "ABCDEFGHIJKLMNOPQRSTUVWXYZ" | cut -c $(($MYVAR+1))-26)
CIPHER=$SETB$SETA$SET2$SET1

tr "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" "$CIPHER"