#include "Lib/leven.h"
#include "Lib/istruction_structure.h"

int nrighe = 0, ncolonne = 0;


/**
 * 
 */
int min(int a, int b, int c);

/**
 * 
 */
void stringsElaboration(char * toModify, char * finalResault);

/**
 * 
 */
void complexityReduction(char * toModify, char * finalResault); 

/**
 * 
 */
int ** initMatrix();

/**
 * 
 */
void fillMatrix(int ** matrix, char *toModify, char *finalResault);

/**
 * 
 */
MaxHeap * findEditPath();

/**
 * 
 */
void recFind(int ** matrix, MaxHeap * hp, int riga, int colonna, char * toModify, char * finalResault);

/**
 * 
 */
void freeMat(int size, int** mat);

int levensthein_distance(char * toModify, char * finalResault)
{
    start_timer();
    stringsElaboration(toModify, finalResault);

    nrighe = (int)strlen(toModify) + 1;
    ncolonne = (int)strlen(finalResault) + 1;
    
    int ** matrix = initMatrix(nrighe, ncolonne);
    if(nrighe == 0 && ncolonne == 0)
    {
        stop_timer();
        return 0;
    }
    fillMatrix(matrix, toModify, finalResault);
    //pmatrix(matrix);
    stop_timer();
    freeMat(nrighe, matrix);
    return matrix[nrighe][ncolonne];
}

MaxHeap * levensthein_distance_out(char * toModify, char * finalResault)
{
    start_timer();
    stringsElaboration(toModify, finalResault);
    nrighe = (int)strlen(finalResault) + 1;
    ncolonne = (int)strlen(toModify) + 1;
    printf("\nRIGHE: %i\nCOLONNE: %i", nrighe, ncolonne);
    int ** matrix = initMatrix(nrighe, ncolonne);
    if(nrighe == 0 && ncolonne == 0)
    {
        stop_timer();
        return 0;
    }
    fillMatrix(matrix, toModify, finalResault);
    //pmatrix(matrix);
    MaxHeap * hp = findEditPath(matrix, toModify, finalResault);
    stop_timer();
    freeMat(nrighe, matrix);
    return hp;
}

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int** initMatrix()
{
        int **matrix = (int **)malloc(nrighe * sizeof(int *)); 

        for (int i = 0; i < nrighe; ++i)
            matrix[i] = (int *)malloc(ncolonne * sizeof(int)); 




    // int ** matrix = (int**) malloc ((nrighe) * sizeof(int*));

    // for ( int i = 0; i <= nrighe; i++)
    // {
    //     matrix[i] = (int *)malloc((ncolonne) * sizeof(int*));
    // }
    
    for ( int i = 0; i < nrighe; i++)
    {
        matrix[i][0] = i;
    }
    for ( int i = 0; i < ncolonne; i++)
    {
        matrix[0][i] = i;
    }
    return matrix;
}







    // int **mat = malloc(sizeof(int*) * nrighe);
    // if(mat != NULL)
    // for (int i=0; i<nrighe; i++){
    //     mat[i] = malloc(sizeof(int*) * ncolonne);
    // }
    // for(int i=0; i<nrighe; i++){
    //     for(int j=0; j<ncolonne; j++){
    //         mat[i][0]=i;
    //         mat[0][j]=j;
    //     }
    // }
    // //pmatrix(matrix);
    // return mat;
// }

void fillMatrix(int ** matrix, char *toModify, char *finalResault)
{
    int costo = 0;
    for ( int i = 1; i < ncolonne; ++i)
    {
        for ( int j = 1; j < nrighe; ++j)
        {
            if (toModify[i - 1] == finalResault[j - 1])
                costo = 0;
            else
                costo = 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + costo);
            
        }
    }
    printf("\nMatrice fillata\n");
}

MaxHeap * findEditPath(int ** matrix, char * toModify, char * finalResault)
{
    MaxHeap * hp = initStructure(1,0);
    printf("\n\nCAMMINO ISTRUZIONI:\n");
    printf("\n%s   %s", toModify, finalResault);
    recFind(matrix, hp, nrighe-1, ncolonne-1, toModify, finalResault);
    heapPrint(hp);
    printf("\n\n");
    return hp;
}

