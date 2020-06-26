#ifndef leven_h
#define leven_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "istruction_structure.h"
#include "timer.h"

/**
 * Restituisce la distanza di edit tre le due stringhe in ingresso e scrive le istruzioni in binario nel file output.
 */
int levensthein_distance_out(char * toModify, char *finalResault, char * output);

/**
 * Restituisce la distanza di edit tra le due stringhe in ingresso.
 */
int levensthein_distance(char * toModify, char * finalResault);

#endif 
