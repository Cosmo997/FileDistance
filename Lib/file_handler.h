#ifndef file_handler_h
#define file_handler_h
#include <string.h>
#include <stdlib.h>
#include "istruction_structure.h"

/**
 * Applica al file toModify le istruzioni contenute su film, e salva il risultato su outputfile
 */
char * changesApply(char *inputfile1, char *filem, char *outputfile);

/**
 * Restituisce la striga contenuta nel file path.
 */
char * getStringFromFile(char * path);

#endif 
