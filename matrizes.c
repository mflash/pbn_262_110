#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    printf("m1 (alocação linha a linha)\n");
    int** m1 = malloc(n * sizeof(int*));
    for(int i=0; i<n; i++)
        m1[i] = malloc(n * sizeof(int));

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            m1[i][j] = i+j;

    for(int i=0; i<n; i++)
        printf("%d: %p\n", i, m1[i]);

    printf("\nm2 (alocação direta)\n");
    int (*m2)[n] = malloc(n * sizeof *m2);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            m2[i][j] = i+j;

    for(int i=0; i<n; i++)
        printf("%d: %p\n", i, m2[i]);
    
    // Libera todas as linhas
    for(int i=0; i<n; i++)
        free(m1[i]);
    // Libera a matriz
    free(m1);
}