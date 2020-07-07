#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lib/istruction_structure.h"
#include "Lib/file_handler.h"

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

char * changesApply(char * toModifyPath, char * filemPath, char * outputPath)
{
    MaxHeap * dafile = NULL;
    dafile = initStructure();
    if (dafile == NULL)
    {
        return NULL;
    }
    getFromFile(dafile,filemPath);
    char * buffer = getStringFromFile(toModifyPath);
    if(buffer == NULL)
        return 0;
    
    FILE * out = fopen(outputPath, "w");
    while (dafile->count != 0)
    {
        IstructionData istr = popIstruction(dafile);
        switch (istr.istruction)
        {
        case ADD:
            addCharacter(buffer, istr.position-1,istr.letter);
            break;
        case DEL:
            deleteCharacter(buffer, istr.position-1);
            break;
        case SET:
            setCharacter(buffer, istr.position-1, istr.letter);
            break;
        }
        
    }
    fprintf(out,buffer);
    fclose(out);
    free(buffer);
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


