SHELL = bash

C=             gcc
CFLAGS=         -g -gdwarf-2 -Wall -std=gnu99
LD=             gcc
LDFLAGS=        -L.
TARGETS=        walk
all:            $(TARGETS)


walk.o: walk.c
	@echo Compiling walk.o ...
	$(CC) $(CFLAGS) -c -o walk.o walk.c

walk:	walk.o	
	@echo Linking walk ...
	$(LD) $(LDFLAGS)  -o walk walk.o

test:  walk
	@echo Testing walk...
	diff <(./walk | sort) <(./walk.py | sort)> walk.log
	@[ `valgrind --leak-check=full ./walk 2>&1 | tee -a walk.log | grep ERROR | awk '{print $$4}'` = 0 ] && ! grep -q 'failed' walk.log || cat walk.log

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) *.a *.o *.log