#!/bin/bash                                                                                                                                          


echo "| NITEMS   | ALPHA     | TIME      | SPACE     |"
echo "| -------- | --------- |-----------|-----------|"

for i in 1 10 100 1000 10000 100000 1000000 10000000; do
   for alpha in 0.5 0.75 0.9 1.0 2.0 4.0 8.0 16.0; do
    OUTPUT=$(shuf -i1-"$i" -n "$i" | ./measure ./freq -l "$alpha" 2>&1> /dev/null)
    TIME=$(echo "$OUTPUT"| grep -Eo '^[0-9\.]{5}') 
    SPACE=$(echo "$OUTPUT" | sed -nr 's|.*\t([0-9\.]{7}).*|\1|p')
    printf "| %8s | %4s    | %9s | %9s |\n" "$i" "$alpha" "$TIME" "$SPACE"
    done
done

