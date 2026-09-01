#include <stdio.h>

void exibeMemoria(char* mem, int tam);

int main() {
  long v[] = {0, 1, 2, 3, 4};
  int matriz[4][4] = {
      {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};

  exibeMemoria((char*)v, 5 * sizeof(long));
  printf("\n");
  exibeMemoria((char*)matriz, 4 * 4 * sizeof(int));
}

void exibeMemoria(char* mem, int tam) {
  for (int i = 0; i < tam; i++) {
    if (i % 16 == 0) printf("%p: ", mem);
    printf("%02X ", *mem);
    mem++;
  }
  printf("\n");
}