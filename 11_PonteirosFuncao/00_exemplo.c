#include <stdio.h>

void saudacao() { printf("Ola, mundo!\n"); }

int main() {
  printf("Endereco de saudacao:  %p\n", saudacao);
  printf("Com operador &:        %p\n", &saudacao);
  printf("Endereco de main:      %p\n", main);
}