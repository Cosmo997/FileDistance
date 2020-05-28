//
//  main.c
//  filedistance
//
//  Created by Michele on 27/05/2020.
//  Copyright © 2020 Michele. All rights reserved.
//

#include <getopt.h>
#include <string.h>
#include "levenshtein.h"
#include "time.h"

void help(){
    printf("How to use \n");
    printf("Edit distance from two file: filedistance distance file1 file2 \n");
    printf("Generete output instraction: filedistance distance file1 file2 output \n");
    printf("Apply instraction: filedistance apply inputfile filem outputfile \n");
    printf("Search file: filedistance search inputfile dir \n");
    printf("Search file with limit: filedistance search inputfile dir limit \n");
}

int main(int argc, const char *argv[]) {
    
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
