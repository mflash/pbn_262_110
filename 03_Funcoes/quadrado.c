#include <stdio.h>

void quadrado(); // protótipo

int main()
{
    quadrado();
}

void quadrado()
{
    for(int k=1; k<=10; k++) {
        printf("%d\n", k);
    }
}