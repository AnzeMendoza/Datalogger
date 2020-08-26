#include "keyboard.h"

uint8_t teclado_leer_HD()
{
    // fila 1
    gpioSetPin(PIN_FILA_0, HIGH_GPIO);
    gpioSetPin(PIN_FILA_1, LOW_GPIO);
    gpioSetPin(PIN_FILA_2, HIGH_GPIO);
    gpioSetPin(PIN_FILA_3, HIGH_GPIO);

    if (gpioGetPin(PIN_COLUMNA_0, LOW_GPIO))
        return CODIGO_1;
    if (gpioGetPin(PIN_COLUMNA_1, LOW_GPIO))
        return CODIGO_2;
    if (gpioGetPin(PIN_COLUMNA_2, LOW_GPIO))
        return CODIGO_3;

    // fila 2
    gpioSetPin(PIN_FILA_0, HIGH_GPIO);
    gpioSetPin(PIN_FILA_1, LOW_GPIO);
    gpioSetPin(PIN_FILA_2, HIGH_GPIO);
    gpioSetPin(PIN_FILA_3, HIGH_GPIO);

    if (gpioGetPin(PIN_COLUMNA_0, LOW_GPIO))
        return CODIGO_4;
    if (gpioGetPin(PIN_COLUMNA_1, LOW_GPIO))
        return CODIGO_5;
    if (gpioGetPin(PIN_COLUMNA_2, LOW_GPIO))
        return CODIGO_6;

    // fila 3
    gpioSetPin(PIN_FILA_0, HIGH_GPIO);
    gpioSetPin(PIN_FILA_1, LOW_GPIO);
    gpioSetPin(PIN_FILA_2, HIGH_GPIO);
    gpioSetPin(PIN_FILA_3, HIGH_GPIO);

    if (gpioGetPin(PIN_COLUMNA_0, LOW_GPIO))
        return CODIGO_7;
    if (gpioGetPin(PIN_COLUMNA_1, LOW_GPIO))
        return CODIGO_8;
    if (gpioGetPin(PIN_COLUMNA_2, LOW_GPIO))
        return CODIGO_9;

    // fila 4
    gpioSetPin(PIN_FILA_0, HIGH_GPIO);
    gpioSetPin(PIN_FILA_1, LOW_GPIO);
    gpioSetPin(PIN_FILA_2, HIGH_GPIO);
    gpioSetPin(PIN_FILA_3, HIGH_GPIO);

    if (gpioGetPin(PIN_COLUMNA_0, LOW_GPIO))
        return CODIGO_NUM;
    if (gpioGetPin(PIN_COLUMNA_1, LOW_GPIO))
        return CODIGO_0;
    if (gpioGetPin(PIN_COLUMNA_2, LOW_GPIO))
        return CODIGO_AST;

    return NO_KEY;
}

uint8_t codigo_actual;
uint8_t codigo_anterior;
uint8_t codigo_valido;
uint8_t contador;

void teclado_inicializar()
{
    contador = 0;
    codigo_anterior = NO_KEY;
    codigo_valido = NO_KEY;
}

void teclado_antirebote()
{
    codigo_actual = teclado_leer_HD();

    if (codigo_actual == NO_KEY)
    {
        contador = 0;
        codigo_anterior = NO_KEY;
        return;
    }

    if (codigo_actual == codigo_anterior)
    {
        if (contador >= CANT_TECLA_VALIDA)
        {
            codigo_valido = codigo_actual;
        }

        if (contador >= CANT_TECLA_VALIDA_REPETICION)
        {
            //codigo_valido = codigo_actual;
            teclado_push(codigo_actual);
            contador -= 50;
        }

        contador++;
    }
    else
    {
        contador = 0;
    }

    codigo_anterior = codigo_actual;
}

uint8_t teclado_leer()
{
    // uint8_t temp = codigo_valido;
    // codigo_valido = NO_KEY;
    return teclado_pop(codigo_valido);
}

uint8_t in;
uint8_t out;
uint8_t buffer[TAMANIO_BUFFER_TECLADO];

void teclado_push(uint8_t codigo)
{
    buffer[in] = codigo;
    in++;

    if (in >= TAMANIO_BUFFER_TECLADO)
    {
        in = 0;
    }

    if (in == out)
    {
        // que la memoria esta llena
    }
}

uint8_t teclado_pop()
{

    uint8_t temp;
    if (in == out)
    {
        return NO_KEY;
    }

    temp = buffer[out];
    out++;

    return temp;

    if (out >= TAMANIO_BUFFER_TECLADO)
    {
        out = 0;
    }
}