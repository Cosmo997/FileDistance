#include <stdio.h>

typedef struct CarloConcatenato Carlo;

struct CarloConcatenato
{
    int x;
    Carlo *carloNext;
};
int main(void)
{
    struct CarloConcatenato terzo = {5,NULL};
    struct CarloConcatenato secondo = {4,&terzo};
    struct CarloConcatenato primo = {3, &secondo};
}
