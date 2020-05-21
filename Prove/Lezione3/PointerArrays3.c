#include <stdio.h>

int main(void)
{
    int a1[10], a2[10];
    int *pa = a1;
    // ! a1 = a2; ---> Non compila
    // ! a1++; ----> Non complia
    pa++; // ? ---> Compila ma che fa?
    printf("\n");
    printf("%d", pa);
    printf("\n");
}