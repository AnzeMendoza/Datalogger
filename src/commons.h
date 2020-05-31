#ifndef COMMONS_H
#define COMMONS_H

typedef unsigned int uint32_t;
typedef unsigned int uint16_t;
typedef unsigned int uint8_t;

#define SALIDA      1
#define ENTRADA     0

#define ON          1
#define OFF         0

#define LOW         0
#define HIGH        1

#define CLOSE       0
#define OPEN        1

typedef enum{
    PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7,
    PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15,
    PIN16, PIN17, PIN18, PIN19, PIN20, PIN21, PIN22, PIN23,
    PIN24, PIN25, PIN26, PIN27, PIN28, PIN29, PIN30, PIN31,
}pin_t;

typedef enum{
    False,
    True
} bool_t;
#endif  // COMMONS_H
