#ifndef file_distance_h
#define file_distance_h


#include <stdio.h>
#include <stdlib.h>
// TODO Sostituire i FILE in input con stringhe
// TODO ! Vedere come si gestiscono le cartelle

/**
 * Metodo che calcola la distanza dal file e generato un output della seguente forma:
 * EDIT DISTANCE: ​ distanza
 * TIME: ​ tempo di calcolo
 */
int distance(char *inputfile1, char *inputfile2);

/**
 * Metodo che salva nel file ​output la sequenza delle istruzioni necessarie per trasformare il primo file nel secondo.
 */
int distance_out(char *inputfile1, char *filem, char *outputfile);

/**
 * Applica a ​ inputfile l ​ e modifiche contenute nel file ​ filem ​ e salva il risultato nel file ​ outputfile ​ .
 */
int apply(char *inputfile1, char *filem, char *outputfile);

/**
 * Restituisce in output i file contenuti in ​ dir ​(e nelle sue sottodirectory) che hanno minima distanza da ​inputfile.
 * Il path assoluto di ogni file viene presentato in una riga dello ​standard output. 
 */
// TODO int search(FILE *inputfile1, DIRECTORY dir);

/**
 * Vengono restituiti in output tutti i file contenuti in dir (e nelle sue sottodirectory)
 * che hanno una distanza da ​nputfile ​ minore o uguale di ​ limit ​ (che è un intero). 
 * I file vengono presentatinello standard output in ordine crescente secondo il seguente formato:
 * distanza pathassolutofile
 * 
 */
// TODO int searchAll(FILE *inputfile1, DIRECTORY dir, int limit);


#endif 