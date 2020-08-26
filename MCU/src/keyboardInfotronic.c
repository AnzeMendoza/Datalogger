#include "keyboardInfotronic.h"

uint8_t codigo_actual;
uint8_t codigo_anterior;
uint8_t codigo_valido;
uint8_t contador;

/*--------------------------------------------------------------*/
codeKey_t teclado_leer_HD()
{
    if (gpioGetPin(SW1, LOW_GPIO))
        return KEY_SW1;
    if (gpioGetPin(SW2, LOW_GPIO))
        return KEY_SW2;
    if (gpioGetPin(SW3, LOW_GPIO))
        return KEY_SW3;
    if (gpioGetPin(SW4, LOW_GPIO))
        return KEY_SW4;
    if (gpioGetPin(SW5, LOW_GPIO))
        return KEY_SW5;

    return NO_KEY;
}
/*--------------------------------------------------------------*/
void teclado_inicializar()
{
    setPinsel(SW1, GPIO);
    gpioSetDir(SW1, IN_GPIO);
    setPinsel(SW2, GPIO);
    gpioSetDir(SW2, IN_GPIO);
    setPinsel(SW3, GPIO);
    gpioSetDir(SW3, IN_GPIO);
    setPinsel(SW4, GPIO);
    gpioSetDir(SW4, IN_GPIO);
    setPinsel(SW5, GPIO);
    gpioSetDir(SW5, IN_GPIO);

    contador = 0;
    codigo_anterior = NO_KEY;
    codigo_valido = NO_KEY;
}

/*--------------------------------------------------------------*/
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
/*--------------------------------------------------------------*/
codeKey_t teclado_leer()
{
    return teclado_pop(codigo_valido);
}
/*--------------------------------------------------------------*/
uint8_t in;
uint8_t out;
codeKey_t buffer[TAMANIO_BUFFER_TECLADO];
/*--------------------------------------------------------------*/
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
/*--------------------------------------------------------------*/
codeKey_t teclado_pop()
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
/*--------------------------------------------------------------*/