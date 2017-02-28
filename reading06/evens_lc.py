#!/usr/bin/env python2.7

import sys
print ' '.join(y.strip() for y in sys.stdin if int(y.strip()) %2 == 0)
