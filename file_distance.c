#include "Lib/file_distance.h"
#include "Lib/leven.h"
#include "time.h"

char * buffer1 = NULL;
char * buffer2 = NULL;
long length;
FILE *inputFile1 = NULL;
FILE *inputFile2 = NULL;

// TODO Rimuovere variabili globali
void initData(char * path1, char * path2);
void freeData();
int buffersetter1(FILE *input);
int buffersetter2(FILE *input);

int distance(char *path1, char *path2)
{
    initData(path1, path2);
    printf("EDIT DISTANCE: %d \n",levensthein_distance(buffer1, buffer2));
    printf("TIME: %lf sec \n", getExecutionTime());
    freeData();
    return 0;
}

char* distance_out(char *path1, char *path2, char *outputfile)
{
    initData(path1, path2);
    printf("EDIT DISTANCE: %d \n",levensthein_distance(buffer1, buffer2));
    printf("TIME: %lf sec \n", getExecutionTime());
    create_file_edit(outputfile);
    freeData();
    return outputfile;
}

//TODO da implementare
int apply(char *inputfile1, char *filem, char *outputfile)
{
    changeApply(inputfile1, filem, outputfile);
    return 1;
}

//TODO rimuovere codice ripetuto
int buffersetter1(FILE *input)
{   
    fseek(input, 0L, SEEK_END);
    long fsize = ftell(input);
    buffer1 = malloc((sizeof(char)* fsize) + 1);
    fseek(input, 0L, SEEK_SET);
    if(buffer1)
    {
    fread(buffer1, 1, fsize, input);
    return 0;
    }
    else return 1;
}
int buffersetter2(FILE *input)
{
    fseek(input, 0L, SEEK_END);
    long fsize = ftell(input);
    buffer2 = malloc((sizeof(char)* fsize) + 1);
    fseek(input, 0L, SEEK_SET);
    if(buffer2)
    {
    fread(buffer2, 1, fsize, input);
    return 0;
    }
    else return 1;
}

void initData(char * path1, char * path2)
{
    inputFile1 = fopen(path1,"r");
    if(inputFile1 == NULL)
    {
        perror("\nErrore nell'apertura del primo file\n");
    }
    
    inputFile2 = fopen(path2,"r");
    if(inputFile2 == NULL)
    {
        perror("\nErrore nell'apertura del secondo file\n");
    }
    
    buffersetter1(inputFile1); 
    buffersetter2(inputFile2);
}
void freeData()
{
    free(buffer1);
    free(buffer2);
    fclose(inputFile1);
    fclose(inputFile2);
}