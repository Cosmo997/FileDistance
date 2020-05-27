#include <stdio.h>
#include <stdlib.h>
#define DIM 15

void create_random_string(char* str);
char* find_first(char* str, char c);

int main(void)
{
    char stringa[DIM];
    char* stri = stringa;
    create_random_string(stri);
        for (int i = 0; i < DIM; i++)
            {
                printf("%c", stringa[i]);
            }    
    printf("\n Risultato: %s\n", find_first(stri,'E'));
    return 0;
}

void create_random_string(char* str)
{
    for (int i = 0; i < DIM; i++)
    {
        str[i] = 'A' + (random() % 26);
        printf("%c", str);
        str++;
    }
}
char* find_first(char* str, char c)
{
    while (str++ != "\0")
    {
        if (*str == 'c')
            return str;
    }
    return NULL;
}
