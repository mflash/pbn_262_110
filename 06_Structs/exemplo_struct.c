#include <stdio.h>

typedef struct
{
    float p1;
    float p2;
    char conceito;
    int faltas;
} Aluno;

void exibeAluno(Aluno a);
void exibeAlunoPtr(const Aluno *a);
void exibeTurma(Aluno *turma[], int tam);

int main()
{
    Aluno a1, a2;
    Aluno turma[10];   // 10 structs Aluno COM LIXO!
    Aluno *turma2[10]; // 10 ponteiros para Aluno

    turma[0] = a1; // cópia de dado NÃO INICIALIZADO!
    turma[1] = a2;

    turma2[0] = &a1;
    turma2[1] = &a2;

    int tamA1 = sizeof(a1);         // 16 pois o compilador "alinha" os dados em múltiplos de 4!
    int tamTurma = sizeof(turma);   // 160 bytes, pois 16 bytes por posição (conteúdo de uma struct Aluno)
    int tamTurma2 = sizeof(turma2); // 80 bytes, pois 8 bytes por posição (ponteiro, end. de memória 64 bits)

    a1.p1 = 8;
    a1.p2 = 7.5;
    a1.faltas = 0;

    a2.p1 = 8.5;
    a2.p2 = 6.5;
    a2.faltas = 4;

    Aluno a3 = a1; // copia todo o conteúdo de a1 para a3
    a3.p1 = 10;
    a3.faltas = 2;
    turma2[2] = &a3;

    printf("Aluno 1:\n");
    exibeAlunoPtr(&a1);

    printf("Aluno 2:\n");
    exibeAluno(a2);

    printf("Aluno 3:\n");
    exibeAluno(a3);

    printf("\n");
    printf("Turma com 3 alunos:\n");
    exibeTurma(turma2, 3);
}

void exibeAluno(Aluno a)
{
    printf("Prova 1: %f\n", a.p1);
    printf("Prova 2: %f\n", a.p2);
    printf("Faltas: %d\n", a.faltas);
}

void exibeAlunoPtr(const Aluno *a)
{
    printf("Prova 1: %f\n", a->p1);
    printf("Prova 2: %f\n", a->p2);
    printf("Faltas: %d\n", a->faltas);
    // a->p1 = 0; // não pode, salvo pelo const!
}

void exibeTurma(Aluno *turma[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Aluno %d:\n", i);
        exibeAlunoPtr(turma[i]);
    }
}
