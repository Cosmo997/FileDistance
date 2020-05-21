#include <stdio.h>

int main(void)
{
    float fval, array[10];
    float *p1, *p2, *p3 = &array[5];
    int i = 2, j;
    p1 = NULL;
    p2 = &fval;
    p1 = p2;
    p2 = p3 - 4;
    p2 += i;
    j = p3 - p2;
    i = p2 < p3;
    //! ARRAY
    for (int k = 0; k < sizeof(array); k++)
    {
        printf("%f  ", array[k]);
    }

    printf("\n");
}
