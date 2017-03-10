#!/usr/bin/env python2.7  

import os
import sys

counts = {}
count = 0

for line in os.popen('ps aux'):
    k  = line.split()
    if k in counts:
        counts[line.split()[1]] = nums.get(line.split()[1],0) + 1
    else:
        counts[k] = set()
        counts[line.split()[1]] = nums.get(line.split()[1],0) + 1

print len(counts)


