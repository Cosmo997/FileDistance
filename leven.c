#include "Lib/leven.h"

int nrighe = 0;
int ncolonne = 0;
int **matrix = NULL;
int i = 0, j = 0, curr = 0;
char * verticale = NULL;
char * orizzontale = NULL;

int min(int a, int b, int c);
void stringElaboration(char * stringa1, char * stringa2);
void complexityReduction(char *stringa1, char *stringa2);
void initMatrix();
void fillMatrix();
void findEditPath();
void recFind();
void pmatrix();

//TODO Riportare i metodi privati nella lib con l'attributo static

int levensthein_distance(char *stringa1, char *stringa2)
{
    start_timer();
    
    stringElaboration(stringa1, stringa2);

    if(nrighe == 0 && ncolonne == 0)
    {
        stop_timer();
        return 0;
    }

    initMatrix();

    fillMatrix(stringa1, stringa2);

    pmatrix();

    findEditPath();

    stop_timer();

    return matrix[nrighe][ncolonne];

}

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

void initMatrix()
{
    matrix = (int**) malloc ((nrighe + 1) * sizeof(int*));

    for ( i = 0; i <= nrighe; i++)
    {
        matrix[i] = (int*) malloc((ncolonne + 1) * sizeof(int));
    }
    
    for ( i = 0; i <= nrighe; i++)
    {
        matrix[i][0] = i;
    }
    for ( i = 0; i <= ncolonne; i++)
    {
        matrix[0][i] = i;
    }
    
}

void fillMatrix(char *stringa1, char *stringa2)
{
    for ( i = 1; i <= nrighe; i++)
    {
        for ( j = 1; j <= ncolonne; j++)
        {
            if(stringa1[i-1] != stringa2[j-1])
            {
                matrix[i][j] = min(matrix[i][j-1],matrix[i-1][j-1],matrix[i-1][j]) + 1;
            }
            else
            {
                matrix[i][j] = min(matrix[i][j-1],matrix[i-1][j-1],matrix[i-1][j]);
            }
            
        }
    }
}

void findEditPath()
{
    curr = matrix[nrighe][ncolonne];
    printf("\n\nCAMMINO ISTRUZIONI:\n");
    recFind(nrighe, ncolonne);
    printf("\n\n");
}

void recFind(int riga, int colonna)
{   
    if (curr != 0 && riga-1 >= 0 && colonna-1 >= 0)
    {
        int app = min(matrix[riga][colonna-1],matrix[riga-1][colonna-1],matrix[riga-1][colonna]);
        if(matrix[riga -1 ][colonna - 1] == app)
        {
            //TODO REPLACE
            if (orizzontale[colonna - 1] != verticale[riga -1])
            {
                printf("\nSET%d%c",riga,orizzontale[colonna-1]);
            }
            
            curr = matrix[riga - 1][colonna - 1];
            recFind(riga - 1, colonna -1);
        }
        else if (matrix[riga][colonna - 1] == app)
        {
            //TODO DELETE
            if(colonna - 1 >= 0){
            if (orizzontale[colonna - 1] != verticale[riga -1])
            {
                printf("\nDEL%d", colonna);
            }
            curr = matrix[riga][colonna - 1];
            recFind(riga, colonna -1);
            }
        }
        else
        {
            //TODO INSERT
            if(riga - 1 >= 0)
            {
            if (orizzontale[colonna - 1] != verticale[riga -1])
            {
                printf("\nADD%d%c",riga-1,verticale[riga-1]);
            }
            curr = matrix[riga-1][colonna];
            recFind(riga -1, colonna);
            }
        }
    }

}

//TODO Da implementare
char* create_file_edit(FILE *output)
{
    return 0;
}

void stringElaboration(char * stringa1, char * stringa2)
{
    if(stringa1[strlen(stringa1)-1] == '\0')
    stringa1[strlen(stringa1)-1] = 0;
    if(stringa2[strlen(stringa2)-1] == '\0')
    stringa2[strlen(stringa2)-1] = 0;
    complexityReduction(stringa1, stringa2);
    nrighe = strlen(stringa1);
    ncolonne = strlen(stringa2);
    verticale = stringa1;
    orizzontale = stringa2;
}

void complexityReduction(char *stringa1, char *stringa2)
{
    if(stringa1[strlen(stringa1)-1] != '\0' && stringa2[strlen(stringa2)-1] != '\0')
    if(stringa1[strlen(stringa1)-1] == stringa2[strlen(stringa2)-1])
    {
        stringa1[strlen(stringa1)-1] = 0;
        stringa2[strlen(stringa2)-1] = 0;
        complexityReduction(stringa1, stringa2);
    }
    else return;
}

void pmatrix()
{
    printf("\n");
    for ( i = 0; i <= nrighe; i++)
    {
        for ( j = 0; j <= ncolonne; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}




