#!/bin/sh
for i in $@
do
   if [ -e "$i" ] 
   then
     echo "$i exists!"
   else
     echo "$i does not exist!"
   fi
done
if [ $# -eq 0 ]; then
    echo "Please enter arguments with the command" 
    exit 1
fi
exit 1