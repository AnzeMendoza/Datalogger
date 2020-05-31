#ifndef PINSEL_H
#define PINSEL_H
#include "commons.h"

#define     PINSEL      ((uint32_t *)0x4002C000)
#define     PINMODE     ((uint32_t *)0x4002C040)
#define     PINMODE_OD  ((uint32_t *)0x4002C068)
#define     I2CPADCFG   ((uint32_t *)0x4002C07C)

//Registros PINSEL:
#define     PINSEL0     PINSEL[0]
#define     PINSEL1     PINSEL[1]
#define     PINSEL2     PINSEL[2]
#define     PINSEL3     PINSEL[3]
#define     PINSEL4     PINSEL[4]
#define     PINSEL5     PINSEL[5]
#define     PINSEL6     PINSEL[6]
#define     PINSEL7     PINSEL[7]
#define     PINSEL8     PINSEL[8]
#define      PINSEL9    PINSEL[9]
//Registros PINMODE
#define     PINMODE0    PINMODE[0]
#define     PINMODE1    PINMODE[1]
#define     PINMODE2    PINMODE[2]
#define     PINMODE3    PINMODE[3]
#define     PINMODE4    PINMODE[4]
#define     PINMODE5    PINMODE[5]
#define     PINMODE6    PINMODE[6]
#define     PINMODE7    PINMODE[7]
#define     PINMODE8    PINMODE[8]
#define     PINMODE9    PINMODE[9]

#define     PINMODE_OD0  PINMODE_OD[0]
#define     PINMODE_OD1  PINMODE_OD[1]
#define     PINMODE_OD2  PINMODE_OD[2] 
#define     PINMODE_OD3  PINMODE_OD[3] 
#define     PINMODE_OD4  PINMODE_OD[4] 

#define     I2CPADCFG0 I2CPADCFG[0]

typedef enum{
    PORT0,
    PORT1,
    PORT2,
    PORT3,
    PORT4
} port_t; 

typedef enum{
    GPIO,
    FUNCTION1,
    FUNCTION2,
    FUNCTION3
} functionSelect_t;

void setPinsel(port_t port, pin_t pin, functionSelect_t fuction);

#endif //PINSEL_H