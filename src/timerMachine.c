#include "timerMachine.h"

timerMachine_t timer[NUMBER_TIMERS];

void timerStart(uint32_t numberTimer, uint32_t t, void (*callback)(void)){
    if(numberTimer >= NUMBER_TIMERS)
        return;

    timer[numberTimer].Tiempo = t;
    timer[numberTimer].Alarma = 0;
    timer[numberTimer].callback = callback;
}

void timerStop(uint32_t numberTimer){
    if(numberTimer >= NUMBER_TIMERS)
        return;
    timer[numberTimer].Tiempo = 0;
    timer[numberTimer].Alarma = 0;
    timer[numberTimer].callback = 0;
}

void timerDiscounter(void){ // se va a llamar desde la base de tiempo
    for (uint8_t i = 0; i < NUMBER_TIMERS; i++)
    {
        if (timer[i].Tiempo > 0)
        {
            timer[i].Tiempo--;
            if(timer[i].Tiempo == 0)
                timer[i].Alarma = 1;
        }        
     }
}

void timerAnalyzer(){
    for (uint8_t i = 0; i < NUMBER_TIMERS; i++)
    {
        if (timer[i].Alarma == 1)
        {
            timer[i].Alarma = 0;
            timer[i].callback();
        }
    }
}
