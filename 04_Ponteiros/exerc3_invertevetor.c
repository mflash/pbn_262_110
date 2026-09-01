#include <stdio.h>

void inverteVetor(int v[], int tam);
void inverteVetor_pont(int v[], int tam);

int main() {
  int vet[6] = {10, 20, 30, 40, 50, 60};
  //inverteVetor(vet, 6);
  inverteVetor_pont(vet, 6);
  // Escrever na tela o vetor invertido
  for(int i=0; i<6; i++)
    printf("%d ", vet[i]);
  printf("\n");
}

void inverteVetor(int v[], int tam) {
  int pos1 = 0;
  int pos2 = tam-1;
  while(pos1 < pos2) {
    int temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
    pos1++;
    pos2--;
  }
}

void inverteVetor_pont(int v[], int tam) {
  int* p1 = v;
  int* p2 = v+tam-1;
  while(p1 < p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    p1++;
    p2--;
  }
}