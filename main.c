
#include <string.h>
#include "leven.h"
#include "time.h"




/**
 * TODO Vedere perchè non funzionano gli #include
 * TODO Switch iniziale con gli argv
 * TODO Help
 * TODO Importare filedistance.h
 * TODO Vedere il makefile
 * 
 * */
int main(const char *argv[]) {
    
    if(argc == 1){
        help();
        exit(1);
    }
    else if(strcmp(argv[1], "distance") == 0){
        if(argc == 4)
        result(argv[2], argv[3], stop_timer());
        else if (argc == 5){
            
        }
    }
    return 0;
}
void help(){
    printf("How to use \n");
    printf("Edit distance from two file: filedistance distance file1 file2 \n");
    printf("Generete output instraction: filedistance distance file1 file2 output \n");
    printf("Apply instraction: filedistance apply inputfile filem outputfile \n");
    printf("Search file: filedistance search inputfile dir \n");
    printf("Search file with limit: filedistance search inputfile dir limit \n");
}
