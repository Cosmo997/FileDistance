#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "timer.h"
#include "leven.h"
#include "linked_list.h"

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
 * Restituisce una LinkedList contenente le istruzioni che dovranno essere applicate al file per trasformarlo.
 */
LinkedList * findEditPath(FILE * output, int ** matrix,  int nrighe , int ncolonne, char * finalResault, char * toModify);

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
void recFind(FILE * output, int ** matrix, int riga, int colonna, char * toModify, char * finalResault);

/**
 * Restituisce la striga contenuta nel file path.
 */
char * getStringFromFile(char * path);

/**
 * 
 */
void writeList(char * filemPath, LinkedList * lista);


LinkedList * lista = NULL;

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

LinkedList * findEditPath(FILE * output, int ** matrix,  int nrighe , int ncolonne, char * finalResault, char * toModify)
{
    recFind(output, matrix, nrighe-1, ncolonne-1, toModify, finalResault);
    printf("\n\n");
    return lista;
}

void recFind(FILE * output, int ** matrix, int riga, int colonna, char * toModify, char * finalResault)
{   
    if (matrix[riga][colonna] != 0)
    {   
        if(riga -1>=  0 && colonna-1>= 0)
        {
        int app = min(matrix[riga][colonna-1],matrix[riga-1][colonna-1],matrix[riga-1][colonna]);
        if(matrix[riga -1 ][colonna - 1] == app)
        {
            if(matrix[riga][colonna] != matrix[riga-1][colonna-1])
            {
            pushIstruction(&lista, SET, colonna-1, finalResault[riga-1]); // ! SET
            }
            recFind(output, matrix, riga - 1, colonna -1,toModify, finalResault);
        }
        else if (matrix[riga][colonna -1] == app && colonna-1 >= 0)
        {
            pushIstruction(&lista, ADD, colonna-1, finalResault[colonna-1]); // ! ADD
            recFind(output, matrix, riga, colonna-1, toModify, finalResault);
        }
        else if(matrix[riga-1][colonna] == app && riga-1 >= 0)
        {
            pushIstruction(&lista, DEL, riga,'-'); // ! DEL
            recFind(output, matrix, riga-1, colonna, toModify, finalResault);
        }
        }
        else if (riga - 1 < 0)
        {
            pushIstruction(&lista, ADD, colonna-1, finalResault[colonna-1]); // ! ADD
            recFind(output, matrix, riga, colonna-1, toModify, finalResault);
        }
        else if (colonna - 1 < 0)
        {
            pushIstruction(&lista, DEL, riga,'-'); // ! DEL
            recFind(output, matrix, riga - 1, colonna, toModify, finalResault);
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

int levensthein_distance_out(char * toModify, char * finalResault, char *outputPath)
{
    
    stringsElaboration(toModify, finalResault);
    start_timer();
    int nrighe = (int) strlen(finalResault)+1;
    int ncolonne = (int) strlen(toModify)+1;
    int **matrix = createMatrix(nrighe, ncolonne);
    fillMatrix(matrix, toModify, nrighe, finalResault, ncolonne);
    int distance = matrix[nrighe-1][ncolonne-1];
    LinkedList * lista = findEditPath(matrix, nrighe, ncolonne, toModify,finalResault);
    writeList(outputPath, lista);
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

void writeList(char * outputPath, LinkedList * lista)
{
    FILE *filem = fopen(outputPath, "wb+");
    if(filem == NULL)
        return -1;
    char* command = NULL;
    unsigned int num = 0;
    
    while (lista != NULL) {
        switch (lista->type) {
            case DEL:
                command = getIstructionName(lista->type);
                for (int i = 0; i<3; i++) {
                    fwrite(&command[i], sizeof(char), 1, filem);
                }
                fwrite(&lista->pos, sizeof(unsigned int), 1, filem);
                break;
            case ADD:
                command = getIstructionName(lista->type);
                for (int i = 0; i<3; i++) {
                    fwrite(&command[i], sizeof(char), 1, filem);
                }
                num = lista->pos;
                fwrite(&num, sizeof(unsigned int), 1, filem);
                fwrite(&lista->character, sizeof(char), 1, filem);
                break;
            case SET:
                command = getIstructionName(lista->type);
                for (int i = 0; i<3; i++) {
                    fwrite(&command[i], sizeof(char), 1, filem);
                }
                num = lista->pos;
                fwrite(&num, sizeof(unsigned int), 1, filem);
                fwrite(&lista->character, sizeof(char), 1, filem);
                break;
        }
        lista = lista->next;
    }
    fclose(filem);
    

}
