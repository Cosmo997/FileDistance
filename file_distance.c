#include "file_distance.h"
#include "leven.h"
#define MAXBUFLEN 10000

char buffer1[MAXBUFLEN + 1];
char buffer2[MAXBUFLEN + 1];
long length;

int buffersetter1(FILE *input);
int buffersetter2(FILE *input);

int distance(FILE *inputfile1, FILE *inputfile2)
{
    if(buffersetter1(inputfile1) != 0 || buffersetter2(inputfile2) != 0 || stringCompare(buffer1, buffer2) != 0)
    return 1;
   /* if(buffersetter2(inputfile2) != 0)
    return 1;
    if(stringCompare(buffer1, buffer2) != 0)
    return 1;*/
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

//TODO rimuovere codice ripetuto

int buffersetter1(FILE *input)
{
    if (input != NULL) 
    {
        size_t newLen = fread(buffer1, sizeof(char), MAXBUFLEN, input);

        if ( ferror( input ) != 0 ) 
        {
            fputs("Error reading file", stderr);
        } 
        else 
        {
            buffer1[newLen++] = '\0';
            return 0;
        }
    }
    else
    {
        printf("\n\nErrore, il file è vuoto! \n\n");
        return 1;
    }
}
int buffersetter2(FILE *input)
{
    if (input != NULL) 
    {
        size_t newLen = fread(buffer2, sizeof(char), MAXBUFLEN, input);

        if ( ferror( input ) != 0 ) 
        {
            fputs("Error reading file", stderr);
        } 
        else 
        {
            buffer2[newLen++] = '\0';
            return 0;
        }
    }
    else
    {
        printf("\n\nErrore, il file è vuoto! \n\n");
        return 1;
    }
}