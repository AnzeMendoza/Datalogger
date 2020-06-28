#include <stdio.h>
#include "commons.h"
#include "gpio.h"
#include "pinsel.h"
#include "pll.h"
#include "systick.h"
#include "timerMachine.h"

void setupLPC(){
	InitPLL();
	SysTickIni();
	setPinsel(PORT0, PIN22, GPIO);
	gpioSetDir(PORT0, PIN22, OUT_GPIO);
	setPinsel(PORT2, PIN10, GPIO);
	gpioSetDir(PORT2, PIN10, IN_GPIO);
}
void f();

int main(void) {
	setupLPC();
	//timerStart(0, 5, f);
	
	//timerStart(1, 10, f);
	while (True){
		//timerAnalyzer();
		if(gpioGetPin(PORT2, PIN10, LOW_GPIO))
			printf("Entra al if\n");
	};
	return 0 ;
}

void f(){
	gpioTogglePin(PORT0, PIN22);
	printf("pase por f\n");
	timerStop(1);
}
