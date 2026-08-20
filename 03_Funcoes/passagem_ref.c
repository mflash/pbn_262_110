#include <stdio.h>

void multiplica(int* x);

int main()
{
    int t = 10;
    multiplica(&t);
    printf("%d\n", t);
    // saída: 100
}

void multiplica(int* x)
{
    *x = *x * *x;
}

