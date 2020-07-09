#include <stdio.h>
#include "file_handler.h"
#include "leven.h"
#include "timer.h"
#include "finder.h"
#include "file_distance.h"


int distance(char *toModifyPath, char *finalResaultPath){
    char * toModify = getStringFromFile(toModifyPath);
    char * finalResault = getStringFromFile(finalResaultPath);
    printf("EDIT DISTANCE: %d \n",levensthein_distance(toModify, finalResault));
    printf("TIME: %lf sec \n", getExecutionTime());
    return 0;
}

int distanceOutput(char *toModifyPath, char *finalResaultPath, char *outputFilePath){
    
    char * toModify = getStringFromFile(finalResaultPath);
    char * finalResault = getStringFromFile(toModifyPath);
    int distance = levensthein_distance_out(toModify, finalResault, outputFilePath);
    printf("EDIT DISTANCE: %d \n",distance);
    printf("TIME: %lf\n", getExecutionTime());
    return 0;
}

int apply(char *inputfilePath, char *filemPath, char *outputfilePath){
    changesApply(inputfilePath, filemPath, outputfilePath);
    return 0;
}

int search(char *inputfile, char *dir){
    recFinder(inputfile, dir, -1);
    return 0;
}

int searchAll(char *inputfile, char *dir, int limit){
    recFinder(inputfile, dir, limit);
    return 0;
}
