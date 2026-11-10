#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Função rápida: executa poucas iterações simples (baixo consumo de CPU)
void funcao_rapida(int n) {
  volatile double soma = 0.0;
  for (int i = 0; i < n; i++) {
    soma += i * 0.5;
  }
}

// Função lenta: contém operações matemáticas intensivas e laço aninhado.
// Este será o hotspot (> 95% do tempo de CPU) que o profiler irá apontar!
void funcao_lenta_gargalo(int n) {
  volatile double soma = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2000; j++) {
      soma += sin((double)i) * cos((double)j);
    }
  }
}

// Versão otimizada após diagnóstico com Callgrind (memoização de cos(j))
void funcao_lenta_otimizada(int n) {
  volatile double soma = 0.0;
  double tab_cos[2000];
  for (int j = 0; j < 2000; j++) {
    tab_cos[j] = cos((double)j);
  }
  for (int i = 0; i < n; i++) {
    double s = sin((double)i);
    for (int j = 0; j < 2000; j++) {
      soma += s * tab_cos[j];
    }
  }
}

int main(void) {
  printf("Iniciando processamento para analise de profiling...\n");

  funcao_rapida(100000);
  funcao_lenta_gargalo(20000);

  printf("Processamento concluido com sucesso!\n");
  return 0;
}
