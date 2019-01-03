/*
 * OSKernal.c
 *
 *  Created on:  1/1/2019
 *      Author: ELSAFI
 */
#include "OSKernal.h"
#include "OSKernalCfg.h"
#include "HW_SysTick.h"

void Thread_Stack_Init(U8_t Thread){/*STACK initialization of Thread */

//Access stack pointer to the top from 84 to zero.
    TCBS[Thread].StackPt = &THREAD_STACK[Thread][STACK_SIZE-16];
/*Access Program status register of processor M4 register bank,Make processor state is THUMB.
 *So set bit24 to 1 and save it in array element. */
    THREAD_STACK[Thread][STACK_SIZE-1]=0x01000000;//PSR register.

}/*STACK initialization of Thread */


U8_t OS_Kernal_CreatThreads(void (*TASK0)(void),
                            void (*TASK1)(void),
                            void (*TASK2)(void)){/*OS_Kernal_CreatThreads*/
//disable interrupt.
    __asm(" CPSID i");
/* Make round robin linked list thread0->thread1->thraed2->thread0*/
   TCBS[0].NextTH=&TCBS[1];
   TCBS[1].NextTH=&TCBS[2];
   TCBS[2].NextTH=&TCBS[0];
/* initialize thread0 stack*/
   Thread_Stack_Init(0);
   /* initialize thread0 PC=thread0 code*/
   THREAD_STACK[0][STACK_SIZE-2]=(U32_t)TASK0;

/* initialize thread1 stack*/
   Thread_Stack_Init(1);
   /* initialize thread1 PC=thread1 code*/
   THREAD_STACK[1][STACK_SIZE-2]=(U32_t)TASK1;

/* initialize thread2 stack*/
   Thread_Stack_Init(2);
   /* initialize thread2 PC=thread2 code*/
   THREAD_STACK[2][STACK_SIZE-2]=(U32_t)TASK2;

//enable interrupt.
    __asm(" CPSIE i");

   return 1;
}/*OS_Kernal_CreatThreads*/


void OS_Kernal_Setup(void){/*OS_Kernal_Setup*/
//disable interrupt.
    __asm(" CPSID i");
Mili_prescaler=SYSTEM_FREQUENCY/1000;

}/*OS_Kernal_Setup*/

void OS_Kernal_Launch(U32_t Quanta){/*OS_Kernal_Launch*/
//start access system tick timer.
    STCTRL=0x00;
    STCURRENT=0x00;
    SYSPRI3=(0xE0000000);//lowest priority=7.
    STRELOAD=Quanta*Mili_prescaler;
//enable system timer and its interrupt.it clocked from system oscillator.
    STCTRL=0x00000007;

}/*OS_Kernal_Launch*/



