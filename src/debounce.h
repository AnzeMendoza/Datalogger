#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include "gpio.h"
#include "commons.h"

#define CANT_ENTRADAS_DIGITALES 4
#define ESTADOS_VALIDOS 5

typedef uint8_t stateDebounce_t;
typedef uint8_t countDebounce_t;

typedef struct 
{
    stateDebounce_t actualState;
    stateDebounce_t previousState;
    countDebounce_t count;
    stateDebounce_t validState;
    port_t port;
    pin_t pin;
} digitalInput;

void debounce(void);
stateDebounce_t readFilteredEntry(uint8_t numberInput);

#endif // DEBOUNCE_H