#ifdef istruction_list_h
#define istruction_list_h
#include "istruction_data.h"

//TODO Commentare
struct istruction_list;

typedef struct istruction_list IstructionsList;

int add(IstructionData data);

IstructionData getFirstIstruction();

IstructionData popFirstIstruction();

int getFromFile(FILE *filem);

char* saveToFile(FILE *filem);



#endif