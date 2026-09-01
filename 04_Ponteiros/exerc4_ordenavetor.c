#include <stdio.h>

void ordenaVetor(int v[], int tam);

int main()
{
  int vet[10] = {10, 5, 3, 4, 9, 1, 2, 7, 6, 8};
  ordenaVetor(vet, 10);
  // Escrever na tela o vetor ordenado
  for(int i=0; i<10; i++)
    printf("%d ", vet[i]);
  printf("\n");
}

void ordenaVetor(int v[], int tam)
{
    for(int pos1=0; pos1<tam; pos1++) {
        int* p1 = v;
        int* p2 = p1+1;
        for(int pos2=0; pos2<tam-1-pos1; pos2++) {
            if(*p1 > *p2) {
                int temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
            p1++;
            p2++;
        }
    }
}