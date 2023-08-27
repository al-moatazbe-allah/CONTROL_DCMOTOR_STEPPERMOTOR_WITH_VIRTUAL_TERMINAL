/*
 * STEPPER.c
 *
 * Created: 8/26/2023 9:19:41 PM
 *  Author: dell
 */ 

#include "STEPPER.h"

void stepper_motor_init()
{
for (u_int8 i=4;i<8;i++)
{
	DIO_set_bit_direction('B',i,1);
	DIO_CLR_Bit('B',i);
}
}
u_int8 current_direction=0, current_index_cw=0, current_angel =0;
u_int8 ClockWise[4]={2,1,4,3};
void set_mode( u_int8 data)
{
	delay_ms(100);
	switch (data)
	{
		case 1:
			DIO_Set_Bit('b',6);
			DIO_Set_Bit('b',7);
			delay_ms(100);
			DIO_CLR_Bit('b',6);
			DIO_CLR_Bit('b',7);
			break;
		case 2:
			DIO_Set_Bit('b',6);
			DIO_Set_Bit('b',5);
			delay_ms(100);
			DIO_CLR_Bit('b',6);
			DIO_CLR_Bit('b',5);
			break;
		case 3:	
			DIO_Set_Bit('b',5);
			DIO_Set_Bit('b',4);
			delay_ms(100);
			DIO_CLR_Bit('b',4);
			DIO_CLR_Bit('b',5);
			
			
	
			break;
		case 4:
		DIO_Set_Bit('b',4);
		DIO_Set_Bit('b',7);
		delay_ms(100);
		DIO_CLR_Bit('b',7);
		DIO_CLR_Bit('b',4);
			
			break;
}
}
void move_stepper_motor(u_int8 angel,u_int8 direction)
{

	u_int8 i;

	if (direction=='R'||direction=='r')
	{
		for (i=0;i<=angel;i++)
		{
			if (current_index_cw==4)
			current_index_cw=0;
			set_mode(ClockWise[current_index_cw]);
			current_index_cw++;
		}

	}
	if  (direction=='L'||direction=='l')
	{
		for (i=0;i<=angel;i++)
		{

			set_mode(ClockWise[current_index_cw]);
			if (!current_index_cw)

				current_index_cw=4;

			current_index_cw--;

		}

	}
	current_direction=direction;
	current_angel=angel;
}

void change_direction (u_int8 angel,u_int8 direction)
{


	if (current_angel==0)
	{
		move_stepper_motor(angel, direction);

	}
	else if (current_direction=='L'||current_direction=='l')
	{

		move_stepper_motor(current_angel+1, 'r');
		delay_ms(1000);
		current_index_cw=0;
		move_stepper_motor(angel, direction);

	} else if (current_direction=='R'||current_direction=='r')
	{
		move_stepper_motor(current_angel+1, 'l');
		delay_ms(1000);

		current_index_cw=0;
		move_stepper_motor(angel, direction);
	}
}