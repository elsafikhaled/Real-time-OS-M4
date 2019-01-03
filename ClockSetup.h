/*
 * ClockSetup.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ELSAFI
 */

#ifndef CLOCKSETUP_H_
#define CLOCKSETUP_H_
#include "data_types.h"

/*Run-Mode Clock Configuration 2 (RCC2)*/

#define RCC2 *((U32_t volatile *)0x400FE070)

/*Raw Interrupt Status (RIS)*/
#define RIS *((U32_t volatile *)0x400FE050)


void System_Clock_PLL(void);

#endif /* CLOCKSETUP_H_ */
