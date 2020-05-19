#include <stdio.h>

int main(void)
{
    // CONST FORMA 2
    int i = 5, j = 6;
    int * const p = &i;

    printf("\nValore di i: %d", i);
    printf("\nValore di j: %d", j);
    printf("\nValore del puntatore *p: %d\n", *p);

    printf("\nCambio\n");

    *p = j; //------->  Si può fare, "tipo * const" permette di modificare i valori 
            //           a quell'indirizzo tramite se stesso

    //  p = &j; ------> Non è permesso cambiare indirizzo alle variabili "tipo * const"
    

    printf("\nValore di i: %d", i);
    printf("\nValore di j: %d", j);
    printf("\nValore del puntatore *p: %d\n", *p);
    
}