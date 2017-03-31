#!/bin/bash     


linewidth=47

echo "| NITEMS   | SORT     | TIME      | SPACE     |"
echo "| -------- | -------- |-----------|-----------|"

for i in 1 10 100 1000 10000 100000 1000000 10000000; do
   TIME=$(shuf -i1-"$i" -n "$i" | ./measure ./lsort -n 2>&1 > /dev/null | cut -d : -f 1 | grep -Eo '^[0-9]+(\.)?[0-9]{4}')
   SPACE=$(shuf -i1-"$i" -n "$i" | ./measure ./lsort -n 2>&1 > /dev/null | cut -d : -f 3 | grep -Eo '^[0-9]+(\.)?[0-9]{4}')
   

  printf "| %8s | Merge    | %9s | %9s |\n" "$i" "$TIME" "$SPACE"

    TIME=$(shuf -i1-"$i" -n "$i" | ./measure ./lsort -n -q 2>&1 > /dev/null | cut -d : -f 1 | grep -Eo '^[0-9]+(\.)?[0-9]{4}')
    SPACE=$(shuf -i1-"$i" -n "$i" | ./measure ./lsort -n -q 2>&1 > /dev/null | cut -d : -f 3 | grep -Eo '^[0-9]+(\.)?[0-9]{4}')

    printf "| %8s | Quick    | %9s | %9s |\n" "$i" "$TIME" "$SPACE"

done