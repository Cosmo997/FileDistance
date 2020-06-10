#ifdef istruction_structure_h
#define istruction_structure_h
#include "istruction_data.h"

/**
 * MaxHeap contenente le istruzioni per la modifica del file.
 */
struct istruction_structure
{
	unsigned int size; // Size of the allocated memory (in number of items)
	unsigned int count; // Count of the elements in the heap
	type *data; // Array with the elements
};

typedef struct istruction_structure IstructionStructure;

/**
 * Metodo che rende utilizzabile la structure
 */
int initStructure(struct istruction_structure);


/**
 * Metodo che aggiunge un elemento all MaxHeap.
 * @return 0 Se l'operazione è stata completata 1 Se sono stati lanciati errori
 */
int pushIstruction(IstructionData data);


/**
 * Metodo che restituisce il primo elemento della lista, rimuovendolo da essa.
 */
IstructionData popIstruction();

void heapify(type data[], int count);

/**
 * Metodo che prende una lista da un file e ritorna 0 in caso di successo o 1 in caso di insuccesso.
 */
int getFromFile(FILE *filem);

/**
 * Metodo che salva una lista in un file e ritorna il path del file.
 */
char* saveToFile(FILE *filem);



#endif