#include "debounce.h"

digitalInput input[CANT_ENTRADAS_DIGITALES]; 

void debounce(void)
{
    for (uint8_t i = 0; i < CANT_ENTRADAS_DIGITALES; i++)
    {    
        input[i].actualState = getPin(input[i].port, input[i].pin, HIGH_GPIO);
        
        if (input[i].actualState == input[i].previousState)
        {
            if (input[i].count >= ESTADOS_VALIDOS)
            {
                input[i].validState = input[i].actualState;
            }
            else
            {
                input[i].count++;
            }
        }
        else
        {
            input[i].count = 0;
        }
        input[i].previousState = input[i].actualState;
    }
}

stateDebounce_t readFilteredEntry(uint8_t numberInput){
    return input[numberInput].validState;
}