#include <stdio.h>

int main(void)
{
    char c = 'A';
    char *pc = &c;
    double d = 2.56;
    double *pd1, *pd2;
    
    pd1 = &d;
    pd2 = pd1;


    printf("\nValore c : %c", c);
    printf("\nValore puntatore a c : %c", *pc);
    printf("\nValore d: %.2f", d);
    printf("\nValore puntatore1 a d: %.2f", *pd1);
    printf("\nValore puntatore2 a d: %.2f\n", *pd2);

    *pd1 = *pd2 * 2.0;
    *pc = 'B';

    printf("\nValore c : %c", c);
    printf("\nValore puntatore a c : %c", *pc);
    printf("\nValore d: %.2f", d);
    printf("\nValore puntatore1 a d: %.2f", *pd1);
    printf("\nValore puntatore2 a d: %.2f\n", *pd2);
}