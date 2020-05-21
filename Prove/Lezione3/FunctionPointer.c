#include <stdio.h>
#include <stdlib.h>
#define DIM 15

char* create_random_string(void);
char* find_first(char* str, char c);
double* geometric_growth(void);

int main(void)
{
    printf("\n Risultato: %c\n", find_first(create_random_string(),'E'));
}

char* create_random_string()
{
    static char stringa[DIM];

    for (int i = 0; i < sizeof(stringa); i++)
    {
        stringa[i] = 'A' + (random() % 26);
    }
    return stringa;
}
char* find_first(char* str, char c)
{
    while (str++ != '\0')
    {
        if (*str == 'c')
            return str;
    }
    return NULL;
}
double* geometric_growth(void)
{
    static double grows = 0.1;
    grows *= 1.1;
    return &grows;
}