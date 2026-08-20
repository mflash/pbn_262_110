#include <stdio.h>

int main()
{
    int valor;
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    int n100 = valor / 100;
    int n50  = valor % 100 / 50;
    int n10  = valor % 50 / 10;  // % 100 % 50 / 10;
    int n5   = valor % 10 / 5;   // 100 % 50 % 10 / 5;
    int n1   = valor % 5;        // 100 % 50 % 10 % 5;
    printf("Notas de 100: %d\n", n100);
    printf("Notas de 50 : %d\n", n50);
    printf("Notas de 10 : %d\n", n10);
    printf("Notas de 5  : %d\n", n5);
    printf("Notas de 1  : %d\n", n1); 
}