#ifndef UART_H
#define UART_H

#include "pll.h"
#include "pinsel.h"
#include "nvic.h"
#include <string.h>

//0x4000C000 : Registro de recepcion de la UART0:
#define UART0	((__RW uint32_t *) 0x4000C000)

#define U0RBR	UART0[0]	//Reciever Buffer Register (DLAB=0)
#define U0DLL	UART0[0]	//Divisor Latch LSB (ajuste de baudrate) (DLAB=1)
#define U0THR	UART0[0]	//Transmitter holding register (DLAB=0)
#define U0DLM	UART0[1]	//Divisor Latch MSB (ajuste de baudrate) (DLAB=1)
#define U0IER	UART0[1]	//Interrupt Enable Register (enable de interrupciones) (DLAB=0)
#define U0IIR	UART0[2]	//Interrupt ID Register (identifica interrupcion)
#define U0LCR	UART0[3]	//Line Control Register
#define U0LSR	UART0[5]	//Line Status Register

//Macros UART0
#define		U0DLAB_OFF	(U0LCR & 0xEF)	//DLAB=0
#define		U0DLAB_ON	(U0LCR | 0x80)	//DLAB=1

//0x40010000UL : Registro de recepcion de la UART1:
#define		UART1		( ( __RW uint32_t  * ) 0x40010000 )

#define		U1RBR		UART1[0]
#define		U1THR		UART1[0]
#define		U1DLL		UART1[0]
#define		U1IER		UART1[1]
#define		U1DLM		UART1[1]
#define		U1IIR		UART1[2]
#define		U1LCR		UART1[3]
#define		U1LSR		UART1[5]

//Comunicación serie
#define 	TX0			0,2	//Tx de la UART0
#define 	RX0			0,3	//Rx de la UART0
#define		TX1			0,15
#define		RX1			0,16

//driver
void initUART0();
void UART0_IRQHandler();
void UART0_RX();
void UART0_TX();

//primitivas
void UART0_TX_byte(uint8_t data);
int16_t popTx();
void UART0_TX_Datos(uint8_t *datos, uint32_t size);

#endif //UART_H
