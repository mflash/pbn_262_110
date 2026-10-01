#include <stdio.h>

int main()
{
    // Abre para escrita (e APAGA o arquivo)
    FILE* arq = fopen("teste.txt", "w");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        perror("Erro");
        return -1;
    }
    for(int i=0; i<100; i++) {
        fprintf(arq, "%d\n", i);
    }
    fclose(arq);
    printf("Arquivo gerado com sucesso!\n");
    return 0;
}