#ifdef istruction_list_h
#define istruction_list_h
#include "istruction_data.h"

/**
 * Lista concatenata contenente le istruzioni per la modifica del file.
 */
struct istruction_list;

typedef struct istruction_list IstructionsList;

/**
 * Metodo che aggiunge un elemento alla lista.
 * @return 0 Se l'operazione è stata completata 1 Se sono stati lanciati errori
 */
int add(IstructionData data);

/**
 * Metodo che restituisce il primo elemento della lista.
 */
IstructionData getFirstIstruction();

/**
 * Metodo che restituisce il primo elemento della lista, rimuovendolo da essa.
 */
IstructionData popFirstIstruction();

/**
 * Metodo che prende una lista da un file.
 */
int getFromFile(FILE *filem);

/**
 * Metodo che salva una lista in un file.
 */
char* saveToFile(FILE *filem);



#endif