void recFind(int ** matrix, MaxHeap * hp, int riga, int colonna, char * toModify, char * finalResault)
{   
    printf("\n%s\n%s\n%d\n%d", finalResault, toModify,riga, colonna);
    if (matrix[riga][colonna] != 0)
    {   
        if(riga -1>=  0 && colonna-1>= 0)
        {
        int app = min(matrix[riga][colonna-1],matrix[riga-1][colonna-1],matrix[riga-1][colonna]);
        if(matrix[riga -1 ][colonna - 1] == app)
        {
            // ! SET
            if(matrix[riga][colonna] != matrix[riga-1][colonna-1])
            {
                printf("\n\n\n%c%c%c%c\n\n\n\n", finalResault[riga - 2], finalResault[riga - 1], finalResault[riga], finalResault[riga + 1]);
            pushIstruction(hp, SET, colonna-1, finalResault[riga-1]);
            printf("\nSET%d%c", colonna-1, finalResault[riga-1]);
            }
            recFind(matrix, hp, riga - 1, colonna -1,toModify, finalResault);
        }
        else if (matrix[riga -1][colonna] == app && riga-1 >= 0)
        {
            // ! ADD
            pushIstruction(hp, ADD, riga-1, finalResault[riga-1]);
            printf("\nADD%d%c",riga-1,finalResault[riga-1]);
            recFind(matrix, hp, riga -1, colonna, toModify, finalResault);
        }
        else if(matrix[riga][colonna-1] == app && colonna-1 >= 0)
        {
            // ! DEL
            pushIstruction(hp, DEL, colonna-1,'-');printf("\nDEL%d", colonna-1);
            recFind(matrix, hp, riga, colonna -1, toModify, finalResault);
        }
        
        
        }
        else if (riga - 1 < 0)
        {
            // ! ADD
            pushIstruction(hp, ADD, riga-1, finalResault[riga-1]);
            printf("\nADD%d%c",riga-1,finalResault[riga-1]);
            recFind(matrix, hp, riga -1, colonna, toModify, finalResault);
        }
        else if (colonna - 1 < 0)
        {
            // ! DEL
            pushIstruction(hp, DEL, colonna-1,'-');
            printf("\nDEL%d", colonna-1);
            recFind(matrix, hp, riga, colonna -1, toModify, finalResault);
        }
        else return;
        
        

        
    }
    else return;






    // !! NUOVO RECFIND

    /*
    if(riga - 1 > 0 && colonna - 1 >= 0)
    {
        if(matrix[riga-1][colonna-1] == matrix[riga][colonna])
        {
            
            riga--;
            colonna--;
            printf("\n\nNIENTE\n\n");
            recFind(matrix, hp, riga, colonna, toModify, finalResault);
        }
        
        
    }
    else
    {
            printf("\n\nQUI\n\n");
            if(riga-1 == 0 && colonna-1 == 0)
            return;
            else if (colonna-1 <0)
            {
                //ADD
                printf("\n\nADDLATO\n\n");
                riga--;
                recFind(matrix, hp, riga, colonna, toModify, finalResault);
            }
            else if (riga-1<0)
            {
                //DEL
                printf("\n\nDELLATO\n\n");
                colonna--;
                recFind(matrix, hp, riga, colonna, toModify, finalResault);
            }
            else
            {
                int app = min(matrix[riga][colonna-1],matrix[riga-1][colonna-1],matrix[riga-1][colonna]);
                if(matrix[riga -1][colonna] == app)
                    {
                        //ADD
                        printf("\n\nADD\n\n");
                        riga--;
                        pushIstruction(hp, ADD, riga, toModify[riga]);
                        recFind(matrix, hp, riga, colonna, toModify, finalResault);
                    }
                else if (matrix[riga][colonna - 1] == app)
                    {
                        //DEL
                        printf("\n\nDEL\n\n");
                        pushIstruction(hp, DEL, colonna,'-');
                        colonna--;
                        recFind(matrix, hp, riga, colonna, toModify, finalResault);
                    }
                else
                    {
                        pushIstruction(hp, SET, riga,finalResault[colonna-1]);
                        printf("\n\nSET\n\n");
                        riga--;
                        colonna--;
                        recFind(matrix, hp, riga, colonna, toModify, finalResault);
                        //SET
                    }
            }
    }
    */
    
    



    
    

}

char* create_file_edit(MaxHeap * hp, char * path)
{
    if(hp == NULL)
    return 0;
    return saveToFile(hp, path);
    
}

void stringsElaboration(char * toModify, char * finalResault)
{
    if(toModify[strlen(toModify)-1] != '\0')
    toModify[strlen(toModify)-1] = '\0';
    if(finalResault[strlen(finalResault)-1] != '\0')
    finalResault[strlen(finalResault)-1] = '\0';

    complexityReduction(toModify, finalResault);
    

}

void complexityReduction(char *stringa1, char *stringa2)
{
    if(stringa1[strlen(stringa1)-1] == stringa2[strlen(stringa2)-1])
    {
        stringa1[strlen(stringa1)-1] = 0;
        stringa2[strlen(stringa2)-1] = 0;
        complexityReduction(stringa1, stringa2);
    }
    else return;
}

void freeMat(int size, int** mat){
    for (int i = 0; i<size; i++) {
        free(mat[i]);
    }
    free(mat);
}

void pmatrix(int ** matrix)
{
    printf("\n");
    for ( int i = 0; i < nrighe; i++)
    {
        for ( int j = 0; j < ncolonne; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}