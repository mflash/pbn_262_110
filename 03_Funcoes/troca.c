#include <stdio.h>

void swap(int *var1, int *var2);

int main()
{
    int x = 10, y = 5;
    printf("X: %d, Y: %d\n", x, y);
    swap(&x, &y);
    printf("X: %d, Y: %d\n", x, y);
}

void swap(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

