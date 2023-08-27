/*
 * LCD.h
 *
 * Created: 8/21/2023 12:39:21 PM
 *  Author: dell
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#define LCD_CLR 0x01
#define LCD_RET 0x02
#define ENTER_MODE 0x06
#define FUN_SET 0x28
#define CUR_DISP 0x0C
#define RS 0
#define EN 1
void LCD_init();
void LCD_Write_Data(u_int8 value);
void LCD_send_cmd(u_int8 value);
void LCD_EN();
void LCD_set_cursor(u_int8 row,u_int8 col);
void LCD_write_string(u_int8 * arr);
void LCD_CLRR();

#endif /* LCD_H_ */