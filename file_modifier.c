#include "Lib/file_modifier.h"
#include "Lib/istruction_structure.h"



MaxHeap * changeApply(char *inputfile1, char *filem, char *outputfile)
{
    MaxHeap * dafile = initStructure(1,0);
    getFromFile(dafile,outputfile);
    heapPrint(dafile);
    return dafile;
}

./filedistance apply File/prova1.txt File/prova.bin File/prova2.txt



