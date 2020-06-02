//
//  time.c
//  filedistance
//
//  Created by Michele on 27/05/2020.
//  Copyright © 2020 Michele. All rights reserved.
//

#include "time.h"

time_t start, end;
double execution_time;

void start_timer(){
    start = clock();
};

void stop_timer(){
        end = clock();
        execution_time = (double)(end - start) / CLOCKS_PER_SEC;
};

double getExecutionTime()
{
    return execution_time;
}
