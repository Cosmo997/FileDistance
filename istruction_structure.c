#include "Lib/istruction_structure.h"

/**
 * Scambia i valori alla posizione uno e due del MaxHeap.
 */
void swap(MaxHeap * hp, int uno, int due);

MaxHeap* initStructure()
{
    MaxHeap *hp = malloc(sizeof(MaxHeap));
    hp->data = (IstructionData *)malloc(sizeof(IstructionData*));
    hp->count = 0;
    hp->size = 1;
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
		hp->size++;
		hp->data = realloc(hp->data, sizeof(IstructionData) * hp->size);
		if (!hp->data) printf("ERRORE"); 
	}
    
    hp->data[hp->count] = x;
    int i = hp->count;
    while (i>1 && hp->data[getParent(i)].position < hp->data[i].position)
    {
        swap(hp, i, getParent(i));
        i = getParent(i);
    }
    hp->count ++;
    if(hp->count > 1)
    maxHeapify(hp, 0);
}

IstructionData popIstruction(MaxHeap *h)
{
    IstructionData toReturn = h->data[0];
    h->data[0] = h->data[h->count];
    maxHeapify(h,0);
    h->count--;
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

void swap(MaxHeap * hp, int uno, int due)
{
    IstructionData temp = hp->data[uno];
    hp->data[uno] = hp->data[due];
    hp->data[due] = temp;
}

void heapPrint(MaxHeap *h)
{
    if(h->count == 0) return;

    printf("\n\nMaxHeap:\nSize: %d", h->size);
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

IstructionType getIstructionByC(char x)
{
    switch (x)
    {
    case 'A':
        return ADD;
        break;
    case 'S':
        return SET;
        break;
    case 'D':
        return DEL;
        break;
    default:
        return 0;
        break;
    }
}

void maxHeapify(MaxHeap *h, int index)
{
    int l = getLeft(index); 
    int r = getRight(index); 
    int bigger = index; 
    if (l < h->count && h->data[l].position > h->data[index].position)
    {
        bigger = l; 
    }
    if (r < h->count && h->data[r].position > h->data[bigger].position)
    {
        bigger = r;
    }
    
    if (bigger != index) 
    { 
        swap(h, index, bigger); 
        maxHeapify(h,bigger);
    } 
}

char* saveToFile(MaxHeap *h, char * path)
{
    FILE *filem = fopen(path, "wb+");
    if(filem == NULL)
        return NULL;
    
    while(h->count != 0)
    {
        IstructionData app = popIstruction(h);
        char * istr = getIstructionName(app.istruction);
        int pos = app.position;
        fwrite(&istr[0], sizeof(char), 1, filem);
        fwrite(&istr[1], sizeof(char), 1, filem);
        fwrite(&istr[2], sizeof(char), 1, filem);
        fwrite(&pos, sizeof(int), 1,filem);
        if(app.istruction != DEL)
        {
        fwrite(&app.letter,sizeof(char),1,filem);
        }
     }
     fclose(filem);
     return path;

}

int getFromFile(MaxHeap *h, char * path)
{
    FILE *filem = NULL;
    filem = fopen(path,"rb");
    if (filem == NULL)
    {
        return -1;
    }
    
    char istr;
    int pos;
    char letter = '0';
    int nread = 0;
    do
    {
        
        nread = fread(&istr,sizeof(char),1,filem);
        if(nread != 0)
        {
        fseek(filem,2,SEEK_CUR);
        fread(&pos, sizeof(int),1, filem);
        if(istr != 'D')
        fread(&letter, sizeof(char),1,filem);
        pushIstruction(h,getIstructionByC(istr), pos, letter);
        }
    } while (!feof(filem));
    fclose(filem);
    return 0;
}

IstructionData* getOrderedArray(MaxHeap * h)
{
    IstructionData * toReturn = malloc(sizeof(IstructionData*) * h->count);
    for (int i = 0; i < h->count; i++)
    {
        toReturn[i] = popIstruction(h);
    }
    return toReturn;
    
}

