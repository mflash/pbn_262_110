#include <stdio.h>

int main()
{
    int totalSegundos;
    printf("Digite um total em segundos desde a meia-noite: ");
    scanf("%d", &totalSegundos);
    int horas = totalSegundos / 3600;
    int minutos  = totalSegundos % 3600 / 60;
    int segundos  = totalSegundos % 3600 % 60;
    printf("Horas: %d\n", horas);
    printf("Minutos: %d\n", minutos);
    printf("Segundos: %d\n", segundos);
    // %02d -> ocupa sempre 2 espaços, preenche com 0 à esquerda
    printf("%02d:%02d:%02d\n", horas, minutos, segundos);
}