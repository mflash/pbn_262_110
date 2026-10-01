#include <stdio.h>

int main()
{
    // Abre para leitura
    FILE* arq = fopen("teste.txt", "r");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        perror("Erro");
        return -1;
    }
    while(!feof(arq)) {
        int valor;
        fscanf(arq, "%d\n", &valor);
        printf("valor lido: %d\n", valor);
    }
    fclose(arq);
    return 0;
}