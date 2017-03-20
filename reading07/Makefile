CC=             gcc
CFLAGS=         -g -gdwarf-2 -Wall -std=gnu99
TARGETS=        sort grep

all: $(TARGETS)

# TODO: Add rules for sort and grep

test: test_sort.sh test_grep.sh
	./test_sort.sh
	./test_grep.sh

test_sort.sh:
	curl -O http://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/sh/test_sort.sh
	chmod +x $@

test_grep.sh:
	curl -O http://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/sh/test_grep.sh
	chmod +x $@

sort.exe: sort.c
	$(CC) $(CFLAGS) sort sort.c

grep.exe: grep.c
	$(CC) $(CFLAGS) grep grep.c


clean:
	rm -f $(TARGETS)