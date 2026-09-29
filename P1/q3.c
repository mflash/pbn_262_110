#include <stdio.h>

void funcao(int* p) { *p = *p + 5; }

int main() {
  int valores[] = {10, 20, 30, 40, 50};
  int* p = &valores[1];
  int* q = p + 2;
  printf("%d\n", *p);
  printf("%d\n", *(p + 2));
  funcao(q);
  printf("%d %d %d\n", *(valores + 1), *(valores + 2), *(valores + 3));
  p++;
  printf("%d\n", *p);
}