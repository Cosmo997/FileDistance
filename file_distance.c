#include "Lib/file_distance.h"
#include "Lib/leven.h"
#include "time.h"

char * buffer1 = NULL;
char * buffer2 = NULL;
long length;

int buffersetter1(FILE *input);
int buffersetter2(FILE *input);

int distance(char *path1, char *path2)
{
    FILE *inputFile1 = fopen(path1,"r");
    if(inputFile1 == NULL)
    {
        perror("\nErrore nell'apertura del primo file\n");
        return 1;
    }
    
    FILE *inputFile2 = fopen(path2,"r");
    if(inputFile2 == NULL)
    {
        perror("\nErrore nell'apertura del secondo file\n");
        return 1;
    }
    
    if(buffersetter1(inputFile1) != 0 || buffersetter2(inputFile2) != 0)
    return 1;
    

    printf("EDIT DISTANCE: %d \n",levensthein_distance(buffer1, buffer2));
    printf("TIME: %lf sec \n", getExecutionTime());

    free(buffer1);
    free(buffer2);
    return 0;
}
//TODO da implementare
int distance_out(char *inputfile1, char *filem, char *outputfile)
{

    return 0;
}
//TODO da implementare
int apply(char *inputfile1, char *filem, char *outputfile)
{

    return 0;
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