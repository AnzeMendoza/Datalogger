#ifndef NVIC_H
#define NVIC_H

#define ISER ((__RW uint32_t *) 0xe000e100)
#define ISER0	ISER[0]
#define ISER1	ISER[1]

#define ISER_UARTO_ENABLE ISER0 |= (0x1 << 5)

#define ICER ((__RW uint32_t *) 0xe000e180)
#define ICER0	ICER[0]
#define ICER1	ICER[1]

#endif // NVIC_H