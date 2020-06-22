#include "timerMachine.h"

timerMachine_t timer[NUMBER_TIMERS];

void timerStart(numberTimer_t numberTimer, time_t timeInSecond, void (*callback)(void)){
    if(numberTimer >= NUMBER_TIMERS)
        return;

    timer[numberTimer].time = timeInSecond;
    timer[numberTimer].alarm = OFF_ALARM;
    timer[numberTimer].callback = callback;
}

void timerStop(numberTimer_t numberTimer){
    if(numberTimer >= NUMBER_TIMERS)
        return;
    timer[numberTimer].time = 0;
    timer[numberTimer].alarm = OFF_ALARM;
    timer[numberTimer].callback = 0;
}

void timerDiscounter(void){ // se va a llamar desde la base de time
    for (numberTimer_t i = 0; i < NUMBER_TIMERS; i++)
    {
        if (timer[i].time > 0)
        {
            timer[i].time--;
            if(timer[i].time == 0)
                timer[i].alarm = ON_ALARM;
        }        
     }
}

void timerAnalyzer(void){
    for (numberTimer_t i = 0; i < NUMBER_TIMERS; i++)
    {
        if (timer[i].alarm == ON_ALARM)
        {
            timer[i].alarm = OFF_ALARM;
            timer[i].callback();
        }
    }
}
