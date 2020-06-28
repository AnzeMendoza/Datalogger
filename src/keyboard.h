#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "commons.h"
#include "gpio.h"

#define PIN_FILA_0 0, 0
#define PIN_FILA_1 1, 1
#define PIN_FILA_2 2, 2
#define PIN_FILA_3 3, 3

#define PIN_COLUMNA_0 4, 4
#define PIN_COLUMNA_1 4, 4
#define PIN_COLUMNA_2 4, 4

#define CODIGO_1 1
#define CODIGO_2 2
#define CODIGO_3 3
#define CODIGO_4 4
#define CODIGO_5 5
#define CODIGO_6 6
#define CODIGO_7 7
#define CODIGO_8 8
#define CODIGO_9 9
#define CODIGO_NUM '#'
#define CODIGO_0 0
#define CODIGO_AST '*'
#define NO_KEY 255


#define CANT_TECLA_VALIDA 4
#define CANT_TECLA_VALIDA_REPETICION 100

#define TAMANIO_BUFFER_TECLADO 100

uint8_t teclado_leer_HD();
void teclado_inicializar();
void teclado_antirebote();
uint8_t teclado_leer();
void teclado_push(uint8_t codigo);
uint8_t teclado_pop();
#endif // KEYBOARD_H