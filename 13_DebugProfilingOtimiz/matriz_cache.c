#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

// Matriz alocada estaticamente (~800 MB na RAM)
static double mat[N][N];

// CASO 1: Percurso por Linhas (Cache-Friendly - RÁPIDO)
double soma_linhas() {
    double total = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total += mat[i][j];
        }
    }
    return total;
}

// CASO 2: Percurso por Colunas (Cache-Unfriendly - LENTO)
double soma_colunas() {
    double total = 0.0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            total += mat[i][j];
        }
    }
    return total;
}

double calcular_tempo(struct timespec inicio, struct timespec fim) {
    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
}

int main() {
    struct timespec inicio, fim;

    printf("Inicializando matriz %dx%d (%.1f MB na RAM)...\n",
           N, N, (N * (double)N * sizeof(double)) / (1024.0 * 1024.0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = 1.0;
        }
    }

    printf("\n1. Executando soma por LINHAS (acesso contiguo)...\n");
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    double r1 = soma_linhas();
    clock_gettime(CLOCK_MONOTONIC, &fim);
    double t_linhas = calcular_tempo(inicio, fim);
    printf("   Resultado: %.0f | Tempo: %.4f s\n", r1, t_linhas);

    printf("\n2. Executando soma por COLUNAS (saltos na memoria)...\n");
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    double r2 = soma_colunas();
    clock_gettime(CLOCK_MONOTONIC, &fim);
    double t_colunas = calcular_tempo(inicio, fim);
    printf("   Resultado: %.0f | Tempo: %.4f s\n", r2, t_colunas);

    printf("\n>>> Comparativo: Percurso por linhas foi %.2fx mais rapido!\n",
           t_colunas / t_linhas);

    return 0;
}

