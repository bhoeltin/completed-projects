/* translate.c: string translator */

#include "stringutils.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */
int mode;
char * SOURCE = "";
char * TARGET = "";
char *PROGRAM_NAME = NULL;
enum {
  STRIP = 1<<1,
  REVERSE = 1<<2,
  REVERSEWORDS = 1<<3,
  LOWER = 1<<4,
  UPPER = 1<<5
};


/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s SOURCE TARGET\n\n", PROGRAM_NAME);
    fprintf(stderr, "Post Translation filters:\n\n");
    fprintf(stderr, "   -s     Strip whitespace\n");
    fprintf(stderr, "   -r     Reverse line\n");
    fprintf(stderr, "   -w     Reverse words in line\n");
    fprintf(stderr, "   -l     Convert to lowercase\n");
    fprintf(stderr, "   -u     Convert to uppercase\n");
    exit(status);
}

void translate_stream(FILE *stream, char *source, char *target, int mode) {
  char buffer[BUFSIZ];
  char * my_string = "";
  while(fgets(buffer,BUFSIZ, stream)){
    my_string = buffer;
    my_string = string_chomp(my_string);

    if (strlen(source) !=0 && strlen(target) !=0) {
      my_string = string_translate(my_string, source, target);
    }

    /* Check a Mode */
    if (mode & STRIP) {
      my_string = string_strip(my_string);
    }
    if (mode & REVERSE) {
      my_string = string_reverse(my_string);
    }
    if (mode & REVERSEWORDS) {
      my_string = string_reverse_words(my_string);
    }
    if (mode & LOWER) {
      my_string = string_lowercase(my_string);
    }
    if (mode & UPPER) {
      my_string = string_uppercase(my_string);
    }
  }
  printf ("%s\n", my_string);

}

/* Main Execution */

int main(int argc, char *argv[]) {
    /* Parse command line arguments */
  int argind = 1;
  while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
    char *arg = argv[argind++];
    switch (arg[1]) {
    case 'h':
      usage(0);
      break;
    case 's':
      mode |= STRIP;
      break;
    case 'r':
      mode |= REVERSE;
      break;  
    case 'w':
      mode |= REVERSEWORDS;
      break;
    case 'l':
      mode |= LOWER;
      break;
    case 'u':
      mode |= UPPER;
      break;
    default:
      usage(1);
      break;
    }
  }

    if (argind < argc) {
      SOURCE = argv[argind++];
    }
    if (argind < argc) {
      TARGET = argv[argind++];
    }
    /* Translate Stream */
    translate_stream(stdin, SOURCE, TARGET, mode);
  
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
