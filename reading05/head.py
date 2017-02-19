#!/usr/bin/env python2.7

import os
import sys

# Global Variables

NUM = 10

# Usage function

def usage(status=0):
    print '''Usage: head.py files...

    -n  NUM      print the first NUM lines instead of the first 10'''.format(os.path.basename(sys.argv[0]))
    sys.exit(status)


# Parse command line options

args = sys.argv[1:]
while len(args) and args[0].startswith('-') and len(args[0]) > 1:
    arg = args.pop(0)
    if arg == '-n':
        NUM = int(args[0])
    elif arg == '-h':
        usage(0)
    else:
        usage(1)

if len(args) == 0:
    args.append('-')

# Main execution

for path in args:
    if path == '-':
        stream = sys.stdin
    elif os.path.isfile(path):
        stream = open(path)
    else: 
        stream = sys.stdin

    for i in range(NUM):
        line = stream.next().strip()
        print line


stream.close()
