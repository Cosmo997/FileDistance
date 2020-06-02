#include "file_distance.h"
#include "leven.h"

char * inputBuffer1 = 0;
char inputBuffer2[10000];
char filemBuffer[10000];
long length;

int distance(FILE *inputfile1, FILE *inputfile2)
{
    if(inputfile1 != NULL)
    {
        fseek (inputfile1, 0, SEEK_END);
        length = ftell (inputfile1);
        fseek (inputfile1, 0, SEEK_SET);
        inputBuffer1 = malloc (length);
        if (inputBuffer1)
        {
             fread (inputBuffer1, 1, length, inputfile1);
        }
    }
    printf(inputBuffer1);
    free(inputBuffer1);
    return 0;
}

int distance_out(FILE *inputfile1, FILE *filem, FILE *outputfile)
{

    return 0;
}

int apply(FILE *inputfile1, FILE *filem, FILE *outputfile)
{

    return 0;
}

char* converter(FILE testo)
{
    
}