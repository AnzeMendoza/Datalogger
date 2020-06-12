#include "systick.h"
/**
	\fn  SysTickIni(void)
	\brief Inicialiazcion de Systick del LPC.
 	\author Anze Mendoza
 	\param [in] void
 	\param [out] void
	\return void
*/
void SysTickIni(void){
	STRELOAD = (STCALIB/4)-1;
	STCURR = 0;
	ENABLE = 1;
	TICKINT = 1;
	CLKSOURCE = 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
	\fn  SysTick_Handler(void)
	\brief ISR del Systick
 	\author Anze Mendoza
 	\param [in] void
 	\param [out] void
	\return void
*/
void SysTick_Handler(void){

    static uint32_t count = 800;

    if (!count){
    	togglePin(PORT0, PIN22);
        count = 800;
    }
    count--;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
