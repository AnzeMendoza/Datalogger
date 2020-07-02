#include <stdio.h>
#include "commons.h"
#include "gpio.h"
#include "pinsel.h"
#include "pll.h"
#include "systick.h"
#include "timerMachine.h"
#include "keyboardInfotronic.h"

void setupLPC(){
	InitPLL();
	SysTickIni();
	setPinsel(PORT0, PIN22, GPIO);
	gpioSetDir(PORT0, PIN22, OUT_GPIO);
	setPinsel(PORT2, PIN10, GPIO);
	gpioSetDir(PORT2, PIN10, IN_GPIO);
	teclado_inicializar();
}
void f();

int main(void) {
	codeKey_t temp = NO_KEY;
	setupLPC();


	while (True){
		if ( (temp = teclado_leer()) )
			printf("valor de tecla: %d\n", temp);
	};
	return 0 ;
}

void f(){
	gpioTogglePin(PORT0, PIN22);
	printf("pase por f\n");
	timerStop(1);
}
