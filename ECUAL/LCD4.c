/*
 * LCD.c
 *
 * Created: 8/21/2023 12:39:35 PM
 *  Author: dell
 */ 
#include "LCD4.h"
#include "DELAYM.h"

void LCD_init()
{
	delay_ms(200);
	DIO_set_direction('A',0X3F);
	LCD_send_cmd(LCD_RET);
	delay_ms(10);
	LCD_send_cmd(FUN_SET);
	delay_ms(1);
	LCD_send_cmd(CUR_DISP);
	delay_ms(1);
	LCD_send_cmd(LCD_CLR);
	delay_ms(10);
	LCD_send_cmd(ENTER_MODE);
	delay_ms(1);
}

void LCD_Write_Data(u_int8 value)
{
		write_nibble('A',2,value>>4);
		DIO_Set_Bit('A',RS);
		LCD_EN();
		write_nibble('A',2,value);
		DIO_Set_Bit('A',RS);
		LCD_EN();
}

void LCD_send_cmd(u_int8 value)
{
	write_nibble('A',2,value>>4);
	DIO_CLR_Bit('A',RS);
	LCD_EN();
	write_nibble('A',2,value);
	DIO_CLR_Bit('A',RS);
	LCD_EN();
}

void LCD_EN()
{
	DIO_Set_Bit('A',EN);
	delay_ms(2);
	DIO_CLR_Bit('A',EN);
	delay_ms(2);
}

void LCD_set_cursor(u_int8 row, u_int8 col)
{ 
u_int8 ADDRESS=row*64+col+128;
LCD_send_cmd(ADDRESS);
}

void LCD_write_string(u_int8 * arr)
{
u_int8 i=0;
	while ((arr[i]) !='\0')
	{
		LCD_Write_Data(arr[i]);
		i++;
	}
}
LCD_CLRR()
{
	LCD_send_cmd(LCD_CLR);
}
