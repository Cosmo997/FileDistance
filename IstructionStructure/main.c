#include <stdio.h>
#include "istruction_structure.h"

void main(void)
{
    
    IstructionData *ciao = createData(DEL, 5, 'E');
    MaxHeap *cavallo = NULL;
    cavallo = initStructure(1,0);

    pushIstruction(cavallo,DEL, 1, 'E');


    pushIstruction(cavallo,DEL, 2, 'A');
    pushIstruction(cavallo,DEL, 3, 'T');
    pushIstruction(cavallo,DEL, 4, 'P');
    
    //heapPrint(cavallo);

    IstructionData big = popIstruction(cavallo);

    printf("\n\n\nIstruzione %s\nLettera: %c\nPosizione: %d", big.istruction, big.letter, big.position);



}