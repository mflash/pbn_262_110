#include <stdio.h>

void escreveTexto(char v[], int tam);
void escreveTexto2(char v[], int tam);
void exibeVet(int* v, int tam);
void exibe(const int* v);

void exibeVet(int* v, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void exibe(const int* v) {
  //   *v = 20;
  printf("Valor: %d\n", *v);
}

void escreveTexto(char v[], int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%c", v[i]);
  }
  printf("\n");
}

void escreveTexto2(char v[], int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%c", *v);
    v++;
  }
  printf("\n");
}

int main() {
  int b = 200;
  // Lembre-se SEMPRE de inicializar ponteiros!
  int* a = &b;
  printf("End. b : %p\n", &b);
  printf("Valor a: %p\n", a);
  exibe(&b);
  exibe(a);
  printf("Valor de *a: %d\n", *a);
  *a = 1000;
  printf("Valor de *a: %d\n", *a);
  printf("Valor de b : %d\n", b);

  // Vetores e ponteiros
  int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  exibeVet(vet, 10);

  char c[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  char* p = c;  // aponta para a primeira pos. do vetor c

  printf("c: %p\n", c);
  printf("p: %p\n", p);
  printf("c[0]: %c\n", c[0]);
  printf("*p  : %c\n", *p);
  printf("p[0]: %c\n", p[0]);
  printf("p[1]: %c\n", p[1]);
  printf("*(p+1): %c\n", *(p + 1));
  printf("c[1]: %c\n", c[1]);
  printf("*(c+1): %c\n", *(c + 1));
  printf("*c+1: %c\n", *c + 1);

  // Aritmética de ponteiros usa o TAMANHO
  // do dado armazenado
  long m[] = {3, 2, 1, 4, 5, 6, 9, 8, 7, 10};
  printf("m[0]   : %d %p\n", m[0], &m[0]);
  printf("*m     : %d %p\n", *m, m);
  printf("m[1]   : %d %p\n", m[1], &m[1]);
  printf("*(m+1) : %d %p\n", *(m + 1), m + 1);

  // Duas formas de acessar o conteúdo de um
  // vetor:
  printf("\n");
  escreveTexto(c, 10);
  escreveTexto2(c, 10);
}
