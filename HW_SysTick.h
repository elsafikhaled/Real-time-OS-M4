#ifndef __HW_SYSTICK_H__
#define __HW_SYSTICK_H__

//The SysTick STCTRL register enables the SysTick features.
#define STCTRL   *((volatile U32_t *)  0xE000E010 )
/*
The STRELOAD register specifies the start value to load into the SysTick Current Value
(STCURRENT) register when the counter reaches 0. The start value can be between 0x1 and
0x00FF.FFFF. A start value of 0 is possible but has no effect because the SysTick interrupt and the
COUNT bit are activated when counting from 1 to 0.
SysTick can be configured as a multi-shot timer, repeated over and over, firing every N+1 clock
pulses, where N is any value from 1 to 0x00FF.FFFF. For example, if a tick interrupt is required
every 100 clock pulses, 99 must be written into the RELOAD field.
Note that in order to access this register correctly, the system clock must be faster than 8 MHz.
*/
#define STRELOAD  *((volatile U32_t *) 0xE000E014)
//The STCURRENT register contains the current value of the SysTick counter.
#define STCURRENT *((volatile U32_t *) 0xE000E018)

/*System Handler Priority 3 (SYSPRI3)*/
#define SYSPRI3  *((volatile U32_t *) 0xE000E000)


#endif

