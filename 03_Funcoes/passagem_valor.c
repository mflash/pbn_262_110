#include <stdio.h>

int multiplica(int x);

int main()
{
    int t = 10;
    printf("%d - %d\n", t, multiplica(t));
    // saída: 100 10
}

int multiplica(int x)
{
    x = x * x;
    return x;
}

