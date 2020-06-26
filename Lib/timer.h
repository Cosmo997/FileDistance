#ifndef timer_h
#define timer_h

#include <stdio.h>
#include <time.h>

/**
 * Avvia il timer.
 */
void start_timer(void);

/**
 * Ferma il timer.
 */
void stop_timer(void);

/**
 * Restituisce il tempo misurato dal timer.
 */
double getExecutionTime(void);

#endif
