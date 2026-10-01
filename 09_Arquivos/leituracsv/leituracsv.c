#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cod[6];
    int creditos;
    char nome[80];
    int turma;
} Turma;

int main()
{
    Turma lista[100];
    FILE* arq = fopen("turmas.csv", "r");

    if (!arq) {
        printf("Impossivel abrir o arquivo!n");
        return -1;
    }

    char buf[1024];
    int linhas = 0;
    int campos = 0;

    while (fgets(buf, 1024, arq)) {
        campos = 0;

        if (linhas == 0) { // pula a primeira linha
            linhas++;
            continue;
        }

        // strtok retorna um ponteiro para o primeiro campo
        // ate o separador indicado (";")
        char *campo = strtok(buf, ";");

        strcpy(lista[linhas-1].cod, campo);

        // Enquanto nao retornar NULL, e' porque existem mais campos
        while (campo) {
            printf("%02d: %s\n", campos,campo);
            // Pega o proximo campo, passando NULL como primeiro parametro
            campo = strtok(NULL, ";");
            campos++;
            switch(campos) {
                case 1: // total de créditos
                        lista[linhas-1].creditos = atoi(campo);
                        break;
                case 2: // nome disciplina
                        strcpy(lista[linhas-1].nome, campo);
                        break;
                case 4: // número da turma
                        lista[linhas-1].turma = atoi(campo);
            }
        }
        printf("\n");
        linhas++;
    }

    fclose(arq);

    for(int i=0; i<linhas-1; i++) { 
        printf("%s-%02d - %s (%d)\n", lista[i].cod, lista[i].creditos,
            lista[i].nome, lista[i].turma);
    }
    return 0;
}
