#!/usr/bin/env python2.7  

import subprocess
import string
import sys

headings = ['NITEMS','SORT','TIME','SPACE']
data = []
fields = [8,1,5,5]
align = [('^','^'),('^','^'),('^','^'),('^','^')]
SPACE = ''
TIME = ''
accept = string.digits+string.whitespace
timeNeeded = 1;
command = ''


for i in range(1, 10000000, 10**i):
    data.append(i)
    data.append(Merge)
    command = 'shuf {} -n {} | ./measure ./lsort -n > /dev/null'.format(i,i)
    result = subprocess.check_ouptut(command,SHELL=True)
    for line in result:
        for word in line.split():
            if(timeNeeded): 
                TIME = ''.join([x for x in word if x in accept])
                timeNeeded= 0;
            else: SPACE = ''.join([x for x in word if x in accept]) 

    data.append(TIME)
    data.append(SPACE)

    timeNeeded = 1;

    data.append(i)
    data.append(Quick)
    command = 'shuf {} -n {} | ./measure ./lsort -n -q > /dev/null'.format(i,i)
    result = subprocess.check_ouptut(command,SHELL=True)
    for line in result:
         for word in line.split():
            if(timeNeeded):
                TIME = ''.join([x for x in word if x in accept])
                timeNeeded= false;
            else: SPACE = ''.join([x for x in word if x in accept])

    data.append(TIME)
    data.append(SPACE)
    timeNeeded = 1;


table(sys.stdout, data, fields, headings, align)
