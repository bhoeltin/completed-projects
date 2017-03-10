#!/usr/bin/env python2.7                                                        

import sys
import os
import re

words = set()

for line in os.popen('cat /etc/passwd', 'r'):
   word = line.split(':')[4]
   if re.search(r'[uU]ser', word):
       words.add(word.lower())

for item in sorted(words):
    print item
