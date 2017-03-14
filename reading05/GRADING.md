Comments:

- use os.path.exists instead of os.path.isfile. os.path.exists will work for directories, os.path.isfile only works for regular files. -0.25

- head.py does not parse n flag properly. args[0] needs to be popped. Ex. `NUM int(args.pop(0))` -0.25 

- head.py gives error if file is shorter than NUM. -0.25

Score: 3.25/4
