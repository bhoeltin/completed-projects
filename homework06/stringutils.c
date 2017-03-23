/* stringutils.c: String Utilities */

#include "stringutils.h"

#include <ctype.h>
#include <string.h>
#include <math.h>

/**
 * Convert all characters in string to lowercase.
 * @param   s       String to convert
 * @return          Pointer to beginning of modified string
 **/
char *	string_lowercase(char *s) {
  char *c = s;
  while(*c){ 
      *c = tolower(*c);
      c++;
  }
  return s;
}

/**
 * Convert all characters in string to uppercase.
 * @param   s       String to convert
 * @return          Pointer to beginning of modified string
 **/
char *	string_uppercase(char *s) {
  char *c = s;
  while(*c){
    *c = toupper(*c);
    c++;
  }
  return s;
}

/**
 * Returns whether or not the 's' string starts with given 't' string.
 * @param   s       String to search within
 * @param   t       String to check for
 * @return          Whether or not 's' starts with 't'
 **/
bool	string_startswith(char *s, char *t) {
  while (*t){
    if (*s != *t) return false;
    s++;
    t++;
  }
  return true;
}

/**
 * Returns whether or not the 's' string ends with given 't' string.
 * @param   s       String to search within
 * @param   t       String to check for
 * @return          Whether or not 's' ends with 't'
 **/
bool	string_endswith(char *s, char *t) {
  s += strlen(s);
  s -= strlen(t);
  while (*t){
    if (*s != *t) return false;
    s++;
    t++;
  }  
  return true;
}

/**
 * Removes trailing newline (if present).
 * @param   s       String to modify
 * @return          Pointer to beginning of modified string
 **/
char *	string_chomp(char *s) { 
  char *beginning = s;
  s += strlen(s)-1;

  if (*s == '\n'){
    *s = '\0';
  }
  s = beginning;
  return s;
}

/**
 * Removes whitespace from front and back of string (if present).
 * @param   s       String to modify
 * @return          Pointer to beginning of modified string
 **/
char *	string_strip(char *s) {
  char * p;
  p = s + strlen(s)-1;

  while((p >= s) && (*p == ' '))
      p--;
  p++;
  *p = '\0';
  
  while (*s && (*s == ' '))
      s++;
    
  return s;
}

/**
 * Reverses a string given the provided from and to pointers.
 * @param   from    Beginning of string
 * @param   to      End of string
 * @return          Pointer to beginning of modified string
 **/
static char *	string_reverse_range(char *from, char *to) {
  char temp;
  int count = 0;
  while (from < to){
    temp = *from;
    *from = *to;
    *to = temp;
    from++;
    count++;
    to--;
  }
  from -= count;
  return from;
}

/**
 * Reverses a string.
 * @param   s       String to reverse
 * @return          Pointer to beginning of modified string
 **/
char *	string_reverse(char *s) {
  char* beginning = s;
  char* end = s + strlen(s)-1;
 
  if (strlen(s) >= 2){
    s = string_reverse_range(beginning,end);
   }
  return s;
}

/**
 * Reverses all words in a string.
 * @param   s       String with words to reverse
 * @return          Pointer to beginning of modified string
 **/
char *	string_reverse_words(char *s) {
  char *beginning = s;
  char * end = s;
  if (strlen(s) < 2) return s;
  while (*beginning == ' ') beginning++;
  end = beginning;
  while (*end){  
    
    if (*(end + 1) == ' ' || *(end + 1) == '\0'){
      beginning = string_reverse_range(beginning,end);
      beginning = end + 2;
    }
    end++;
  }
  s  = string_reverse_range(s,end-1);
  return s;
}

/**
 * Replaces all instances of 'from' in 's' with corresponding values in 'to'.
 * @param   s       String to translate
 * @param   from    String with letter to replace
 * @param   to      String with corresponding replacment values
 * @return          Pointer to beginning of modified string
 **/
char *	string_translate(char *s, char *from, char *to) {
 typedef  struct {char o; char n;} lib;
  int count =0;
   if (to !=NULL  &&  from!=NULL){
    int len = strlen(to);
    char * beginning = s;
    lib table[len];
    while(*to){
      table[count].n = *to;
      table[count].o = *from;
      count++;
      to++;
      from++;
    }
    while(*s){
      for(int i = 0; i < len; i++){
	if (table[i].o == *s){
	  *s = table[i].n;
	}
      }
     s++;
    }
    s = beginning;
  }
  return s;
}

/**
 * Converts given string into an integer.
 * @param   s       String to convert
 * @param   base    Integer base
 * @return          Converted integer value
 **/
int	string_to_integer(char *s, int base) {
  int count = strlen(s)-1;
  int total=0;
  typedef  struct {char o; int n;} hex;
  int power = 1;
  for (int i = 0; i < count; i++)
    power *= base;

  hex c1[16] = {
    {'0',0},{'1',1}, {'2',2},{'3',3},{'4',4}, {'5',5},{'6',6},{'7',7},{'8',8},
    {'9',9}, {'A',10}, {'B',11}, {'C',12}, {'D',13},{'E',14}, {'F',15}};


  while(*s){
    if(*s < 123 && *s >96) *s = toupper(*s);
      for (int i = 0; i < base; i++){
	if (*s == c1[i].o){
	  total = total+ (c1[i].n)*power;
	  power /= base;
	}
      }
      s++;
  }
  return total;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
