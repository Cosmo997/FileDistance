#ifndef filedistance_h
#define filedistance_h

#include <stdio.h>
#include "istruction_structure.h"
#include "file_handler.h"
#include "leven.h"
#include "timer.h"
#include "finder.h"

/**
 * Funzione che restituisce la distanza di edit tra le due stringhe ricevute in ingresso.
 */
int distance(char *toModify, char *finalResault);

/**
* Funzione che restituisce la distanza di edit tra le due stringhe ricevute in ingresso e salva le istruzioni, ordinate in modo decrecente, sul file con path outputfilePath
 */
int distanceOutput(char *toModify, char *finalResault, char *outputfilePath);

/**
 * Applica al file toModify le istruzioni contenute su film, e salva il risultato su outputfile
 */
int apply(char * toModify, char * filem, char * outputfile);

/**
 * Restituisce in output i file contenuti in ​dir ​(e nelle sue sottodirectory) che hanno minima 
 * distanza da ​inputfile. ​ Il path assoluto di ogni file viene presentato in una riga dello standard
 * output.
 */
int search(char *inputfile, char * dir);

/**
 * Vengono restituiti in output tutti i file contenuti in dir (e nelle sue sottodirectory) che hanno 
 * una distanza da ​ inputfile ​ minore o uguale di ​limit (che è un intero). I file vengono presentati
 * nello standard output in ordine crescente secondo il seguente formato:
 * distanza pathassolutofile
 */
int searchAll(char * inputfile, char * dir, int limit);

#endif
