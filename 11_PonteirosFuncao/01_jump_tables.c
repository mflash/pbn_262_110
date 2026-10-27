#include <stdio.h>

void abrir() { printf("Abrindo arquivo...\n"); }
void salvar() { printf("Salvando arquivo...\n"); }
void fechar() { printf("Fechando arquivo...\n"); }

typedef void (*Operacao)();

int main() {
  // Vetor de ponteiros de função que não recebem argumentos e retornam void
  Operacao menu[] = {abrir, salvar, fechar};
  // void (*menu[])() = {abrir, salvar, fechar};

  printf("Abrir: %p\n", abrir);
  printf("Salvar: %p\n", salvar);
  printf("Fechar: %p\n", fechar);

  int opcao;
  printf("Digite 0 para Abrir, 1 para Salvar, 2 para Fechar: ");
  if (scanf("%d", &opcao) == 1 && opcao >= 0 && opcao <= 2) {
    // if(opcao == 0)
    // abrir();
    // else if(opcao==1)
    // salvar();
    menu[opcao]();  // Chamada direta via índice
  }

  return 0;
}
