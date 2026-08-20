#include <stdio.h>

int main()
{
    int vet[10] = {1, 2, 3, 4, 2, 3, 2, 2, 2, 8};
    int qtdRepetidos = 0;
    int totalRepet;
    for(int pos1=0; pos1 < 10; pos1++)
    {
        totalRepet = 0;
        for(int pos2=pos1+1; pos2 < 10; pos2++)
        {
            if(vet[pos1] == vet[pos2]) {
                totalRepet++;
            }
        }
        if(totalRepet == 1)
            qtdRepetidos++;
    }
    printf("Qtd de valores repetidos: %d\n", qtdRepetidos);
}