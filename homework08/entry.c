/* entry.c: map entry */

#include "map.h"

/**
 * Create entry structure.
 * @param   key             Entry's key.
 * @param   value           Entry's value.
 * @param   next            Reference to next entry.
 * @param   type            Entry's value's type.
 * @return  Allocate Entry structure.
 */
Entry *		entry_create(const char *key, const Value value, Entry *next, Type type) {

  struct Entry  *p = calloc(1,sizeof(struct Entry));

  if (p != 0){
    (*p).key = strdup(key);
    (*p).type = type;
    entry_update(p, value, type);
    (*p).next = next;
    (*p).type = type;
    return p;
  }

  return NULL;

}

/**
 * Delete entry structure.
 * @param   e               Entry structure.
 * @param   recursive       Whether or not to delete remainder of entries.
 * return   NULL.
 */
Entry *		entry_delete(Entry *e, bool recursive) {
  struct Entry * c = e;
  if (recursive){
    while (e != NULL){
      c = (*e).next;
      if ((*e).type == STRING) free(((*e).value).string);
      free((*e).key);
      free(e);
      e = c;
    }
  }
  else{
    if ((*e).type == STRING) free(((*e).value).string);
    free((*e).key);
    free(e);
  }
  return NULL;
}

/**
 * Update entry's value.
 * @param   e               Entry structure.
 * @param   value           New value for entry.
 * @param   type            New value's type.
 */
void            entry_update(Entry *e, const Value value, Type type) {

  if (type == STRING){
    if ((*e).type == STRING) free(((*e).value).string);
    (*e).type = STRING;
    ((*e).value).string = strdup(value.string);
  }
  else{ 
    if ((*e).type == STRING) free(((*e).value).string);
    (*e).type = NUMBER;  
    ((*e).value).number = value.number;
  }
}

/**
 * Dump entry.
 * @param   e               Entry structure.
 * @param   stream          File stream to write to.
 * @param   mode            Dump mode to use.
 */
void            entry_dump(Entry *e, FILE *stream, const DumpMode mode) {

  switch (mode){
  case KEY:
    fprintf(stream, "%s\n", (*e).key);
    break;
  case KEY_VALUE:
    if ((*e).type == STRING)
      fprintf(stream, "%s\t%s\n", (*e).key, ((*e).value).string);
    else fprintf(stream, "%s\t%ld\n", (*e).key,((*e).value).number);
    break;
  case VALUE:
    if ((*e).type ==STRING)
      fprintf(stream, "%s\n", ((*e).value).string);
    else fprintf(stream, "%ld\n", ((*e).value).number);
    break;
  case VALUE_KEY: 
    if ((*e).type ==STRING)
      fprintf(stream, "%s\t%s\n", ((*e).value).string, (*e).key);
    else fprintf(stream, "%ld\t%s\n", ((*e).value).number, (*e).key);
    break;
  default:
    break;
  }
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
