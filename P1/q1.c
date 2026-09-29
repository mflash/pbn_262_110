#include <stdio.h>

void remove_caracter(char* str, char c);

void remove_caracter(char* str, char c) {
  while (*str != '\0') {
    if (*str == c) {
      char* aux = str;
      while (*aux != '\0') {
        *aux = *(aux + 1);
        aux++;
      }
    } else
      str++;
  }
}

int main() {
  char s[] = "baaaaaaaanana";
  printf("String original  : %s\n", s);
  remove_caracter(s, 'a');
  printf("String resultante: %s\n", s);
}