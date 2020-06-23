#include "Lib/file_modifier.h"
#include "Lib/istruction_structure.h"
#include <string.h>
#include <stdlib.h>

char * addCharacter(char * input, int pos, char toAdd);

char * deleteCharacter(char * input, int pos);

char * setCharacter(char * input, int pos, char toSet);

char * changeApply(char *toModify, char *filem, char *outputPath)
{
    MaxHeap * dafile = initStructure(1,0);
    getFromFile(dafile,filem);
    heapPrint(dafile);

    FILE * inputfile = fopen(toModify,"r");
    fseek(inputfile, 0L, SEEK_END);
    long fsize = ftell(inputfile);
    char * buffer1 = malloc((sizeof(char)* fsize) + 1);
    fseek(inputfile, 0L, SEEK_SET);
    //TODO aggiungere errorhandler
    fread(buffer1, 1, fsize, inputfile);
    
    FILE * out = fopen(outputPath, "w");
    printf("\n%s\n",buffer1);
    while (dafile->count != 0)
    {
        IstructionData istr = popIstruction(dafile);
        switch (istr.istruction)
        {
        case ADD:
            printf("\n Position: %d\nLettera: %c", istr.position, istr.letter);
            addCharacter(buffer1, istr.position,istr.letter);
            break;
        case DEL:
            deleteCharacter(buffer1, istr.position);
            break;
        case SET:
            setCharacter(buffer1, istr.position, istr.letter);
            break;
        default:
        return 0;
            break;
        }
        
    }
    //printf("\n%s\n",buffer1);
    fprintf(out,buffer1);
    fclose(inputfile);
    fclose(out);
    free(buffer1);
    return outputPath;
}

char * addCharacter(char * input, int pos, char toAdd)
{
    printf("\nTOADD: %c\nPOS: %d", toAdd,pos);
    size_t i, len;
    char *temp;

    len = input ? strlen(input) : 0;
    temp = (char *)malloc(len + 2);
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

//TODO
char * getBufferFromFile(char * path)
{
    return "ciao";
}



