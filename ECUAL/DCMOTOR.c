/*
 * DCMOTOR.c
 *
 * Created: 8/23/2023 8:16:52 PM
 *  Author: dell
 */ 
#include "DCMOTOR.h"
void DC_INIT()
{
	DIO_set_bit_direction('B',1,1);
	DIO_set_bit_direction('B',2,1);
}
void DC_MOVE(u_int8 Duty_cycle,u_int8 direction)
{
	if (direction=='F' || direction=='f')
	{
		DIO_Set_Bit('B',1);
		DIO_CLR_Bit('B',2);
		T0_PCPWMI(Duty_cycle);
	}
	else if (direction=='b' ||direction=='B')
	{
			DIO_Set_Bit('B',1);
			DIO_CLR_Bit('B',0);
			T0_PCPWMI(Duty_cycle);
	}
}