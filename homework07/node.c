/* node.c */

#include "node.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Create node. 
 *
 * This allocates and configures a node that the user must later deallocate.
 * @param   string      String value.
 * @param   next        Reference to next node.
 * @return  Allocated node structure.
 */
struct node *	node_create(char *string, struct node *next) {
  
  struct node *p = malloc(sizeof(struct node));

  if (p != 0){  
    (*p).string = strdup(string);
      (*p).number = atoi(string);
      (*p).next = next;
      return p;
   }

  return NULL;
}

/**
 * Delete node.
 *
 * This deallocates the given node (recursively if specified).
 * @param   n           Node to deallocate.
 * @param   recursive   Whether or not to deallocate recursively.
 * @return  NULL pointer.
 */
struct node *   node_delete(struct node *n, bool recursive) {
  struct node * c = n;
  if (recursive){
    while (n != NULL){
      c = (*n).next;
      free((*n).string);
      free(n);
      n = c; 
    }
  }
  else{
    free((*n).string);
    free(n);
  }
  return NULL;
}

/**
 * Dump node to stream.
 * 
 * This dumps out the node structure (Node{string, number, next}) to the stream.
 * @param   n       Node structure.
 * @param   stream  File stream.
 **/
void            node_dump(struct node *n, FILE *stream) {

  fprintf(stream, "Node{%s, %d, %p}\n", (*n).string , (*n).number, (*n).next);

}

/**
 * Compare node structures by number
 *
 * This compares two node structures by their number values.
 * @param   a       First node structure.
 * @param   b       Second node structure.
 * @return  < 0 if a < b, 0 if a == 0, > 0 if a > b
 */
int		node_compare_number(const void *a, const void *b) {

  struct node **na = (struct node**)a;
  struct node **nb = (struct node**)b;


  int value;

  if (((*na)->number) < ((*nb)->number)){
    value = -1;
    return value;
  }
  else if(((*na)->number) > ((*nb)->number)){
    value = 1;
    return value;     
  }
  else if (((*na)->number) == 0)
    return 0;

  return 0;

}

/**
 * Compare node structures by string
 *
 * This compares two node structures by their string values.
 * @param   a       First node structure.
 * @param   b       Second node structure.
 * @return  < 0 if a < b, 0 if a == 0, > 0 if a > b
 */
int		node_compare_string(const void *a, const void *b) {

  struct node **na = (struct node**)a;
  struct node **nb = (struct node**)b;

  int result = strcmp(((*na)->string), ((*nb)->string));
 
  if (((*na)->string) == 0) return 0;
  
  return result;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
