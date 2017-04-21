/* map.c: separate chaining hash table */

#include "map.h"

/**
 * Create map data structure.
 * @param   capacity        Number of buckets in the hash table.
 * @param   load_factor     Maximum load factor before resizing.
 * @return  Allocated Map structure.
 */
Map *	        map_create(size_t capacity, double load_factor) {
  
  Map * p = calloc(1, sizeof(Map));

  if (capacity <= 0) p->capacity = DEFAULT_CAPACITY;
  else p->capacity = capacity;

  if (load_factor == 0) p->load_factor = DEFAULT_LOAD_FACTOR;
  else p->load_factor = load_factor;

  p->size = 0;
  
  Entry * buckets = calloc(p->capacity, sizeof(struct Entry));
  p->buckets = buckets;

    return p;
}

/**
 * Delete map data structure.
 * @param   m               Map data structure.
 * @return  NULL.
 */
Map *	        map_delete(Map *m) {
  
  if (m){
    for (int i= 0; i < m->capacity; i++){
      Entry * ptr = m->buckets[i].next;
      entry_delete(ptr, true);
    }
    free(m->buckets);
    free(m);
  }  
  return NULL;
}

/**
 * Insert or update entry into map data structure.
 * @param   m               Map data structure.
 * @param   key             Entry's key.
 * @param   value           Entry's value.
 * @param   type            Entry's value's type.
 */
void            map_insert(Map *m, const char *key, const Value value, Type type) {

  Entry * ptr;
  double maxSize = (double) m->size / m->capacity; 

  if (maxSize > m->load_factor){
    map_resize(m, 2*(m->capacity));
  }
  size_t bucket = fnv_hash(key, strlen(key)) % m->capacity;
  ptr = map_search(m, key);
  if (ptr == NULL){
    Entry * temp = &m->buckets[bucket];
    while (temp->next){
      temp = temp->next;
    }
    struct Entry * newNode = entry_create(key, value, NULL, type);
    temp->next= newNode;
    (m->size)++;
  }
  else{
    entry_update(ptr,value,type);
  }
	 

  
}

/**
 * Search map data structure by key.
 * @param   m               Map data structure.
 * @param   key             Key of the entry to search for.
 * @param   Pointer to the entry with the specified key (or NULL if not found).
 */
Entry *         map_search(Map *m, const char *key) {
  
  size_t bucket = fnv_hash(key, strlen(key)) % m->capacity;
  struct Entry * ent;
  ent = m->buckets[bucket].next;
  while (ent){
    if (strcmp(ent->key,key) == 0){
      return ent;
    }
    ent = ent->next;
  }
    return NULL;
}

/**
 * Remove entry from map data structure with specified key.
 * @param   m               Map data structure.
 * @param   key             Key of the entry to remove.
 * return   Whether or not the removal was successful.
 */
bool            map_remove(Map *m, const char *key) {
  size_t bucket = fnv_hash(key, strlen(key)) % m->capacity;
  Entry * ptr;
  Entry * temp;
  ptr = m->buckets[bucket].next;
  if(!ptr) return false;
  temp = ptr;
  while (ptr != NULL){
    if (strcmp(ptr->key, key) == 0){
      if(ptr == m->buckets[bucket].next)
	m->buckets[bucket].next = ptr->next; 
      else temp->next = ptr->next;
    m->size--;
    entry_delete(ptr,false);
    return true;
    }
    temp = ptr;
    ptr = ptr->next;
  }
   return false;
}

/**
 * Dump all the entries in the map data structure.
 * @param   m               Map data structure.
 * @param   stream          File stream to write to.
 * @param   mode            Dump mode to use.
 */
void		map_dump(Map *m, FILE *stream, const DumpMode mode) {

  Entry * ptr;
  Entry * temp;
  for (int i = 0; i < m->capacity; i++){
    temp = m->buckets[i].next;
    if (!temp){
      continue;
    }

    while (temp){
      entry_dump(temp, stream, mode);
      temp = temp->next;
    }
  }
}

/**
 * Resize the map data structure.
 * @param   m               Map data structure.
 * @param   new_capacity    New capacity for the map data structure.
 */
void            map_resize(Map *m, size_t new_capacity) {

  Entry * new = calloc(new_capacity, sizeof(Entry));
  Entry * old = m->buckets;
  size_t oldCap = m->capacity;
  size_t bucket;
 
  for (int i = 0; i < oldCap; i++){
    Entry * ptr = old[i].next;
    while (ptr!=NULL){
 
     Entry * temp = ptr->next;
      bucket = fnv_hash(ptr->key, strlen(ptr->key)) % new_capacity;
      Entry * temp2 = new[bucket].next;
      new[bucket].next = ptr;
      ptr->next = temp2;
      ptr = temp;
   }
  }
  free(old);
  m->buckets = new;
  m->capacity = new_capacity;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
