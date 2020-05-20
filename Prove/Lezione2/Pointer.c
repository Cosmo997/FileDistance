#include <stdio.h>

int main(void)
{
    int i = 6;

    int *j1 = &i;

    int j2 = &i;
    
    int f = *j1;

    *j1 = *j1 +1;

    printf("\nValore i: %d\n", i);
    printf("\nValore *j1: %d\n", *j1);
    printf("\nValore j2: %d\n", j2);
    printf("\nValore f: %d\n\n", f);

}