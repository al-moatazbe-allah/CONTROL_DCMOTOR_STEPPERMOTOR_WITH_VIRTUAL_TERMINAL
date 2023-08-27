/*
 * UART.c
 *
 * Created: 8/19/2023 6:32:01 PM
 *  Author: dell
 */ 

#include "UART.h"


void UART_INIT(unsigned long baud_rate)
{
	u_int16 UBRR=(F_CPU/(16*baud_rate))-1;
	UBRRH=(u_int8)(UBRR>>8);
	UBRRL=(u_int8)(UBRR);
	
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	UCSRC=(1<<7)|(1<<1)|(1<<2);
}
void UART_SEN(u_int8 data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	UDR=data;
}
u_int8 UART_REV()
{
	while(READ_BIT(UCSRA,RXC)==0);
	return UDR;
}
void UART_STR (u_int8 * arr)
{
	u_int8 i=0;
	while(arr[i] !='\0')
	{
		UART_SEN(arr[i]);
		i++;
	}
}