/*
 * INT.h
 *
 * Created: 8/19/2023 7:12:48 PM
 *  Author: dell
 */ 


#ifndef INT_H_
#define INT_H_
#include "STD.h"
#define  ext_0 __vector_1
#define  ext_1 __vector_2
#define  ext_2 __vector_3
#define	 T2_OVF __vector_5

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#define sei() asm("sei")
#define cli() asm("cli")

void EXTERNAL_1();
void EXTERNAL_2();
void EXTERNAL_3();
#endif /* INT_H_ */