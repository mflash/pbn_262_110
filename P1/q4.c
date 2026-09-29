#include <stdio.h>

void analisa_vet(int* v, int qtd, int* menor, int* maior, int* soma_impares) {
  int* p = v;
  *menor = 100;  // 1. era *menor = 0
  *maior = 0;
  *soma_impares = 0;     // 12. variável soma_impares sem inicialização!
  while (p < v + qtd) {  // 2. era <=
    if (*p % 2 == 0) {   // 3. era != (testando ímpar)
      if (*p < *menor) *menor = *p;  // 4. era *menor = p;
      if (*p > *maior) *maior = *p;  // 5 e 6. era if(p > maior)
    } else {
      *soma_impares = *soma_impares + *p;  // 7. era + p
    }
    // p = p++;  // NÃO PODE FAZER ISSO! Comportamento indefinido
    p = p + 1;  // 8. era p + sizeof(int)
  }
}

int main() {
  int valores[] = {18, 7, 25, 4, 31, 12};
  int menor, maior, soma;
  // 9, 10 e 11. era analisa_vetor(&valores, 7, menor, ...)
  analisa_vet(valores, 6, &menor, &maior, &soma);
  printf("Menor par: %d\n", menor);
  printf("Maior par: %d\n", maior);
  printf("Soma impares: %d\n", soma);
}