#!/usr/bin/env python2.7

import sys

def evens(stream):
    for y in stream:
       y = int(y.strip())
       if y % 2 == 0:
          yield str(y)

print ' '.join(evens(sys.stdin))
