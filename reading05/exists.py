#!/usr/bin/env python2.7

import sys
import os

for arg in sys.argv[1:]:
    if os.path.isfile(arg):
        print "%s exists!" % arg
    else:
        print "%s does not exist" % arg


