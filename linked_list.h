#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>

/**
 * Enum contenente il tipo di istruzione
 */
typedef enum {
    SET,
    ADD,
    DEL,
} IstructionType;

/**
 * Lista concatenata contenete l'istruzione, la posizione e il carattere da utilizzare
 */
typedef struct list{
    IstructionType type;
    unsigned int pos;
    char character;
    struct list *next;
    }LinkedList;

/**
 * Inserimento di una nuova istruzione all'interno della lista.
 */
void pushIstruction(LinkedList** head_ref, IstructionType type, unsigned int pos, char character);

/**
 * Reverse della lista concatenata.
 */
void reverse(LinkedList** head_ref);

/**
 * Restituisce la stringa associata ad ogni istruzione
 */
char * getIstructionName(IstructionType istr);


#endif
