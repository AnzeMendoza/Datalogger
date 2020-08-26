#ifndef GPIO_H
#define GPIO_H

#include "commons.h"
#include "pinsel.h"

//Estructura para manejar los GPIOs:
typedef struct
{
	uint32_t	FIODIR;
	uint32_t	RESERVED[3];
	uint32_t 	FIOMASK;
	uint32_t 	FIOPIN;
	uint32_t 	FIOSET;
	uint32_t 	FIOCLR;
} gpio_t;

typedef enum {
	PULL_UP,
	REPEATER,
	AUTOMATIC,
	PULL_DOWN
} pinMode_t;

typedef enum {
	IN_GPIO,
	OUT_GPIO
} directionSelect_t;

typedef enum {
	LOW_GPIO,
	HIGH_GPIO
} statePin_t;

//0x2009C000 : Direccion de inicio de los registros de GPIOs
#define		GPIOs		( ( gpio_t  * ) 0x2009C000 )
//0x4002C040 : Direccion de inicio de los registros de modo de los pines del GPIO

//Registros GPIOs:
#define		GPIO0		GPIOs[0]
#define		GPIO1		GPIOs[1]
#define		GPIO2		GPIOs[2]
#define		GPIO3		GPIOs[3]
#define		GPIO4		GPIOs[4]

#define		FIO0DIR		GPIO0.FIODIR
#define		FIO1DIR		GPIO1.FIODIR
#define		FIO2DIR		GPIO2.FIODIR
#define		FIO3DIR		GPIO3.FIODIR
#define		FIO4DIR		GPIO4.FIODIR

#define		FIO0MASK	GPIO0.FIOMASK
#define		FIO1MASK	GPIO1.FIOMASK
#define		FIO2MASK	GPIO2.FIOMASK
#define		FIO3MASK	GPIO3.FIOMASK
#define		FIO4MASK	GPIO4.FIOMASK

#define		FIO0CLR		GPIO0.FIOCLR
#define		FIO1CLR		GPIO1.FIOCLR
#define		FIO2CLR		GPIO2.FIOCLR
#define		FIO3CLR		GPIO3.FIOCLR
#define		FIO4CLR		GPIO4.FIOCLR

#define		FIO0SET		GPIO0.FIOSET
#define		FIO1SET		GPIO1.FIOSET
#define		FIO2SET		GPIO2.FIOSET
#define		FIO3SET		GPIO3.FIOSET
#define		FIO4SET		GPIO4.FIOSET

#define		FIO0PIN		GPIO0.FIOPIN
#define		FIO1PIN		GPIO1.FIOPIN
#define		FIO2PIN		GPIO2.FIOPIN
#define		FIO3PIN		GPIO3.FIOPIN
#define		FIO4PIN		GPIO4.FIOPIN


void gpioSetPinMode(port_t port, pin_t pin, pinMode_t mode);
void gpioSetDir(port_t port, pin_t pin, directionSelect_t direction);
void gpioSetPin(port_t port, pin_t pin, statePin_t state);
statePin_t gpioGetPin(port_t port, pin_t pin, statePin_t activity);
void gpioTogglePin(port_t port, pin_t pin);
#endif //GPIO_H
