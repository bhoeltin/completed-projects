#!/bin/bash                                                                                                                                          


echo "| NITEMS   | ALPHA     | TIME      | SPACE     |"
echo "| -------- | --------- |-----------|-----------|"

for i in 1 10 100 1000 10000 100000 1000000 10000000; do
   for alpha in 0.5 0.75 0.9 1.0 2.0 4.0 8.0 16.0; do
    TIME=$(shuf -i1-"$i" -n "$i" | ./measure ./freq -l "$alpha" > /dev/null | cut -d : -f 1 | grep -Eo '^[0-9]+(\.)?[0-9]{4}')
    SPACE=$(shuf -i1-"$i" -n "$i" | ./measure ./freq -l "$alpha" > /dev/null | cut -d : -f 3 | grep -Eo '^[0-9]+(\.)?[0-9]{4}')
    printf "| %8s | %8f    | %9s | %9s |\n" "$i" "$alpha" "$TIME" "$SPACE"
    done
done

