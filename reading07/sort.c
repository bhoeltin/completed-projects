/* sort.c */

#include <stdio.h>
#include <stdlib.h>

/* Constants */

#define MAX_NUMBERS (1<<10)

/* Functions */

size_t read_numbers(FILE *stream, int numbers[], size_t n) {
  size_t i = 0;

  while (i < n && scanf("%d", &numbers[i]) != EOF) {
    i++;
  }

  return i;
}


void sort_numbers(int numbers[], size_t n) {
  int count,temp;
  for (int i = 1; i < n; i++) {
    count = i;
    while (count > 0 && numbers[count] < numbers[count-1]){
	temp = numbers[count];
	numbers[count] = numbers[count-1];
	numbers[count-1] = temp;
	count--;
    }
  }
}

/* Main Execution */

int main(int argc, char *argv[]) {
  int numbers[MAX_NUMBERS];
  size_t nsize;
  
  

  nsize = read_numbers(stdin, numbers, MAX_NUMBERS);
  if (nsize > 0){
    sort_numbers(numbers, nsize);
    
    printf("%d", numbers[0]);
    for (size_t i = 1; i < nsize; i++) {
      printf(" %d", numbers[i]);
    }
  }
  printf("\n");
  return EXIT_SUCCESS;
}
