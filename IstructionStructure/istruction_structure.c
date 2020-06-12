#include "istruction_structure.h"
#include <stdio.h>
#include <stdlib.h>

void recHeapy(MaxHeap *h, int index);
void swap(IstructionData * uno, IstructionData * due);



IstructionData* createData(IstructionType istr, int pos, char lett)
{
    IstructionData* x = malloc(sizeof(IstructionData));
    x->istruction = istr;
    x->position = pos;
    x->letter = lett;
    return x;
}


MaxHeap* initStructure(int size, int count)
{
    MaxHeap *hp = malloc(sizeof(MaxHeap));
    hp->count = count;
    hp->size = size;
    hp->data = malloc(sizeof(IstructionData) * size);
    //printf("\nIstruzione: %s%d%c",getIstructionName(hp->data[0].istruction), hp->data[0].position,hp->data[0].letter);

    return hp ;
}

void pushIstruction(MaxHeap *hp, IstructionType istr, int pos, char lett)
{
    IstructionData x;
    x.istruction = istr;
    x.position = pos;
    x.letter = lett;
    if (hp->count == hp->size)
	{
        //TODO rimuovere la realloc
		hp->size++;
		hp->data = realloc(hp->data, sizeof(IstructionData) * hp->size);
		if (!hp->data) printf("ERRORE"); 
	}
    
    hp->data[hp->count] = x;
    int i = hp->count;
    while (i>1 && hp->data[getParent(i)].position < hp->data[i].position)
    {
        swap(&hp->data[i], &hp->data[getParent(i)]);
        i = getParent(i);
    }
    hp->count ++;
    maxHeapify(hp, 0);
}

IstructionData popIstruction(MaxHeap *h)
{
    printf("\nQUI\n");
	// Resize the heap if it's consuming too much memory
	if (h->count < h->size > 2)
	{
		h->size >>= 1;
		h->data = realloc(h->data, sizeof(IstructionData) * h->size);
		if (!h->data) printf("ERRORE"); // Exit if the memory allocation fails
	}

    IstructionData toReturn = h->data[0];
    h->data[0] = h->data[h->count];
    maxHeapify(h,0);
    return toReturn;
}

int getLeft(int x)
{
    return 2 * x + 1;
}

int getRight(int x)
{
    return 2 * x + 2;
}

int getParent(int x)
{
    return (x - 1) / 2;
}

void swap(IstructionData * uno, IstructionData * due)
{
    IstructionData * temp;
    temp = uno;
    uno = due;
    due = temp;
}

int posCompare(int pos1, int pos2)
{
    if(pos1 > pos2)
        return pos1;
    return pos2;
}

void recHeapy(MaxHeap *h, int index)
{
    int left = getLeft(index);
    int right = getRight(index); 
    if(h->data[index].position < h->data[left].position && h->data[index].position < h->data[right].position)
    {
        int bigger = posCompare(h->data[left].position, h->data[right].position);
        swap(&h->data[index],&h->data[bigger]);
        recHeapy(h,bigger);
    }
    else return;
}

void heapPrint(MaxHeap *h)
{
    if(h->count == 0) return;

    printf("\nSize: %d", h->size);
    printf("\nCount: %d", h->count);
    for (int i = 0; i < h->count; i++)
    {
        printf("\nIstruzione: %s%d%c",getIstructionName(h->data[i].istruction), h->data[i].position,h->data[i].letter);
    }
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

void maxHeapify(MaxHeap *h, int index)
{
    int l = getLeft(index); 
    int r = getRight(index); 
    int bigger = index; 
    if (l < h->count && h->data[l].position > h->data[index].position ) 
        bigger = l; 
    if (r < h->count && h->data[r].position > h->data[bigger].position ) 
        bigger = r; 
    if (bigger != index) 
    { 
        swap(&h->data[index], &h->data[bigger]); 
        maxHeapify(h,bigger); 
    } 
}

char* saveToFile(FILE *filem);

int getFromFile(FILE *filem);

void freeHeap(MaxHeap heap);
