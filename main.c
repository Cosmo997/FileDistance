
#include <string.h>
#include "file_distance.h"
#include "leven.h"
#include "time.h"

//TODO Vedere perchè non funzionano gli #include
//TODO Switch iniziale con gli argv
//TODO Help
//TODO Importare filedistance.h
//TODO Vedere il makefile

FILE *inputFile1;
FILE *inputFile2;
FILE *fileM;
FILE *outputfile;
/**
 * 
 * 
 * */
int main(const char *argv[])
{
    switch (*argv[1])
    {
    case 'distance':
        if (sizeof(argv) == 3)
        {
            inputFile1 = fopen(argv[2],"r");
            inputFile2 = fopen(argv[3],"r");
            distance(inputFile1, inputFile2);
            fclose(inputFile1);
            fclose(inputFile2);            
        }
        if (sizeof(argv) == 4)
        {
            inputFile1 = fopen(argv[2],"r");
            inputFile2 = fopen(argv[3],"r");
            outputfile = fopen(argv[4],"w");
            distance_out(inputFile1, inputFile2, outputfile);
            fclose(inputFile1);
            fclose(inputFile2);
            fclose(outputfile);
        }
        else
        {
            printf("\n\nERRORE\n\n");
        }
        
        break;
    case 'apply':
        inputFile1 = (argv[2], "w");
        fileM = fopen(argv[3], "r");
        outputfile = fopen(argv[4],"w");
        apply(inputFile1, inputFile2, outputfile);
        break;
    case 'search':
        search(argv[2], argv[3]);
        break;
    case 'searchall':
        searchAll(argv[2], argv[3], argv[4]);
        break;
    default:
        help();
        break;
    }

}
void help()
{
    printf("How to use \n");
    printf("Edit distance from two file: filedistance distance file1 file2 \n");
    printf("Generete output instraction: filedistance distance file1 file2 output \n");
    printf("Apply instraction: filedistance apply inputfile filem outputfile \n");
    printf("Search file: filedistance search inputfile dir \n");
    printf("Search file with limit: filedistance search inputfile dir limit \n");
}
