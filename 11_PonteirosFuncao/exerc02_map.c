#include <stdio.h>

typedef int (*Transformacao)(int);

int dobro(int x);
int quadrado(int x);
int inverteSinal(int x);
void exibe(int v[], int tam);
void mapear(const int* entrada, int tamanho, int* saida, Transformacao op);

int dobro(int x) {}
int quadrado(int x) {}
int inverteSinal(int x) {}

void mapear(const int* entrada, int tamanho, int* saida, Transformacao op) {
  // Passar pelos elementos do vetor de entrada,
  // usando op (função de transformação) e armazenar
  // o resultado no vetor de saída
}

void exibe(int v[], int tam) {
  for (int i = 0; i < tam; i++) printf("%d ", v[i]);
  printf("\n");
}

int main() {
  int v1[] = {1, 3, 5, 7, 9, 11};
  int v2[] = {0, 0, 0, 0, 0, 0};

  exibe(v1, 6);
  mapear(v1, 6, v2, dobro);
  exibe(v2, 6);
  mapear(v1, 6, v2, quadrado);
  exibe(v2, 6);
  mapear(v1, 6, v2, inverteSinal);
  exibe(v2, 6);
}