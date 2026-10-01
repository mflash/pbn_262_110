#include <stdio.h>
#include <string.h>

int main()
{
    // Abre para leitura
    FILE* arq = fopen("teste.txt", "r");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        perror("Erro");
        return -1;
    }
    char str[80];
    while(!feof(arq)) {
        if(fgets(str, 79, arq) == NULL)
            break;
        int tam = strlen(str);
        str[tam-1] = '\0'; // retira o '\n'
        printf("linha lida: (%d) %s\n", tam, str);
    }
    fclose(arq);
    return 0;
}