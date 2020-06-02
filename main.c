
#include <string.h>
#include "file_distance.h"
#include "leven.h"
#include "time.h"

//TODO Help
//TODO Importare filedistance.h

//char argomento1[];
//char argomento2[];


FILE *inputFile1 = NULL;
FILE *inputFile2 = NULL;
FILE *fileM = NULL;
FILE *outputfile = NULL;

void help();

/**
 * 
 * 
 * */
int main(int argc, const char *argv[])
{
    
    
    if(strcasecmp(argv[1], "distance") == 0)
    {
        if(argc == 3)
        {
            help();
        }
        if(argc == 4)
        {
            inputFile1 = fopen(argv[2],"r");
            if(inputFile1 == NULL)
            {
                printf("\nErrore nell'apertura del primo file\n");
                return 1;
            }
            
            inputFile2 = fopen(argv[3],"r");
            if(inputFile2 == NULL)
            {
                printf("\nErrore nell'apertura del secondo file\n");
                return 1;
            }
            if (distance(inputFile1, inputFile2) != 0)
            return 1;

            fclose(inputFile1);
            fclose(inputFile2);
            return 0;
        }
        if(argc == 5)
        {
            inputFile1 = fopen(argv[2],"r");
            inputFile2 = fopen(argv[3],"r");
            outputfile = fopen(argv[4],"w");
            distance_out(inputFile1, inputFile2, outputfile);
            fclose(inputFile1);
            fclose(inputFile2);
            fclose(outputfile);
        }
    }
    else if(strcasecmp(argv[1], "apply") == 0)
    {
        inputFile1 = fopen(argv[2], "w");
        fileM = fopen(argv[3], "r");
        outputfile = fopen(argv[4],"w");
        apply(inputFile1, inputFile2, outputfile);
    }
    else if(strcasecmp(argv[1], "search") == 0)
    {
        //search(argv[2], argv[3]);
        printf("\nTODO\n");
        return 0;
    }
    else if(strcasecmp(argv[1], "searchAll") == 0)
    {
        //searchAll(argv[2], argv[3], argv[4]);
        printf("\nTODO\n");
        return 0;
    }
    else
        {
            help();
            exit(1);
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
