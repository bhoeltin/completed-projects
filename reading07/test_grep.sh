#!/bin/bash

FAILURES=0

if [ ! -x ./grep ]; then
    echo "grep is not executable!"
    FAILURES=$((FAILURES + 1))
fi

for path in /etc/hosts /etc/passwd FAKEFILE; do
    if ! diff -u <(/bin/grep 1 $path 2> /dev/null) <(./grep 1 $path 2> /dev/null); then
	echo "grep test failed on $path!"
	FAILURES=$(($FAILURES + 1))
    fi
done

if ! diff -u <(cat /etc/hosts | /bin/grep 1) <(cat /etc/hosts | ./grep 1); then
    echo "grep test failed on implicit stdin!"
    FAILURES=$(($FAILURES + 1))
fi

if ! diff -u <(cat /etc/hosts | /bin/grep 1 -) <(cat /etc/hosts | ./grep 1 -); then
    echo "grep test failed on explicit stdin!"
    FAILURES=$(($FAILURES + 1))
fi

if ./grep 2> /dev/null | /bin/grep -q -i 'Usage'; then
    echo "grep test failed on no arguments"
    FAILURES=$(($FAILURES + 1))
fi

if ! ./grep 1 FAKEFILE 2> /dev/null; then
    echo "grep test failed on FAKEFILE! (exit)"
    FAILURES=$(($FAILURES + 1))
fi

if ! ./grep 1 FAKEFILE 2>&1 | /bin/grep -q "No such file or directory"; then
    echo "grep test failed on FAKEFILE! (error message)"
    FAILURES=$(($FAILURES + 1))
fi

if [ $FAILURES -eq 0 ]; then
    echo "grep test successful!"
    exit 0
else
    echo "grep tests $FAILURES failures"
    exit 1
fi
