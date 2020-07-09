#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    SET,
    ADD,
    DEL,
} IstructionType;

typedef struct list{
    IstructionType type;
    unsigned int pos;
    char character;
    struct list *next;
    }LinkedList;

void pushIstruction(LinkedList** head_ref, IstructionType type, unsigned int pos, char character);

void reverse(LinkedList** head_ref);

void printList(LinkedList *node);

char * getIstructionName(IstructionType istr);

int getNuberOfElements(LinkedList * node);

#endif
