#include <stdio.h>
#include <stdlib.h>

// Definição do tipo para simplificar a sintaxe
typedef int (*Comparador)(const void*, const void*);

int ascendenteInteiros(const void* a, const void* b) {
  int va = *((int*)a);
  int vb = *((int*)b);
  return va - vb;
}

int ascendenteLong(const void* a, const void* b) {
  long va = *((long*)a);
  long vb = *((long*)b);
  return va - vb;
}

int descendenteInteiros(const void* a, const void* b) {
  int va = *((int*)a);
  int vb = *((int*)b);
  return vb - va;
}

void imprimir(int* vetor, int tamanho) {
  for (int i = 0; i < tamanho; i++) printf("%d ", vetor[i]);
  printf("\n");
}

int main() {
  int dados[] = {5, 2, 9, 1, 56};
  long dados2[] = {51212322, 281277, 921727, 112717, 56127712};
  // Lembre-se que isto só funciona na função onde o vetor
  // é DECLARADO!
  int n = sizeof(dados) / sizeof(dados[0]);

  qsort(dados, n, sizeof(int), ascendenteInteiros);
  imprimir(dados, n);

  qsort(dados, n, sizeof(int), descendenteInteiros);
  imprimir(dados, n);

  qsort(dados2, n, sizeof(long), ascendenteLong);
  for (int i = 0; i < n; i++) printf("%d ", dados2[i]);
  printf("\n");

  return 0;
}
