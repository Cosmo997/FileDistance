#ifndef leven_h
#define leven_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "istruction_structure.h"
#include "timer.h"

/**
 * Metodo che restituisce la distanza di edit tra due stringhe
 */
int levensthein_distance(char * toModify, char * finalResault);

MaxHeap * levensthein_distance_out(char * toModify, char * finalResault);

//TODO Organizzare meglio le responsabilità delle librerie
/**
 * Metodo che crea il FileM utilizzato dalla libreria file_modifier.h per Applicare i cambiamenti da fare
 * Restituisce il path del file creato
 */
char * create_file_edit(MaxHeap * hp, char * path);



#endif 
