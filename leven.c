#include "Lib/leven.h"

int nrighe = 0;
int ncolonne = 0;
int **matrix = NULL;
int i = 0, j = 0;



// ? filem bin? txt?

int minimum(int a, int b, int c);
void initMatrix();
void fillMatrix();
void findEditPath();
void pmatrix();



//TODO ! Modificare tutto sto metodo
//TODO ! Capire leven
//TODO ! Modificare leven per salvare le modifiche
int levensthein_distance(char *stringa1, char *stringa2){

    stringa1[strlen(stringa1)-1] = 0;
    stringa2[strlen(stringa2)-1] = 0;

    start_timer();

    nrighe = strlen(stringa1);

    ncolonne = strlen(stringa2);

    initMatrix();


    fillMatrix(stringa1, stringa2);

    pmatrix();

    //findEditPath();

    stop_timer();

    return matrix[nrighe][ncolonne];


/*
    int m = strlen(x);
    int n = strlen(y);
    

    register int i, j;
    int distance;
    
    int *prev = malloc((n + 1) * sizeof(int));
    int *curr = malloc((n + 1) * sizeof(int));
    int *tmp = 0;
    
    for(i = 0; i <= n; i++)
        prev[i] = i;

    for(i = 1; i <= m; i++) {
        curr[0] = i;
        for(j = 1; j <= n; j++) {
            if(x[i - 1] != y[j - 1]) {
                int k = minimum(curr[j - 1], prev[j - 1], prev[j]);
                curr[j] = k + 1;
            } else {
                curr[j] = prev[j - 1];
            }
        }

        tmp = prev;
        prev = curr;
        curr = tmp;
        
        memset((void*) curr, 0, sizeof(int) * (n + 1));
    }
    
    distance = prev[n];
    
    free(curr);
    free(prev);





    stop_timer();
    return distance;
    */
}

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int stringCompare(char *x, char *y){
    int distance = levensthein_distance(x, y);
    printf("EDIT DISTANCE: %d \n", distance);
    printf("TIME: %lf sec \n", getExecutionTime());
    return distance;
}


void initMatrix()
{
    matrix = (int**) malloc ((nrighe + 1) * sizeof(int*));

    for ( i = 0; i < nrighe; i++)
    {
        matrix[i] = (int*) malloc((ncolonne +1) * sizeof(int));
    }
    
    for ( i = 0; i < nrighe; i++)
    {
        matrix[i][0] = i;
    }
    for ( i = 0; i < ncolonne; i++)
    {
        matrix[j][i] = i;
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
                printf("\nConfronto lettera %c con %c", stringa1[i-1],stringa2[j-1]);
                matrix[i][j] = minimum(matrix[i][j-1],matrix[i-1][j-1],matrix[i-1][j]) + 1;
            }
            else
            {
                printf("\nConfronto lettera %c con %c", stringa1[i-1],stringa2[j-1]);
                matrix[i][j] = minimum(matrix[i][j-1],matrix[i-1][j-1],matrix[i-1][j]);
            }
            
        }
    }
}
void findEditPath()
{
    return ;
}

char* create_file_edit(FILE *output)
{
    return 0;
}
void prova()
{
    initMatrix();
}
void pmatrix()
{
    printf("\n");
    for ( i = 0; i < nrighe; i++)
    {
        for ( j = 0; j < ncolonne; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}