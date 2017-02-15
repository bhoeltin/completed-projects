#!/bin/sh

# gender.sh

URL=https://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/csv/demographics.csv

count_gender() {
    column=$(( 2 * $1 % 2013 + 1 )) # TODO: Determine appropriate column from first argument
    gender=$2 # TODO:	Gender is second argument
    # TODO extract gender data for specified year and group

    curl -s https://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/csv/demographics.csv | cut -d ',' -f$column | grep -Eo "$gender" | wc -l 
}

for year in $(seq 2013 2019); do
    echo $year $(count_gender $year F) $(count_gender $year M)
done
