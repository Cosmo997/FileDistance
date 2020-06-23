#include "Lib/file_distance.h"
#include "Lib/file_modifier.h"
#include "Lib/leven.h"
#include "time.h"

int distance(char *path1, char *path2)
{
    char * toModify = getStringFromFile(path1);
    char * finalResault = getStringFromFile(path2);
    printf("EDIT DISTANCE: %d \n",levensthein_distance(toModify, finalResault));
    printf("TIME: %lf sec \n", getExecutionTime());
    free(toModify);
    free(finalResault);
    return 0;
}

char* distance_out(char * toModifyPath, char * finalResaultPath, char *outputfilePath)
{
    char * toModify = getStringFromFile(toModifyPath);
    char * finalResault = getStringFromFile(finalResaultPath);
    MaxHeap * hp = levensthein_distance_out(toModify, finalResault);
    printf("EDIT DISTANCE: %d \n",hp->count);
    printf("TIME: %lf sec \n", getExecutionTime());
    create_file_edit(hp, outputfilePath);
    free(toModify);
    free(finalResault);
    return outputfilePath;
}

int apply(char *inputfile1, char *filem, char *outputfilePath)
{
    changeApply(inputfile1, filem, outputfilePath);
    return 1;
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


