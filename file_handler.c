#include "file_handler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"


/**
 * Aggiugne il carattere toAdd alla posizione pos nella stringa input.
 */
char * addCharacter(char * input, int pos, char toAdd);

/**
 * Cancella il carattere alla posizione pos della stringa input.
 */
char * deleteCharacter(char * input, int pos);

/**
 * Modifica il carattere alla posizione pos con il carattere toSet nella stringa input.
 */
char * setCharacter(char * input, int pos, char toSet);

/**
 * Recupera le istruzioni e le relative informazioni dal filem.
 */
LinkedList * loadChanges(char * filemPath);

/**
 * Applica le modifiche contenute in lista alla stringa buffer e poi stampa il suo contenuto nel nuovo file.
 */
void apply(char * buffer, LinkedList * lista, char * outputPath);

/**
 * 
 */
void setCase(FILE * filem, LinkedList * lista, unsigned int pos, char c);

/**
 * 
 */
void delCase(FILE * filem, LinkedList * lista, unsigned int pos);

/**
 * 
 */
void addCase(FILE * filem, LinkedList * lista, unsigned int pos, char c);


char * changesApply(char * toModifyPath, char * filemPath, char * outputPath)
{
    char * buffer = getStringFromFile(toModifyPath);
    LinkedList * lista = loadChanges(filemPath);
    apply(buffer, lista, outputPath);
    return outputPath;
}

char * addCharacter(char * input, int pos, char toAdd)
{
    size_t i, len;
    char *temp;

    len = input ? strlen(input) : 0;
    temp = (char *)malloc(len + 1);
    if (temp != NULL) {
        if (pos > len)
            pos = len;
        for (i = 0; i < pos; i++) {
            temp[i] = input[i];
        }
        temp[i] = toAdd;
        for (; i < len; i++) {
            temp[i + 1] = input[i];
        }
        
    }
    return temp;
}

char * deleteCharacter(char * input, int pos)
{
    memmove(&input[pos], &input[pos + 1], strlen(input) - pos);
    return input;
}

char * setCharacter(char * input, int pos, char toSet)
{
    input[pos-1] = toSet;
    return input;
}

char * getStringFromFile(char * input)
{   
    FILE * inputFile = fopen(input,"r");
    if(inputFile == NULL)
    {
        perror("\nErrore nell'apertura del file\n");
    }
    char * stringa = NULL;
    fseek(inputFile, 0L, SEEK_END);
    long fsize = ftell(inputFile);
    stringa = malloc((sizeof(char)* fsize) + 1);
    fseek(inputFile, 0L, SEEK_SET);
    if(stringa)
    {
    fread(stringa, 1, fsize, inputFile);
    fclose(inputFile);
    return stringa;
    }
    else{
    fclose(inputFile);
    return NULL;
    }
}

LinkedList * loadChanges(char * filemPath)
{
    FILE * filem = fopen(filemPath, "rb+");
    if(filem == NULL){
        perror("\nErrore nell'apertura del file.\n");
        exit(1);
    }
    LinkedList * lista = NULL;
    char command;
    unsigned int pos = 0;
    char c;
    while (!feof(filem)) {
        fread(&command, sizeof(char), 1, filem);
        switch (command) {
            case 'S':
                setCase(filem, lista, pos, c);
                command = '\0';
                break;
            case 'A':
                addCase(filem, lista, pos, c);
                command = '\0';
                break;
            case 'D':
                delCase(filem, lista, pos);
                command = '\0';
                break;
        }
    }
    reverse(&lista);
    return lista;
}

void setCase(FILE * filem, LinkedList * lista, unsigned int pos, char c)
{
    fseek(filem, 2, SEEK_CUR);
    fread(&pos, (sizeof(unsigned int)), 1, filem);
    fread(&c, (sizeof(char)), 1, filem);
    pushIstruction(&lista, SET, pos, c);
}
void delCase(FILE * filem, LinkedList * lista, unsigned int pos)
{
    fseek(filem, 2, SEEK_CUR);
    fread(&pos, (sizeof(unsigned int)), 1, filem);
    pushIstruction(&lista, DEL, pos, '0');
}
void addCase(FILE * filem, LinkedList * lista, unsigned int pos, char c)
{
    fseek(filem, 2, SEEK_CUR);
    fread(&pos, (sizeof(unsigned int)), 1, filem);
    fread(&c, (sizeof(char)), 1, filem);
    pushIstruction(&lista, ADD, pos, c);
}
