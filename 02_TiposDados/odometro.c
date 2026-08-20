#include <stdio.h>
int main() {
    float metros = 0;
    int repeticoes = 100000000;
    for (int i = 0; i < repeticoes; i++) {
        metros += 0.01;
        //if(i>=20000000)
        //    printf("%f\n", metros);
    }
    printf("Esperados: %f km\n", 0.01 * repeticoes / 1000 );
    printf("Obtido   : %f km \n", metros / 1000);
}
