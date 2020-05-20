#include <stdio.h>

int main(void)
{
    printf("\n");
    int dim = 10;
    int k = 0;
    unsigned buffer[10];
    for (k = 0; k < dim; k++)
    {
        buffer[k] = k;
    }
    unsigned *pbuffer1 = buffer;
    unsigned *pbuffer2 = buffer +5;
    for ( int i = 0; i < dim; i++)
    {
       printf("%d\t", buffer[i]);
    }
    printf("\n");
    for (int i = 5; i < dim; i++)
    {
        printf("%d\t", pbuffer2[i]);
    }
    
    printf("\n");
    printf("\n");
}