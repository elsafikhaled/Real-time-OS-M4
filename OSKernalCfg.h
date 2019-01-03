/*
 * OSKernalCfg.h
 *
 *  Created on: 1/1/2019
 *      Author: ELSAFI
 */

#ifndef KERNALOS_OSKERNALCFG_H_
#define KERNALOS_OSKERNALCFG_H_

//OS KERNAL Configuration.

#define THREADS_NUMBER      3
#define STACK_SIZE          100 //400byte foe each thread 100*Word.
#define SYSTEM_FREQUENCY    16000000

//Declare a "TCB=Task control Block".

typedef struct TCB{

    U32_t *StackPt;//Stack pointer for each Thread.
    struct TCB *NextTH;//Pointer to the next thread.

}TCB_TYPE;

//declare an array of THreads numbers of structures.each task has its own TCB.

TCB_TYPE TCBS[THREADS_NUMBER];

//declare a Head pointer to the current Thread."GLOBAL VARIABLE"

TCB_TYPE *HeadPT;

//declare an 2 dimension array that has the STACK data for each TASK or THREAD.

U32_t THREAD_STACK[THREADS_NUMBER][STACK_SIZE];

//variable to get load value=(XTAL/1000)*MSEC.,XTAL=(NUMBER OF COUNTS 24BIT/TIME OF TOATAL COUNTS OF 24BIT).
U32_t Mili_prescaler=0;








#endif /* KERNALOS_OSKERNALCFG_H_ */



