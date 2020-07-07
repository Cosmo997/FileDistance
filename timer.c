#include "Lib/timer.h"
#include <stdio.h>
#include <time.h>

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
