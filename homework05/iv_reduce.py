#!/usr/bin/env python2.7

import sys

counts = {}
value = ''
for line in sys.stdin:
    k, v  = line.split('\t', 1)
    if k in counts:
        counts[k].add(int(v))
    else:
        counts[k] = set()
        counts[k].add(int(v))
for k, v in sorted(counts.items()):
    v = [str(i) for i in sorted(v)]
    value = ' '.join(v)
    print '{}\t{}'.format(k, value)
