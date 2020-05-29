#ifndef file_distance_h
#define file_distance_h


#include <stdio.h>
#include <stdlib.h>
//TODO Vedere come si gestiscono i File
//TODO Vedere come si gestiscono le cartelle



/**
 * Metodo che calcola la distanza dal file e generato un output della seguente forma:
 * EDIT DISTANCE: ​ distanza
 * TIME: ​ tempo di calcolo
 */
int distance(File file1, File file2);

/**
 * Metodo che salva nel file ​output la sequenza delle istruzioni necessarie per trasformare il primo file nel secondo.
 */
int distance_out(File file1, File file2);

/**
 * Applica a ​ inputfile l ​ e modifiche contenute nel file ​ filem ​ e salva il risultato nel file ​ outputfile ​ .
 * 
 */
int apply(File f1, File m);

/**
 * Restituisce in output i file contenuti in ​ dir ​(e nelle sue sottodirectory) che hanno minima distanza da ​inputfile.
 * Il path assoluto di ogni file viene presentato in una riga dello ​standard output. 
 */
int search(File input, Directory dir);

/**
 * Vengono restituiti in output tutti i file contenuti in dir (e nelle sue sottodirectory)
 * che hanno una distanza da ​nputfile ​ minore o uguale di ​ limit ​ (che è un intero). 
 * I file vengono presentatinello standard output in ordine crescente secondo il seguente formato:
 * distanza pathassolutofile
 * 
 */
int searchAll(File input, Directory dir);

#endif 