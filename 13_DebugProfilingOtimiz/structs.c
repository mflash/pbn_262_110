#include <stdio.h>

// Estrutura mal declarada: consome 24 bytes!
struct DadosIneficiente {
    char tipo;      // 1 byte  + 7 bytes de padding invisível!
    double valor;   // 8 bytes (alinhado a 8)
    int contador;   // 4 bytes + 4 bytes de padding no final!
};

// Estrutura reorganizada (maior -> menor): consome apenas 16 bytes (33% menor!)
struct DadosEficiente {
    double valor;   // 8 bytes (alinhado a 8)
    int contador;   // 4 bytes (alinhado a 4)
    char tipo;      // 1 byte  + 3 bytes de padding no final
};

int main()
{
    printf("tamanho DadosIneficiente: %zu\n", sizeof(struct DadosIneficiente));
    printf("tamanho DadosEficiente  : %zu\n", sizeof(struct DadosEficiente));
}
