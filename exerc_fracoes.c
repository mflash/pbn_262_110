#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Fracao;

void multiplica(Fracao* a, Fracao* b, Fracao* result);
void adiciona(Fracao* a, Fracao* b, Fracao* result);
void exibeFracao(Fracao* frac);

int main()
{
    Fracao f1 = { 1, 2 };
    Fracao f2 = { 3, 4 };

    Fracao resMultiplicacao;
    Fracao resAdicao;

    printf("Fracao 1: ");
    exibeFracao(&f1);
    printf("Fracao 2: ");
    exibeFracao(&f2);

    multiplica(&f1, &f2, &resMultiplicacao);
    adiciona(&f1, &f2, &resAdicao);

    printf("Multiplicação: ");
    exibeFracao(&resMultiplicacao);
    printf("Adição: ");
    exibeFracao(&resAdicao);
}

void exibeFracao(Fracao* frac) {
    printf("%d / %d\n", frac->numerador, frac->denominador);
}

void multiplica(Fracao* a, Fracao* b, Fracao* result) {
    result->numerador = a->numerador * b->numerador;
    result->denominador = a->denominador * b->denominador;
}

void adiciona(Fracao* a, Fracao* b, Fracao* result) {
    result->denominador = a->denominador * b->denominador;
    result->numerador = result->denominador / a->denominador * a->numerador +
                        result->denominador / b->denominador * b->numerador;
}