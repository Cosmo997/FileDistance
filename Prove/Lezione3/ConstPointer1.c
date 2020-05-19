#include <stdio.h>

int main(void)
{
    // CONST FORMA 1
    int i = 5, j = 6;
    const int *p = &i;

    printf("\nValore di i: %d", i);
    printf("\nValore di j: %d", j);
    printf("\nValore del puntatore *p: %d\n", *p);

    //  *p = j;  ------->  Non si può fare, const non permette di modificare i valori 
    //                     a quell'indirizzo tramite se stesso

    p = &j; // E' permesso cambiare indirizzo alle variabili const
    printf("\nCambio p = &j\n");
    //  *p = i;  ------->  Non si può fare, const non permette di modificare i valori 
    //                     a quell'indirizzo tramite se stesso

    printf("\nValore di i: %d", i);
    printf("\nValore di j: %d", j);
    printf("\nValore del puntatore *p: %d\n", *p);
}