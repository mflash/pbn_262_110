#include <stdio.h>

typedef union {
    int i;
    double d;
} MinhaUnion;

typedef union
{
    unsigned char bytes[4];
    unsigned int inteiro;
} HW_Register;

int main()
{
    MinhaUnion u1;
    u1.i = 255;
    printf("Valor inteiro: %d\n", u1.i);
    u1.d = 1000.2571;
    printf("Valor double: %f\n", u1.d);
    printf("Valor inteiro: %d\n", u1.i);
    u1.i = 255;
    printf("Valor double: %f\n", u1.d);

    HW_Register valor;
    valor.inteiro = 256;
    printf("Valor.inteiro: %u\n", valor.inteiro);
    printf("Valor.bytes[0]: %d\n", valor.bytes[0]);
    printf("Valor.bytes[1]: %d\n", valor.bytes[1]);
    valor.bytes[0] = valor.bytes[1] = valor.bytes[2] = valor.bytes[3] = 255;
    printf("Valor.inteiro: %u\n", valor.inteiro);
}