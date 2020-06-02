#ifndef leven_h
#define leven_h

#include <stdio.h>
#include <stdlib.h>

/**
 * Metodo che restituisce la distanza di edit tra due stringhe
 */
int levensthein_distance(char *x, char *y);

/**
 * Metodo che crea il FileM utilizzato dalla libreria file_modifier.h per Applicare i cambiamenti da fare
 * Restituisce il path del file creato
 */
char* create_file_edit();

#endif 
