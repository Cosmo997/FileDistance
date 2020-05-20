#include <stdio.h>

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main(void)
{
    int x = 5, y = 6;
    printf("\nX : %dnY : %d\n",x,y);
    swap(x,y);
    printf("\nCAMBIO\n");
    printf("\nX : %dnY : %d\n",x,y);
    //Nel secondo print non è cambiato niente perchè i valori sono passati by Reference, 
    //quindi vengono create delle copie, e di conseguenza quelli originali non vengono toccati.
}