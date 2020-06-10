#ifndef leven_h
#define leven_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timer.h"

//TODO Aggiungere i metodi privati come static

/**
 * Metodo che restituisce la distanza di edit tra due stringhe
 */
int levensthein_distance(char *x, char *y);

//TODO Organizzare meglio le responsabilità delle librerie
/**
 * Metodo che crea il FileM utilizzato dalla libreria file_modifier.h per Applicare i cambiamenti da fare
 * Restituisce il path del file creato
 */
char* create_file_edit(FILE *output);

#endif 
