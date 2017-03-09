#!/usr/bin/env python2.7

import sys
import string

count = 1

accept = string.letters+string.digits+string.whitespace+'-'

for line in sys.stdin:
    for word in (line.lower()).strip().split():
        word = ''.join([x for x in word if x in accept])
        print '{}\t{}'.format(word,count)
    count = count + 1
