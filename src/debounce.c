#include "debounce.h"
#include "gpio.h"

#define CANT_ENTRADAS_DIGITALES 4
#define ESTADOS_VALIDOS 5
#define PULSADOR PORT0, PIN23

typedef struct 
{
    uint8_t estado_actual;
    uint8_t estado_anterior;
    uint8_t contador;
    uint8_t estado_valido;
    uint8_t port;
    uint8_t pin;
} digitalInput;

digitalInput input[CANT_ENTRADAS_DIGITALES]; 

void debounce(void)
{

    for (uint8_t i = 0; i < CANT_ENTRADAS_DIGITALES; i++)
    {    
        input[i].estado_actual = getPin(input[i].port, input[i].pin, HIGH_GPIO);
        
        if (input[i].estado_actual == input[i].estado_anterior)
        {
            if (input[i].contador >= ESTADOS_VALIDOS)
            {
                input[i].estado_valido = input[i].estado_actual;
            }
            else
            {
                input[i].contador++;
            }
        }
        else
        {
            input[i].contador = 0;
        }
        input[i].estado_anterior = input[i].estado_actual;
    }
}

uint32_t readFilteredEntry(uint8_t numberInput){
    return input[numberInput].estado_valido;
}