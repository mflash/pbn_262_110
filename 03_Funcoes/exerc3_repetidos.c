#include <stdio.h>

int contaRepetidos(int vet[], int tam);

int main()
{
    int dados[10] = {1, 2, 3, 4, 2, 3, 2, 2, 2, 8};
    int qtd = contaRepetidos(dados, 10);
    printf("Qtd de valores repetidos: %d\n", qtd);
}

int contaRepetidos(int vet[], int tam)
{
    int qtdRepetidos = 0;
    int totalRepet;
    for (int pos1 = 0; pos1 < tam; pos1++)
    {
        totalRepet = 0;
        for (int pos2 = pos1 + 1; pos2 < tam; pos2++)
        {
            if (vet[pos1] == vet[pos2])
            {
                totalRepet++;
            }
        }
        if (totalRepet == 1)
            qtdRepetidos++;
    }
    return qtdRepetidos;
}

