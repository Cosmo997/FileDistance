#ifndef istruction_structure_h
#define istruction_structure_h

#include <stdio.h>

/**
 * Enum contenente il tipo di modifica da apportare.
 */
typedef enum {ADD, DEL, SET} IstructionType;

char* getIstructionName(IstructionType istr);


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
    int size;
    int count;
    IstructionData *data;
};
typedef struct MaxHeap MaxHeap;
/**
 * Metodo che salva una lista in un file e ritorna il path del file.
 */
char* saveToFile(FILE *filem);

/**
 * Metodo che prende una lista da un file e ritorna 0 in caso di successo o 1 in caso di insuccesso.
 */
int getFromFile(FILE *filem);

/**
 * Metodo che crea un IstructionData e lo restituisce.
 */
IstructionData* createData(IstructionType istruction, int position, char letter);

/**
 * Metodo che rende utilizzabile la structure e la restituisce.
 */
MaxHeap* initStructure(int size, int count);


/**
 * Metodo che aggiunge un elemento all MaxHeap.
 * @return 0 Se l'operazione è stata completata 1 Se sono stati lanciati errori
 */
void pushIstruction(MaxHeap *hp, IstructionType istr, int pos, char lett);

/**
 * Metodo che restituisce il primo elemento della lista, rimuovendolo da essa.
 */
IstructionData popIstruction();

/**
 * Metodo che restituisce l'indice del figlio sinistro dell'IstructionData.
 */
int getLeft(int x);

/**
 * Metodo che restituisce l'indice del figlio destro dell'IstructionData.
 */
int getRight(int x);

/**
 * Metodo che restituisce l'indice del parent dell'IstructionData.
 */
int getParent(int x);

/**
 * Metodo che mantiene le proprietà del MaxHeap.
 */
void maxHeapify(MaxHeap *h, int index);

/**
 * Dealloca la memoria utilizzata dall'Heap.
 */
void freeHeap(MaxHeap heap);

void heapPrint(MaxHeap *h);

#endif