#include <stdio.h>
#include "franco.h"

void main()
{
    printf("\nArgc: %d", argc);
    printf("\nArgv[0]: %s", argv[0]);
    printf("\nArgv[1]: %s", argv[1]);
    printf("\nArgv[2]: %s", argv[2]);
    printf("\nArgv[3]: %s", argv[3]);
    printf("\nArgv[4]: %s\n", argv[4]);
    ciao();
    dajeDeTacco();
}