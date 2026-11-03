#include <stdio.h>

void print_bin32(unsigned int n);

void print_bin32(unsigned int n)
{
    for (int i = 31; i >= 0; i--)
    {
        unsigned int bit = (n >> i) & 1U;
        putchar(bit ? '1' : '0');
        if (i > 0 && i % 4 == 0)
            putchar(' '); // agrupa em nibbles
    }
    putchar('\n');
}

// Zera todos os bits
unsigned int clear(unsigned int val) { return 0; }

// Seta (liga) o bit n
unsigned int setBit(unsigned int x, int n)
{
    return x | (1U << n);
}

// Reseta (zera) o bit n
unsigned int clearBit(unsigned int x, int n)
{
    return x & ~(1U << n);
}

// Inverte o estado do bit n
unsigned int invertBit(unsigned int x, int n)
{
    return x ^ (1U << n);
}

// Retorna 1 se o bit n for 1; 0 se for 0
int testBit(unsigned int x, int n)
{
    return x & (1U << n);
}

// Campo de bit
typedef struct
{
    unsigned int red : 11; // red vai ocupar NO MÍNIMO 10 bits
    unsigned int green : 11;
    unsigned int blue : 11;
} RGBbit;

int main()
{
    printf("%p\n", main);
    printf("%b\n", main);
    unsigned int valor = 65535;
    printf("Binário (com %%b): %b\n", valor);
    printf("Binário (com a função): ");
    print_bin32(valor);

    printf("\nsizeof(char)      = %zu byte(s)  -> %zu bits\n", sizeof(char), sizeof(char) * 8);
    printf("sizeof(short)     = %zu byte(s)  -> %zu bits\n", sizeof(short), sizeof(short) * 8);
    printf("sizeof(int)       = %zu byte(s)  -> %zu bits\n", sizeof(int), sizeof(int) * 8);
    printf("sizeof(long)      = %zu byte(s)  -> %zu bits\n", sizeof(long), sizeof(long) * 8);

    unsigned char v1 = 0b01001010;
    unsigned char v2 = 0b10010010;

    unsigned res_and = v1 & v2;
    printf("v1:      %08b\n", v1);
    printf("v2:      %08b\n", v2);
    printf("v1 & v2: %08b\n", res_and);

    // Atenção: NOT usa todos os bits!
    unsigned int v3 = 0b11111111; // 255
    printf("v3:  ");
    print_bin32(v3);
    printf("~v3: ");
    print_bin32(~v3);

    unsigned int v4 = 0b10101111;
    printf("\nv4: ");
    print_bin32(v4);
    v4 = setBit(v4, 10);
    printf("v4: ");
    print_bin32(v4);
    v4 = clearBit(v4, 7);
    printf("v4: ");
    print_bin32(v4);

    RGBbit pixel1;
    pixel1.red = 1023;
    pixel1.green = 255;
    pixel1.blue = 56;
    printf("Tamanho de RGBbit: %zu\n", sizeof(pixel1));

    // Campos de bit processados manualmente
    unsigned int cor = 0;
    unsigned int r = 255;
    unsigned int g = 1023;
    unsigned int b = 511;

    // Inicializando o pixel
    cor |= r;
    cor |= (g << 10);
    cor |= (b << 20);

    printf("cor:    ");
    print_bin32(cor);

    // Alterando o verde:
    // 1. Apagar o conteúdo atual
    unsigned int mask = 0b1111111111 << 10;
    printf("mask:   ");
    print_bin32(mask);
    printf("~mask:  ");
    print_bin32(~mask);
    cor = cor & ~mask;
    printf("cor:    ");
    print_bin32(cor);

    // 2. Substitui (OR) com o novo conteúdo
    g = 255;
    cor = cor | (g << 10);
    printf("g:      ");
    print_bin32(g);
    printf("g<<10:  ");
    print_bin32(g << 10);
    printf("cor:    ");
    print_bin32(cor);
}