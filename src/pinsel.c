#include "pinsel.h"

/**
	\fn setPinsel( uint8_t puerto, uint8_t pin, uint8_t funcionamiento)
	\brief Elije la funcionalidad del pin.
 	\author Anze
 	\param [in] puerto Numero del puerto seleccionado
 	\param [in] bit Numero del bit seleccionado
 	\param [in] modo Selecciona entre los 4 modos de funcionamiento
	\return void
*/
void setPinsel(port_t port, pin_t pin, functionSelect_t function){
    PINSEL[port*2 + pin/16] &= ~(0x3<<((pin%16)*2));
    PINSEL[port*2 + pin/16] |= (function<<((pin%16)*2));
}
