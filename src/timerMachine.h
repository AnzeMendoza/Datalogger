#ifndef TIMER_H
#define TIMER_H

#include "commons.h"

#define NUMBER_TIMERS 1

typedef struct 
{
    uint32_t Tiempo;
    uint32_t Alarma;
    void (*callback)(void);
} timerMachine_t;

void timerStart(uint32_t numberTimer, uint32_t t, void (*callback)(void));
void timerStop(uint32_t numberTimer);
void timerDiscounter(void);
void timerAnalyzer();

#endif //TIMER_H