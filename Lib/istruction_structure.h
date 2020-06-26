#ifndef istruction_structure_h
#define istruction_structure_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Enum contenente il tipo di modifica da apportare.
 */
typedef enum {ADD, DEL, SET} IstructionType;

/**
 * Restituisce la stringa che identifica una determinata istruzione
 */
char * getIstructionName(IstructionType istr);


/**
 * Sotto-Struttura contenente le informazioni delle istruzioni che saranno utilizzate per apportare modifiche al file.
 */
struct istructionData
{
    /**
     * Tipo di istruzione da apportare: ADD, SET o DEL
     */
    IstructionType istruction;
    /**
     * Unsigned int che indica la posizione in cui verrà apportata la modifica
     */
    int position;
    /**
     * Parametro utilizzato solamente nei metodi ADD e SET, che indica il nuovo valore che avrà la lettera nella posizione position
     */
    char letter;
};
typedef struct istructionData IstructionData;

/**
 * MaxHeap contenente le istruzioni per la modifica del file.
 */
struct MaxHeap
{
    /**
     * Grandezza del MaxHeap
     */
    int size;
    /**
     * Numero di elementi presenti al suo interno
     */
    int count;
    /**
     * Istruzione contenuta
     */
    IstructionData *data;
};
typedef struct MaxHeap MaxHeap;

/**
 * Salva una lista in un file e ritorna il path del file.
 */
char* saveToFile(MaxHeap *h, char * path);

/**
 * Prende una lista da un file e ritorna 0 in caso di successo o 1 in caso di insuccesso.
 */
int getFromFile(MaxHeap *h, char * path);

/**
 * Restituisce un array ordinato in modo crescenti contenente le istruzioni.
 */
IstructionData* getOrderedArray(MaxHeap * h);

/**
 * Crea un IstructionData e lo restituisce.
 */
IstructionData* createData(IstructionType istruction, int position, char letter);

/**
 * Rende utilizzabile la structure e la restituisce.
 */
MaxHeap* initStructure(void);

/**
 * Aggiunge un elemento all MaxHeap.
 */
void pushIstruction(MaxHeap *hp, IstructionType istr, int pos, char lett);

/**
 * Restituisce il primo elemento della lista, rimuovendolo da essa.
 */
IstructionData popIstruction(MaxHeap * hp);

/**
 * Restituisce l'indice del figlio sinistro dell'IstructionData.
 */
int getLeft(int x);

/**
 * Restituisce l'indice del figlio destro dell'IstructionData.
 */
int getRight(int x);

/**
 * Restituisce l'indice del parent dell'IstructionData.
 */
int getParent(int x);

/**
 * Mantiene le proprietà del MaxHeap.
 */
void maxHeapify(MaxHeap *h, int index);

/**
 * Dealloca la memoria utilizzata dall'Heap.
 */
void freeHeap(MaxHeap heap);


/**
 * Stampa l'heap.Utilizzato in debug
 */
void heapPrint(MaxHeap *h);

#endif
