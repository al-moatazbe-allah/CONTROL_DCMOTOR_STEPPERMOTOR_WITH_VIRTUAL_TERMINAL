/*
 * PROJECT.c
 *
 * Created: 8/26/2023 11:21:10 PM
 *  Author: dell
 */ 

#include "DIO.h"
#include "INT.h"
#include "LCD4.h"
#include "timers.h"
#include "UART.h"
#include "DELAYM.h"
#include "DCMOTOR.h"
#include "STEPPER.h"
#define F_CPU 8000000UL
u_int8 hours=0,minutes=0,seconds=0;
u_int8 frame[12];
u_int8 i=0;
void display_time();
int main(void)
{
	
	LCD_init();
	UART_INIT(9600);
	DC_INIT();
	T2_NM_DF_OSC();
	display_time();
	stepper_motor_init();

	while(1)
	{
		

		for(i=0;i<=7;i++)
		{
			frame[i]=UART_REV();
			if (frame[i]=='E'||frame[i]=='e')
			{
				break;
			}
		}
		if (i==7)
		{
			
			if (frame[0]=='1'||frame[0]=='0')
			{
				if (frame[1]>='0'&&frame[1]<='9')
				{
					if (frame[2]>='0'&&frame[2]<='9')
						{
							if (frame[3]=='f'||frame[3]=='F'||frame[3]=='b'||frame[3]=='B')
							{
											if (frame[4]>='0'&&frame[4]<='4')
											{
													if (frame[5]>='0'||frame[5]<='9')
													{
																if (frame[6]=='l'||frame[6]=='L'||frame[6]=='R'||frame[6]=='r')
																{
																		if (frame[7]=='E'||frame[7]=='e')
																		{
																							DISPLAY_RES();
																							DC_MOVE((frame[0]-'0')*100+(frame[1]-'0')*10+frame[2]-'0', frame[3]);
																							change_direction((frame[4]-'0')*10+frame[5]-'0',frame[6]);
																							
																		}
																}
													}
											}
							}
						}
				}

		}
			
			
		}

	
	}
	
}


ISR(T2_OVF)
{
	seconds++;
	if (seconds==60)
	{
		minutes++;
		seconds=0;
	}
	if (minutes==60)
	{
		hours++;
		minutes=0;
	}
	display_time();
}
void display_time()
{
	u_int8 arr[]="time: ";
	LCD_set_cursor(1, 14);
	LCD_write_string(arr);
	LCD_Write_Data((hours/10+'0'));
	LCD_Write_Data((hours%10+'0'));
	LCD_Write_Data(':');
	LCD_Write_Data((minutes/10+'0'));
	LCD_Write_Data((minutes%10+'0'));
	LCD_Write_Data(':');
	LCD_Write_Data((seconds/10+'0'));
	LCD_Write_Data((seconds%10+'0'));
	LCD_Write_Data('A');
	LCD_Write_Data('M');
	
}
void DISPLAY_RES()
{
	cli();
	u_int8 arr1[]="speed: ";
	u_int8 arr2[]="angle: ";
	LCD_set_cursor(0,14);
	LCD_write_string(arr1);
	LCD_Write_Data(frame[0]);
	LCD_Write_Data(frame[1]);
	LCD_Write_Data(frame[2]);
	LCD_Write_Data('%');
	LCD_Write_Data(' ');
	LCD_write_string(arr2);
	if(frame[6]=='L'||frame[6]=='l')
	{
		LCD_Write_Data('-');
		LCD_Write_Data(frame[4]);
		LCD_Write_Data(frame[5]);
	}
	else
	{
		LCD_Write_Data(frame[4]);
		LCD_Write_Data(frame[5]);
	}
	sei();
}