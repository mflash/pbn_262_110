#include "bibfunc.h"

long fatorial(int n) {
  long fat = 1;
  for (int i = 1; i <= n; i++) {
    fat = fat * i;
  }
  return fat;
}

long somatorio(int n) {
  long soma = 0;
  for (int i = 1; i <= n; i++) {
    soma = soma + i;
  }
  return soma;
}
