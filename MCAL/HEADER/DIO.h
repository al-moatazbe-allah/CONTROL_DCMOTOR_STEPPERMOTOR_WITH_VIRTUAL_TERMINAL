/*
 * DIO.h
 *
 * Created: 8/7/2023 3:42:43 PM
 *  Author: dell
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "STD.h"
void DIO_set_direction( u_int8 port,u_int8 value);
u_int8 DIO_get_input(u_int8 port);
u_int8 DIO_get_bit(u_int8 port,u_int8 bit);
void DIO_Set_Bit(u_int8 port,u_int8 bit);
void DIO_CLR_Bit(u_int8 port,u_int8 bit );
void DIO_put_out(u_int8 port, u_int8 value);
void DIO_toggle(u_int8 port);
void DIO_toggle_bit(u_int8 port ,u_int8 bit);
void Write_low_nibble(u_int8 port,u_int8 value);
void Write_high_nibble(u_int8 port,u_int8 value);
void write_nibble(u_int8 port,u_int8 start_bit,u_int8 value);
void DIO_set_bit_direction(u_int8 port,u_int8 bit,u_int8 value);
#endif /* DIO_H_ */