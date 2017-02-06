#!/bin/sh
#Brianna Hoelting, Homework 2

if [ "$#" -eq 0 ]; then
 echo "Arguments please"
 exit 1
fi

for i in "$@"
do
  case "$i"  in
    *.tgz | *.tar.gz)
       tar -xvzf "$i"
       ;;
    *.tbz | *.tar.bz2) 
       tar -xvjf "$i" 
       ;;
    *.txz | *.tar.xz)
       tar -xvJf "$i"
       ;;
    *.zip | *.jar)
       unzip "$i"
       ;;
  esac
done