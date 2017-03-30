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
numbers = [1,10,100,1000,10000,100000,1000000,10000000]

for int in numbers:
    command = 'shuf {} -n {} | ./measure ./lsort -n > /dev/null'.format(int,int)
    result = subprocess.Popen(command,stdout=subprocess.PIPE, shell=True)
    (output, err) = result.communicate()
    result_status = result.wait();
    for line in output:
        for word in line.split():
            if(timeNeeded): 
                TIME = ''.join([x for x in word if x in accept])
                timeNeeded= 0;
            else: SPACE = ''.join([x for x in word if x in accept]) 

    data.append(TIME)
    data.append(SPACE)

    timeNeeded = 1;

    command = 'gshuf {} -n {} | ./measure ./lsort -n -q > /dev/null'.format(int,int)
    result = subprocess.Popen(command, stdout=subprocess.PIPE, shell=True)
    (output, err) = result.communicate()
    result_status = result.wait();
    for line in output:
         for word in line.split():
            if(timeNeeded):
                TIME = ''.join([x for x in word if x in accept])
                timeNeeded= false;
            else: SPACE = ''.join([x for x in word if x in accept])

    data.append(TIME)
    data.append(SPACE)
    timeNeeded = 1;


s = """ | NITEMS   | SORT     | TIME      | SPACE     |
        | -------- | -------- |-----------|-----------|
        | 1        | Merge    | {}        | {}        |
        | 1        | Quick    | {}        | {}        |
        | 10       | Merge    | {}        | {}        |
        | 10       | Quick    | {}        | {}        |
        | 100      | Merge    | {}        | {}        |                                     
        | 100      | Quick    | {}        | {}        |
        | 1000     | Merge    | {}        | {}        |                                     
        | 1000     | Quick    | {}        | {}        |
        | 10000    | Merge    | {}        | {}        |                                     
        | 10000    | Quick    | {}        | {}        |
        | 100000   | Merge    | {}        | {}        |                                     
        | 100000   | Quick    | {}        | {}        |
        | 1000000  | Merge    | {}        | {}        |                      
        | 1000000  | Quick    | {}        | {}        |
        | 10000000 | Merge    | {}        | {}        |                                     
        | 10000000 | Quick    | {}        | {}        |""".format(data.pop(0), data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0), data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0), data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0), data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0),data.pop(0))
