#include "istruction_list.h"
#include <stdio.h>
#include "istruction_data.h"


//TODO Implemetare i metodi mancanti


struct istruction_list
{
    IstructionData *data;
    struct modifier_struct *nextIstruction;
};


int add(IstructionData data);

IstructionData getIstruction();

IstructionData popIstruction();

int getFromFile(FILE *filem);

char* saveToFile(FILE *filem);
