/* freq.c */

#include "map.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char * PROGRAM_NAME = NULL;
double LOAD_FACTOR = 0.0;
DumpMode MODE = VALUE_KEY;

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s\n", PROGRAM_NAME);
    fprintf(stderr, "    -f FORMAT        Output format (KEY, KEY_VALUE, VALUE, VALUE_KEY)\n");
    fprintf(stderr, "    -l LOAD_FACTOR   Load factor for hash table\n");
    exit(status);
}

void freq_stream(FILE *stream, double load_factor, DumpMode mode) {

  Map * m = map_create(0,load_factor);
  char buffer[BUFSIZ];
  
  while(fgets(buffer,BUFSIZ, stream)){
    char * str1 = strtok(buffer," \t\n");
    while ( str1!=NULL){
      Entry * ptr = map_search(m,str1);
      if(ptr == NULL)
	map_insert(m, str1, (Value)(int64_t)1, (Type) NUMBER);
      else
	map_insert(m, str1, (Value)(ptr->value.number +1), (Type)NUMBER);   
      str1 = strtok(NULL," \t\n");
    }
  }
  
  map_dump(m,stdout,mode);
  map_delete(m);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    /* Parse command line arguments */

  int argind = 1;
  PROGRAM_NAME = argv[0];
  while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
    char *arg = argv[argind++];
    switch (arg[1]){
    case 'h':
	 usage(0);
	 break;
       case 'f':
	 if(strcmp(argv[argind], "KEY") == 0) MODE = (DumpMode) KEY;
	 else if(strcmp(argv[argind], "KEY_VALUE") == 0) MODE = (DumpMode) KEY_VALUE;
	 else if(strcmp(argv[argind], "VALUE") == 0) MODE = (DumpMode) VALUE;
	 break;
       case 'l':
	 LOAD_FACTOR = strtod(argv[argind], NULL);
	 break;
       default:
	 usage(1);
	 //	 break;
    }
  }

    freq_stream(stdin, LOAD_FACTOR, MODE);

    /* Compute frequencies of data from stdin */
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
