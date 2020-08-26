#include "uart.h"

uint8_t dataReceivedInRBR;

#define SIZE_BUFFER_TX 50
uint8_t bufferTx[SIZE_BUFFER_TX];
uint32_t txIn = 0;
uint32_t txOut = 0;
bool_t flagTxEnCurso = True;

void initUART0(uint32_t baudrate)
{
    // Enciendo el modulo
    PCONP |= (1 << 3);

    //configuro el clock del fercuencia de mi uart a 25 Mhz.
    PCLKSEL0 &= ~(3 << 6);

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

// cuando llega un dato Rx o cuando se termina de transmitir Tx
void UART0_IRQHandler()
{
    uint8_t iir;
    do
    {
        iir = U0IIR & 0x07; //solo analizo b2,b1,b0
        switch (iir >> 1)   // reviso b2 y b1
        {
        case 0x02:
            UART0_RX();
            break;
        case 0x01:
            UART0_TX();
            break;
        default:
            break;
        }
    } while (0 == (iir & 1));
}

void UART0_RX()
{
    dataReceivedInRBR = U0RBR;
    printf("%c", (char)dataReceivedInRBR);
}

void UART0_TX_byte(uint8_t data)
{
    bufferTx[txIn] = data;
    txIn++;

    txIn %= SIZE_BUFFER_TX;

    if (flagTxEnCurso)
    {
        U0THR = (uint8_t)popTx();
        flagTxEnCurso = False;
    }
}

int16_t popTx()
{
    uint8_t data;

    if (txIn == txOut)
        return -1;

    data = bufferTx[txOut];
    txOut++;
    txOut %= SIZE_BUFFER_TX;

    return data;
}

void UART0_TX()
{
    int16_t data = popTx();

    if (data >= 0)
        U0THR = (uint8_t)data;
    else
        flagTxEnCurso = True;
}

void UART0_TX_Datos(uint8_t *datos, uint32_t size)
{
    if (size == 0)
        size = strlen((char *)datos);

    for (uint8_t i = 0; i < size; i++)
        UART0_TX_byte(datos[i]);
}
