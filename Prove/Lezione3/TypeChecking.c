#include <stdio.h>

int main(void)
{
    float i = 2.f;
    //   unsigned long *p1 = &i;  ------> Errore, Non compila
    unsigned long *p1 = (unsigned long *) &i; //Funziona, ma è rischioso.
}