#include <stdio.h>

void copiaVetor(int v1[], int v2[], int tam);

int main() {
  int v1[6] = {10, 20, 30, 40, 50, 60};
  int v2[6];

  copiaVetor(v1, v2, 6);
  for (int i = 0; i < 6; i++) {
    printf("%d ", v2[i]);
  }
  printf("\n");
}

void copiaVetor(int v1[], int v2[], int tam) {
  int* ptr1 = v1;
  int* ptr2 = v2;
  for (int pos = 0; pos < tam; pos++) {
    // *(v2+pos) = *(v1+pos); // v2[pos] = v1[pos];
    *ptr2 = *ptr1;
    ptr1++;
    ptr2++;
  }
}