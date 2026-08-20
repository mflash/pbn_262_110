#include <stdio.h>

int maior(const int vetor[], int tam);

int main()
{
    int numeros[10] = {5, 7, 80, 12, 30, 9, 4, 1, 10, 3};
    int valMaior = maior(numeros, 10);
    printf("Maior: %d\n", valMaior);
}

int maior(const int vetor[], int tam)
{
    int m = vetor[0];
    for (int i = 1; i < tam; i++)
    {
        if (vetor[i] > m)
        {
            m = vetor[i];
        }
    }
    // vetor[0] = -1; // erro! é const, logo não consegue alterar (ainda bem!)
    return m;
}

