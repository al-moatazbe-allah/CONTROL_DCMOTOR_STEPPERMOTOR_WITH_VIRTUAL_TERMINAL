/*
 * UART.h
 *
 * Created: 8/19/2023 6:31:30 PM
 *  Author: dell
 */ 


#ifndef UART_H_
#define UART_H_

#include "STD.h"
#define F_CPU 8000000UL
enum UCSRA_BITS{MPCM=0,U2X,PE,DOR,FE,UDRE,TXC,RXC};
enum UCSRB_BITS{TXB8=0,RXB8,UCSZ2,TXEN,RXEN,UDRIE,TXCIE,RXCIE};
enum UCSRC_BITS{UCPOL=0,UCSZ0,UCSZ1,USBS,UPM0,UPM1,UMSEL,URSEL=7};
	
	

void UART_INIT(unsigned long baud_rate);
void UART_SEN(u_int8 data);
u_int8 UART_REV();
void UART_STR (u_int8 * arr);



#endif /* UART_H_ */