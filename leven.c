#include "Lib/leven.h"


// ? filem bin? txt?
int minimum(int a, int b, int c);



//TODO ! Modificare tutto sto metodo
//TODO ! Capire leven
//TODO ! Modificare leven per salvare le modifiche
int levensthein_distance(char *x, char *y){
    start_timer();
    int m = strlen(x);
    int n = strlen(y);
    
    register int i, j;
    int distance;
    
    int *prev = malloc((n + 1) * sizeof(int));
    int *curr = malloc((n + 1) * sizeof(int));
    int *tmp = 0;
    
    for(i = 0; i <= n; i++)
        prev[i] = i;

    for(i = 1; i <= m; i++) {
        curr[0] = i;
        for(j = 1; j <= n; j++) {
            if(x[i - 1] != y[j - 1]) {
                int k = minimum(curr[j - 1], prev[j - 1], prev[j]);
                curr[j] = k + 1;
            } else {
                curr[j] = prev[j - 1];
            }
        }

        tmp = prev;
        prev = curr;
        curr = tmp;
        
        memset((void*) curr, 0, sizeof(int) * (n + 1));
    }
    
    distance = prev[n];
    
    free(curr);
    free(prev);
    stop_timer();
    return distance;
}

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int stringCompare(char *x, char *y){
    int distance = levensthein_distance(x, y);
    printf("EDIT DISTANCE: %d \n", distance);
    printf("TIME: %lf sec \n", getExecutionTime());
    return distance;
}

char* create_file_edit(FILE *output)
{

}