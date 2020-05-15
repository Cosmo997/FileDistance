#include <stdio.h>

/*
    Static sulle variabili locali.
    La variabile è stata dichiarata dentro la funzione increment, ma funziona anche fuori.
*/

int increment(void)
{
    static int variabile;
    variabile++;
}

int main(void)
{
    printf("Variabile = %d\n", increment());
    printf("Variabile = %d\n", increment());
    printf("Variabile = %d\n", increment());
    printf("Variabile = %d\n", increment());
    // printf("Variabile senza funzione: %d",variabile); -----> Non se può usà perchè è static e sta dentro la funzione
}