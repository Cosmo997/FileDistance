#include "Lib/finder.h"

/**
 * Lista iniziale.
 */
ScanData *list = NULL;

/**
 * Contatore degli elementi contenuti nella lista.
 */
int count = 0;

/**
 * Aggiunge uno ScanData in testa.
 */
void add(ScanData** head, char *path, int distance);

/**
 * Scan ricorsivo delle cartelle e delle relative sottocartelle, salvando nella variabile globale list ogni verifica della distanza di edit.
 */
void recScan(char *inputfile, char *basePath);

/**
 * Swap dei dati conetnuti nel nodo ptr1 con ptr2
 */
ScanData * swapData(ScanData* ptr1, ScanData* ptr2);

/**
 * Ordinamento bubblesort della lista concatenata.
 */
int bubbleSort(ScanData ** head, int count);

/**
 * Stampa degli elementi della lista con edit distance <= a limit
 */
void printLimit(ScanData *list, int limit);

/**
 * Ordino la lista ed eseguo un printLimit con limit uguale al valore minore tra gli elementi della lista.
 */
void printMin(ScanData *list);


void add(ScanData** head, char *path, int distance)
{
    ScanData* toAdd = (ScanData*)malloc(sizeof(ScanData));
    count++;
    toAdd->path = (char*)malloc((strlen(path) + 1) * sizeof(char));
    toAdd->next = (*head);
    toAdd->distance = distance;
    strcpy(toAdd->path, path);
    (* head) = toAdd;
}

void recScan(char *inputfile, char *basePath)
{
    char path[1000] = "";
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            if(dp->d_type != DT_DIR){
            int distance = levensthein_distance(inputfile, path);
            add(&list, path, distance);
            }
            recScan(inputfile ,path);
        }
    }
    closedir(dir);
}

void printAll(ScanData *list){
    bubbleSort(&list, count);
    while (list!=NULL) {
        printf("Path: %s \n", list->path);
        list = list->next;
    }
}

void printLimit(ScanData *list, int limit){
    bubbleSort(&list, count);
    while (list != NULL) {
        char *real_path = realpath(list->path, NULL);
        if (list->distance <= limit){
            printf("D: %i \t P: %s \n",list->distance, real_path);
        }
        list = list->next;
    }
}

void printMin(ScanData *list){
    bubbleSort(&list, count);
    printLimit(list, list->distance);
}

void recFinder(char *inputfile, char *basepath, int limit){
    recScan(inputfile, basepath);
    if(limit != -1){
        printLimit(list, limit);
    }else{
        printMin(list);
    }
}

int bubbleSort(ScanData ** head, int count) 
{ 
    ScanData ** h; 
    int i, j, swapped; 
  
    for (i = 0; i <= count; i++) 
    { 
  
        h = head; 
        swapped = 0; 
  
        for (j = 0; j < count - i - 1; j++)  
        { 
  
            ScanData * p1 = *h; 
            ScanData * p2 = p1->next; 
  
            if (p1->distance > p2->distance) 
            { 
  
                *h = swapData(p1, p2); 
                swapped = 1; 
            } 
  
            h = &(*h)->next; 
        } 
  
        if (swapped == 0) 
            break; 
    }
    return 0;
}

ScanData * swapData(ScanData* ptr1, ScanData* ptr2) 
{ 
    ScanData * tmp = ptr2->next; 
    ptr2->next = ptr1; 
    ptr1->next = tmp; 
    return ptr2; 
} 
