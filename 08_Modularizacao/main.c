#include <stdio.h>

#include "bibfunc.h"

int main() {
  int v;
  printf("Digite o valor: ");
  scanf("%d", &v);
  printf("Fatorial: %ld\n", fatorial(v));
  printf("Somatório: %ld\n", somatorio(v));
}