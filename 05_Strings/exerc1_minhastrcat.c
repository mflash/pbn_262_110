#include <stdio.h>
#include <string.h>

char* minha_strcat(char* destino, const char* origem);

int main()
{
    char s1[30] = "Minha string "; // reserva espaço
    char s2[] = "legal";

    // int tam = sizeof(s1); // aqui só funciona porque é onde foi
    // DECLARADO o vetor: o compilador entende que desejamos saber
    // o tamanho do vetor na mem, não o ponteiro

    printf("Antes do strcat: %s\n", s1);
    minha_strcat(s1, s2);
    printf("Depois do strcat: %s\n", s1);
}

char* minha_strcat(char* destino, const char* origem)
{
    // int tam_destino = sizeof(destino); // aqui NÃO FUNCIONA: a única informação
    // disponível é que destino é um PONTEIRO para o início do vetor
    char* aux = destino;
    // Vai até o final de destino
    while(*destino != '\0') {
        destino++;
    }

    // Copia de origem até destino, parando no final de origem
    while(*origem != '\0') {
        *destino = *origem;
        origem++;
        destino++;
    }
    return aux;
}
