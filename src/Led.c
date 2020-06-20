#include <stdio.h>
#include "commons.h"
#include "gpio.h"
#include "pinsel.h"

void setupLPC(){
	setPinsel(PORT0, PIN22, GPIO);
	setDir(PORT0, PIN22, OUT_GPIO);
}

int main(void) {
	setupLPC();

	while (True){
		setPin(PORT0, PIN22, LOW_GPIO);
//		printf("%d\n", getPin(PORT0, PIN22,HIGH_GPIO) );
		setPin(PORT0, PIN22, HIGH_GPIO);
//		printf("%d\n", getPin(PORT0, PIN22,HIGH_GPIO) );
	}

	return 0 ;
}
