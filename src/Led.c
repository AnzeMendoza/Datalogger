#include <stdio.h>
#include "commons.h"
#include "gpio.h"
#include "pinsel.h"
#include "pll.h"
#include "systick.h"
#include "timerMachine.h"
#include "keyboardInfotronic.h"
#include "uart.h"

void setupLPC(){
	InitPLL();
	SysTickIni();
//	setPinsel(PORT0, PIN22, GPIO);
//	gpioSetDir(PORT0, PIN22, OUT_GPIO);
//	setPinsel(PORT2, PIN10, GPIO);
//	gpioSetDir(PORT2, PIN10, IN_GPIO);
//	teclado_inicializar();
	initUART0(115200);
}

int main(void) {
	setupLPC();
	extern bool_t flag1segundo;

	while (True){
		if(flag1segundo){
			UART0_TX_Datos((uint8_t*)"Hola desde info2\n",0);
			flag1segundo = False;
		}
	};
	return EXIT_SUCCESS;
}
