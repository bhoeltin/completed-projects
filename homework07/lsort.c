/* lsort.c */

#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char * PROGRAM_NAME = NULL;
bool qsortVal=false;
bool numericVal=false;


/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s\n", PROGRAM_NAME);
    fprintf(stderr, "  -n   Numerical sort\n");
    fprintf(stderr, "  -q   Quick sort\n");
    exit(status);
}

void lsort(FILE *stream, bool numeric, bool quicksort) {

  struct list * linkedlist = list_create();
  char buffer[BUFSIZ];

  while(fgets(buffer,BUFSIZ, stream)){ 
    list_push_back(linkedlist, buffer);
    }

  
  if (quicksort){
    if (numeric){
      list_qsort(linkedlist, node_compare_number);
    }
    else{
      list_qsort(linkedlist, node_compare_string);
    }
  }
  else{
    if (numeric){
      list_msort(linkedlist, node_compare_number);
    }
    else{
      list_msort(linkedlist, node_compare_string);
    }
  }

  struct node * iter = linkedlist->head;

  for (int i = 0; i < (*linkedlist).size; i++){
    printf("%d\n",iter->number);
    iter = iter->next;
  }
  list_delete(linkedlist);

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
    case 'n':
      numericVal = true;
      break;
    case 'q':
      qsortVal = true;
      break;
    default:
      usage(1);
      break;
    }
  }

    lsort(stdin, numericVal, qsortVal);
    /* Sort using list */

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
