CC=             gcc
CFLAGS=         -g -gdwarf-2 -Wall -std=gnu99
LD=             gcc
LDFLAGS=        -L.
TARGETS=        ncat 

all:            $(TARGETS)


ncat.o: ncat.c
	@echo Compiling ncat.o...
	$(CC) $(CFLAGS) -c -o ncat.o ncat.c

ncat: ncat.o
	@echo Linking ncat...
	$(LD) $(LDFLAGS) -o ncat ncat.o
