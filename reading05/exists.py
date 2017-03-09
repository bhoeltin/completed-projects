#!/usr/bin/env python2.7

import sys
import os

STATUS = 0

if len(sys.argv) > 1:
    for arg in sys.argv[1:]:
        if os.path.isfile(arg):
            print "%s exists!" % arg
        else:
            print "%s does not exist" % arg
            STATUS = 1
else:
    print "No arguments"
    sys.exit(1)

sys.exit(STATUS)
