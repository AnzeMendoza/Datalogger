#ifndef KEYBOARD_INFOTRONIC_H
#define KEYBOARD_INFOTRONIC_H

#include "commons.h"
#include "gpio.h"
#include "pinsel.h"

#define SW1 2, 10
#define SW2 0, 18
#define SW3 0, 11
#define SW4 2, 13
#define SW5 1, 26

#define CANT_TECLA_VALIDA 35
#define CANT_TECLA_VALIDA_REPETICION 100
#define TAMANIO_BUFFER_TECLADO 100

typedef enum 
{
    NO_KEY,
    KEY_SW1,
    KEY_SW2,
    KEY_SW3,
    KEY_SW4,
    KEY_SW5,
} codeKey_t;

codeKey_t teclado_leer_HD();
void teclado_inicializar();
void teclado_antirebote();
codeKey_t teclado_leer();
void teclado_push(uint8_t codigo);
codeKey_t teclado_pop();
#endif // KEYBOARD_INFOTRONIC_H
