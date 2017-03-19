#!/bin/bash

FAILURES=0

if [ ! -x ./sort ]; then
    echo "sort is not executable!"
    FAILURES=$((FAILURES + 1))
fi

if ! diff -u <(echo "" | ./sort) <(echo ""); then
    echo "sort test failed on empty input"
    FAILURES=$(($FAILURES + 1))
fi

if ! diff -u <(echo 5 4 7 0 1| ./sort) <(echo 0 1 4 5 7); then
    echo "sort test failed on 5 4 7 0 1!"
    FAILURES=$(($FAILURES + 1))
fi

if ! diff -u <(echo 3 13 3 15 3 25| ./sort) <(echo 3 3 3 13 15 25); then
    echo "sort test failed on 3 13 3 15 3 25!"
    FAILURES=$(($FAILURES + 1))
fi

if [ $FAILURES -eq 0 ]; then
    echo "sort test successful!"
    exit 0
else
    echo "sort tests $FAILURES failures"
    exit 1
fi
