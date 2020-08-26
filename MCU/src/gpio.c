#include "gpio.h"

void gpioSetPinMode(port_t port, pin_t pin, pinMode_t mode){
    PINSEL[port*2 + pin/16] &= ~(mode<<((pin%16)*2));
    PINSEL[port*2 + pin/16] |= (mode<<((pin%16)*2));
}

void gpioSetDir(port_t port, pin_t pin, directionSelect_t direction){
    if(!direction)
        GPIOs[port].FIODIR &= ~(HIGH_GPIO<<pin);
    else
        GPIOs[port].FIODIR |= (HIGH_GPIO<<pin);
}

void gpioSetPin(port_t port, pin_t pin, statePin_t state){
    if(state)
        GPIOs[port].FIOSET = (HIGH_GPIO<<pin);
    else
    	GPIOs[port].FIOCLR = (HIGH_GPIO<<pin);
}

statePin_t gpioGetPin(port_t port, pin_t pin, statePin_t activity){
    statePin_t currentState = (statePin_t)((GPIOs[port].FIOPIN >> pin) & HIGH_GPIO);
    return (activity? currentState : !currentState );
}

void gpioTogglePin(port_t port, pin_t pin){
    gpioSetPin(port, pin, !gpioGetPin(port,pin, HIGH_GPIO));
}
