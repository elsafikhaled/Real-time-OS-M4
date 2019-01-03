/*
 * ClockSetup.c
 *
 *  Created on: 2/1/2019
 *      Author: ELSAFI
 */
#include "ClockSetup.h"


void System_Clock_PLL(void){/* System_Clock_PLL*/
//use RCC2.
RCC2|=(U32_t)(1<<31);
/*The system clock is derived from the OSC source and divided
by the divisor specified by SYSDIV2.*/
RCC2|=(1<<11);
//select Main oscillator.
RCC2&=~((1<<4)|(1<<5)|(1<<6));
//The PLL operates normally.disable power down.and The USB PLL operates normally.
RCC2&=~((1<<13)|(1<<14));
//choose divisor.
RCC2|=(0x3<<24);
//set PLL up to 400mhz.
RCC2|=(1<<30);
/*The PLL timer has reached TREADY indicating that sufficient time
has passed for the PLL to lock.*/
while((RIS&(1<<6))==0){
      //Waiting.
    }
//clear bypass.
RCC2&=~(1<<11);

}/* System_Clock_PLL*/

