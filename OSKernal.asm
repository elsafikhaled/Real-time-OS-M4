           AREA|.text|,CODE,READONLY,ALIGN=2
           THUMB
           EXTERN HeadPT
           IMPORT SysTick_handler
     
     
SysTick_handler              ;Compiler svaed or pushed automatic registers of stack frame R0 to R3 plus R12,PC,LR,XPSR,
   CPSID   I                 ;disable interrupt
   PUSH    {R4-R11}          ;Push registers from R4 to R11.
   LDR     R0,=HeadPT        ;R0 points to current thread.
   LDR     R1,[R0]           ;R1 points to R0 that points to current thread.
   STR     SP,[R1]           ;Save current sp in R1 so now HeadPT has old stack pointer of old thread.
   LDR     R1,[R1,#4]        ;Jumb to the next TCB of next thread.
   LDR     R1,[R0]           ;load HeadPT with new location.
   LDR     SP,[R1]           ;Load stack with new thread location.
   POP     {R4-R11}
   CPSIE   I
   BX LR


