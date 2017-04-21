CC=		gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=		gcc
LDFLAGS=	-L.
AR=		ar
ARFLAGS=	rcs
TARGETS=	lsort \
		test_node \
		test_list \
		liblist.a

all:		$(TARGETS)

# TODO: Add rules for liblist.a, test_node, test_list, lsort, and any intermediate objects

liblist.a: list.o node.o
	$(AR) $(ARFLAGS) liblist.a node.o list.o

lsort.o: lsort.c
	$(CC) $(CFLAGS) -c -o lsort.o lsort.c

lsort: lsort.o liblist.a
	$(LD) $(LDFLAGS) -o lsort lsort.o liblist.a

node.o: node.c
	$(CC) $(CFLAGS) -c -o node.o node.c

list.o: list.c
	$(CC) $(CFLAGS) -c -o list.o list.c

test_node: test_node.o liblist.a
	$(LD) $(LDFLAGS) -o test_node test_node.o liblist.a

test_list: test_list.o liblist.a
	$(LD) $(LDFLAGS) -o test_list test_list.o liblist.a

test_list.o: test_list.c
	$(CC) $(CFLAGS) -c -o test_list.o test_list.c 

test_node.o: test_node.c
	$(CC) $(CFLAGS) -c -o test_node.o test_node.c 

test:		test-node test-list test-lsort

test-node:	test_node
	@echo Testing node...
	@[ `valgrind --leak-check=full ./test_node 2>&1 | tee test_node.log | grep ERROR | awk '{print $$4}'` = 0 ] || cat test_node.log

test-list:	test_list
	@echo Testing list...
	@[ `valgrind --leak-check=full ./test_list 2>&1 | tee test_list.log | grep ERROR | awk '{print $$4}'` = 0 ] || cat test_list.log

test-lsort:	lsort test_lsort.sh
	@echo Testing lsort...
	@./test_lsort.sh

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) test_node test_list *.a *.o *.log *.input

.PHONY:		all test test-node test-list test-lsort clean
