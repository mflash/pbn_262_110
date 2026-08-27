#include <stdio.h>

int procuraValor(int v[], int tam, int valor);

int main() {
  int vet[] = {10, 20, 30, 40, 50, 60};
  int valor;
  printf("Digite um valor: ");
  scanf("%d", &valor);
  int pos = procuraValor(vet, 6, valor);
  if (pos != -1) {
    printf("Encontrei em %d\n", pos);
  } else {
    printf("Valor não encontrado!\n");
  }
}

int procuraValor(int v[], int tam, int valor) {
  int* ptr = v;
  for (int pos = 0; pos < tam; pos++) {
    if (valor == *ptr) return pos;
    ptr++;
  }
  return -1;
}