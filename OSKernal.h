/*
 * OSKernal.h
 *
 *  Created on: 1/1/2019
 *      Author: ELSAFI
 */

#ifndef KERNALOS_OSKERNAL_H_
#define KERNALOS_OSKERNAL_H_

#include "data_types.h"


/*initialize the OS kERNA "Round Robin"   */
void OS_Kernal_Setup(void);

/*Launch the OS KERNAL with Quanta "Round Robin" */
void OS_Kernal_Launch(U32_t Quanta);

/*Add Threads to the KERNAL.
 *Return value to check adding TASKS  */

U8_t OS_Kernal_CreatThreads(void (*TASK0)(void),//Thread0
                            void (*TASK1)(void),//Thread1
                            void (*TASK2)(void));//Thread2

/* THREADS STACK initialization.
 * parameter is THREAD NUMBER   */

void Thread_Stack_Init(U8_t Thread);





#endif /* KERNALOS_OSKERNAL_H_ */
