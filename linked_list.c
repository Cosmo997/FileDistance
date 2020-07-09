#include "linked_list.h"
#include <stdio.h>

void pushIstruction(LinkedList ** head_ref, IstructionType type, unsigned int pos, char character)
{
    LinkedList * new_node = (LinkedList *)malloc(sizeof(LinkedList));
    new_node->type = (IstructionType)malloc(sizeof(IstructionType));
    new_node->character = (char)malloc(sizeof(char));
    new_node->pos  = (unsigned int)malloc(sizeof(unsigned int));
    new_node->next = (*head_ref);
    new_node->type = type;
    new_node->character = character;
    new_node->pos = pos;
    (*head_ref) = new_node;
}

void reverse(LinkedList** head_ref){
    LinkedList *prev = NULL;
    LinkedList *current = *head_ref;
    LinkedList *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

char* getIstructionName(IstructionType istr) 
{
   switch (istr) 
   {
      case DEL: return "DEL";
      case ADD: return "ADD";
      case SET: return "SET";
   }
}

void printList(LinkedList * node)
{
    while (node != NULL)
    {
        printf("\nType: %s \n", getIstructionName(node->type));
        printf("Pos: %i \n", node->pos);
        printf("Char: %c \n", node->character);
        node = node->next;
    }
}

