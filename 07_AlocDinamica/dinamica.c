#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 500000000 // 500 milhões = 4 GB!

int main()
{
   double* array = malloc(sizeof *array * SIZE);
   printf("tam. mem: %zu\n", sizeof *array * SIZE);
   for(int i=0; i<SIZE; i++)
      array[i] = i;
   sleep(10); // espera 10 segundos...
   free(array); // e libera toda a memória
}
