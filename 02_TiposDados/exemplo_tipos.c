#include <stdio.h>

int main()
{
    // a = 2147483647; // maior int com sinal de 32 bits
    int a = 0b01111111111111111111111111111111;
    // Modificador %u - inteiro sem sinal (unsigned)
    printf("a: %u\n", a);

    unsigned int b = -1;
    // Observe que podemos exibir como unsigned, mas o valor fica inválido
    printf("b: %u\n", b);

    // Exemplo de falha de precisão no float: com uma parte inteira muito grande,
    // é impossível somar 0,1:

    float v = 1000000.35;
    printf("v: %f\n", v);
    v += 0.1;
    printf("v: %f\n", v);

    // Mas é possível somar 0,0625. Por quê?
    //
    // Lembrando: pensamos numa "janela" entre duas potências de dois
    // Neste caso, 2^19 (524.288) e 2^20 (1048576)
    // A diferença de valores nesse intervalo é 524.288, então considerando que temos
    // 23 bits na mantissa => 2^23 = 8.388.608 valores possíveis entre eles
    // Logo, o menor incremento possível é 524.288 / 8.388.608 = 0,0625
    
    v += 0.0625;
    // Observe que agora funcionou corretamente!
    printf("v: %f\n", v);
}
