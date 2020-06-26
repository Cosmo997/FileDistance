#ifndef finder_h
#define finder_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "leven.h"

/**
 * Struct contenente path, distanza e puntatore al nodo successivo della lista.
 */
struct ScanData{
    /**
     * Path del file
     */
    char *path;
    /**
     * distanza del file dal file in input
     */
    int distance;
    /**
     * Punatore all'elemento successivo
     */
    struct ScanData *next;
};
typedef struct ScanData ScanData;

/**
 * Funzione che si occupa dell'applicazione alle cartelle di leven.
 */
void recFinder(char *inputfile, char *basepath, int limit);

#endif
