
#include <string.h>
#include "Lib/file_distance.h"
#include "Lib/leven.h"
#include "Lib/time.h"

//TODO Help



FILE *inputFile1 = NULL;
FILE *inputFile2 = NULL;
FILE *fileM = NULL;
FILE *outputfile = NULL;

void help();

/**
 * 
 * 
 * */
int main(int argc, char *argv[])
{
    
    if(strcasecmp(argv[1], "distance") == 0)
    {
        if(argc == 3)
        {
            help();
        }
        if(argc == 4)
        {
            if (distance(argv[2], argv[3]) != 0)
            return 1;
            return 0;
        }
        if(argc == 5)
        {
            if(distance_out(argv[2], argv[3], argv[4]) != 0)
            return 1;
            return 0;
        }
    }
    else if(strcasecmp(argv[1], "apply") == 0)
    {
        if(apply(argv[2], argv[3], argv[4]) != 0)
        return 1;
        return 0;
    }
    else if(strcasecmp(argv[1], "search") == 0)
    {
        // TODO search(argv[2], argv[3]);
        return 0;
    }
    else if(strcasecmp(argv[1], "searchAll") == 0)
    {
        // TODO searchAll(argv[2], argv[3], argv[4]);
        return 0;
    }
    else
        {
            prova();
        }
}
void help()
{
    printf("\nHelp: \n");
    printf("Distanza tra due file: filedistance distance file1 file2 \n");
    printf("Generazione file di modifica: filedistance distance file1 file2 output \n");
    printf("Applicazione del file di modifica: filedistance apply inputfile filem outputfile \n");
    printf("Search file: filedistance search inputfile dir \n");
    printf("Search file with limit: filedistance search inputfile dir limit \n");
}
