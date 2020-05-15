#include <stdio.h>

int globalvar = 1;
extern double myVariable; 
/*  
    La variabile è solo un segnaposto, verrà poi utilizzata nel file Two.c
    Viene comunque inizializzata a 0, se tolgo extern sarebbe una variabile diversa da quella di Two.c
*/
void myFunction(int idx);
