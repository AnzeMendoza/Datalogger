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
	setDir(PORT0, PIN22, OUT_GPIO);
}

int main(void) {
	setupLPC();

	while (True){

		timerAnalyzer();
	};
	return 0 ;
}
