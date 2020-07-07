#include "Lib/leven.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "Lib/istruction_structure.h"
#include "Lib/timer.h"

/**
 * Restituisce il minimo tra i valori in ingresso.
 */
int min(int a, int b, int c);

/**
 * Riduce la complessità dell'algoritmo di leven rimuovendo le lettere finali uguali.
 */
void complexityReduction(char *stringa1, char *stringa2);

/**
 * Pulisce le stringhe da eventiali terminatori di stringa
 */
void stringsElaboration(char * toModify, char * finalResault);

/**
 * Libera la memoria occupata dalla malloc della matrice
 */
void freeMat(int nrighe, int** matrix);

/**
 * Restituisce un MaxHeap contenente le istruzioni che dovranno essere applicate al file per trasformarlo.
 */
MaxHeap * findEditPath(int ** matrix,  int nrighe , int ncolonne, char * finalResault, char * toModify);

/**
 * Crea la matrice e la inizializza, riempiendo la prima riga e la prima colonna con i valori da 0 a n.
 */
int ** createMatrix(int nrighe, int ncolonne);

/**
 * Completa la matrice rispettando le condizioni imposte dall'algoritmo di leven.
 */
int ** fillMatrix(int **matrix, char *str1, int nrighe, char *str2, int ncolonne);

/**
 * Inserisce nel MaxHeap in ingresso le istruzioni per la trasformazione della stringa.
 */
void recFind(int ** matrix, MaxHeap * hp, int riga, int colonna, char * toModify, char * finalResault);


int min(int a, int b, int c) {

    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

void freeMat(int nrighe, int** matrix){
    for (int i = 0; i < nrighe; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int nrighe, int ncolonne){
    
    printf("\n");
    for(int i=0; i < nrighe; i++){
        for(int j=0; j < ncolonne; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

MaxHeap * findEditPath(int ** matrix,  int nrighe , int ncolonne, char * finalResault, char * toModify)
{
    MaxHeap * hp = initStructure();
    recFind(matrix, hp, nrighe-1, ncolonne-1, toModify, finalResault);
    printf("\n\n");
    return hp;
}

void recFind(int ** matrix, MaxHeap * hp, int riga, int colonna, char * toModify, char * finalResault)
{   
    printf("\nRIGA: %d\nCOLONNA: %d\nMATRIX[%d][%d]: %d", riga, colonna, riga, colonna, matrix[riga][colonna]);
    if (matrix[riga][colonna] != 0)
    {   
        printf("qui");
        if(riga -1>=  0 && colonna-1>= 0)
        {
        int app = min(matrix[riga][colonna-1],matrix[riga-1][colonna-1],matrix[riga-1][colonna]);
        if(matrix[riga -1 ][colonna - 1] == app)
        {
            // ! SET
            if(matrix[riga][colonna] != matrix[riga-1][colonna-1])
            {
            pushIstruction(hp, SET, colonna-1, finalResault[riga-1]);
                printf("\nSET%d%c",colonna - 1,finalResault[riga-1]);
            }
            recFind(matrix, hp, riga - 1, colonna -1,toModify, finalResault);
        }
        else if (matrix[riga][colonna -1] == app && colonna-1 >= 0)
        {
            // ! ADD
            pushIstruction(hp, ADD, riga-1, finalResault[riga-1]);
            printf("\nADD%d%c",riga-1,finalResault[riga-1]);
            recFind(matrix, hp, riga, colonna-1, toModify, finalResault);
        }
        else if(matrix[riga-1][colonna] == app && riga-1 >= 0)
        {
            // ! DEL
            pushIstruction(hp, DEL, colonna,'-');
            printf("\nDEL%d", colonna);
            recFind(matrix, hp, riga-1, colonna, toModify, finalResault);
        }
        
        
        }
        else if (riga - 1 < 0)
        {
            // ! ADD
            pushIstruction(hp, ADD, riga-1, finalResault[riga-1]);
            printf("\nADD%d%c",riga-1,finalResault[riga-1]);
            recFind(matrix, hp, riga, colonna-1, toModify, finalResault);
        }
        else if (colonna - 1 < 0)
        {
            // ! DEL
            pushIstruction(hp, DEL, colonna,'-');
            printf("\nDEL%d", colonna);
            recFind(matrix, hp, riga - 1, colonna, toModify, finalResault);
        }
        else return;
    }
    else return;
}

int **fillMatrix(int **matrix, char *toModify, int nrighe, char *finalResault, int ncolonne)
{
   int costo = 0;
    for ( int i = 1; i < nrighe; i++)
    {
        for ( int j = 1; j < ncolonne; j++)
        {
            if (toModify[i - 1] == finalResault[j - 1])
                costo = 0;
            else
                costo = 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + costo);
            
        }
    }
    printMatrix(matrix, nrighe, ncolonne);
    return matrix;
}

int ** createMatrix(int nrighe, int ncolonne){
    int **matrix = (int **)malloc(nrighe * sizeof(int *)); 
    for (int i = 0; i < nrighe; i++)
    {
        matrix[i] = (int*)malloc(ncolonne * sizeof(int*));
    }
    
    for ( int i = 0; i < nrighe; i++)
    {
        matrix[i][0] = i;
    }
    for ( int i = 0; i < ncolonne; i++)
    {
        matrix[0][i] = i;
    }
    return matrix;
}

int levensthein_distance(char *toModify, char *finalResault)
{
    stringsElaboration(toModify, finalResault);
    start_timer();
    int nrighe = (int) strlen(finalResault)+1;
    int ncolonne = (int) strlen(toModify)+1;
    int ** matrix = createMatrix(nrighe, ncolonne);
    fillMatrix(matrix, toModify, nrighe, finalResault, ncolonne);
    int distance = matrix[nrighe-1][ncolonne-1];
    freeMat(nrighe, matrix);
    stop_timer();
    return distance;
}

int levensthein_distance_out(char * toModify, char * finalResault, char *outputPath){
    
    stringsElaboration(toModify, finalResault);
    start_timer();
    int nrighe = (int) strlen(finalResault)+1;
    int ncolonne = (int) strlen(toModify)+1;
    
    int **matrix = createMatrix(nrighe, ncolonne);
    fillMatrix(matrix, toModify, nrighe, finalResault, ncolonne);
    //printMatrix(matrix, nrighe, ncolonne);
    MaxHeap * hp = findEditPath(matrix, nrighe, ncolonne, toModify,finalResault);
    int distance = hp->count;
    saveToFile(hp, outputPath);
    freeMat(nrighe, matrix);
    stop_timer();
    return distance;
}

void stringsElaboration(char * toModify, char * finalResault)
{
    if(toModify[strlen(toModify)-1] == '\0')
    toModify[strlen(toModify)-1] = 0;
    if(finalResault[strlen(finalResault)-1] == '\0')
    finalResault[strlen(finalResault)-1] = 0;
    //complexityReduction(toModify, finalResault);
}

void complexityReduction(char *stringa1, char *stringa2)
{
    if(stringa1[strlen(stringa1)-1] == stringa2[strlen(stringa2)-1])
    {
        stringa1[strlen(stringa1)-1] = 0;
        stringa2[strlen(stringa2)-1] = 0;
        complexityReduction(stringa1, stringa2);
    }
    else return;
}
