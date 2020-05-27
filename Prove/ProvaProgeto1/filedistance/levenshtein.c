//
//  levenshtein.c
//  filedistance
//
//  Created by Michele on 27/05/2020.
//  Copyright © 2020 Michele. All rights reserved.
//

#include "levenshtein.h"

int levensthein_distance(char *x, char *y){
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
    
    return distance;
}

int minimum(int a, int b, int c) {

/* funzione che calcola il minimo di 3 valori */

    int min = a;

    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

void result(char* file1, char* file2, double time){
    printf("EDIT DISTANCE: %d \n", levensthein_distance(file1, file2));
    printf("TIME: %lf sec \n", time);
}
