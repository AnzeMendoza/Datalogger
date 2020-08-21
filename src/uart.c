#include "uart.h"

void initUART0(uint32_t baudrate)
{
    // Enciendo el modulo
    PCONP |= (1 << 3);

    //configuro el clock del fercuencia de mi uart a 25 Mhz.
    PCLKSEL0 & ~(3 << 6);

    // DLAB = 1 lo que me permite acceder al dlm dll
    U0LCR |= 0x80; //b 1000 0000 o (1<<7)

    uint16_t cuenta = (25000000) / (16 * baudrate);

    U0DLM = (uint8_t)(cuenta >> 8);
    U0DLL = (uint8_t)(cuenta);

    setPinsel(TX0, FUNCTION1);
    setPinsel(RX0, FUNCTION1);

    // DLAB = 1
    U0LCR |= 0x00; //b 1000 0000 o (1<<7)

    // 8 bits de datos, 1 de stop, sin paridad
    U0LCR = 0x3;

    //habilitamos las interrupciones que me generara la uart
    U0IER = 0x03;

    //habilito las interrupciones en el ISER.
    ISER_UARTO_ENABLE;
}

void UART0_IRQHandler()
{

    do
    {
        uint8_t iir = U0IIR;
        iir &= 0x07; //solo analizo b2,b1,b0
        switch (iir >> 1) // reviso b2 y b1
        {
        case 0x02:
            RX();
            break;

        case 0x01:
            TX();
            break;

        default:
            break;
        }

    } while (0 == (iir & 1));
}

