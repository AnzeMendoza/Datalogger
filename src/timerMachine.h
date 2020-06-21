#ifndef TIMER_H
#define TIMER_H

#include "commons.h"

#define NUMBER_TIMERS 2

typedef uint32_t time_t;
typedef uint8_t numberTimer_t;
typedef enum {
    OFF_ALARM,
    ON_ALARM
} stateAlarm_t;

typedef struct {
    time_t time;
    stateAlarm_t alarm;
    void (*callback)(void);
} timerMachine_t;

void timerStart(numberTimer_t numberTimer, time_t timeInSecond, void (*callback)(void));
void timerStop(numberTimer_t numberTimer);
void timerDiscounter(void);
void timerAnalyzer(void);

#endif //TIMER_H
