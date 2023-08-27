/*
 * DIO.c
 *
 * Created: 8/7/2023 3:41:56 PM
 *  Author: dell
 */  
#include "DIO.h"
void DIO_set_bit_direction(u_int8 port,u_int8 bit,u_int8 value)
{
	if(value==1)
	{
	switch(port){
		case 'a':
		case 'A':
		SET_BIT(MYDDRA,bit);
		break;
		case 'b':
		case 'B':
		SET_BIT(MYDDRB,bit);
		break;
		case 'c':
		case 'C':
		SET_BIT(MYDDRC,bit);
		break;
		case 'd':
		case 'D':
		SET_BIT(MYDDRD,bit);
		break;
		default:
		break;
	}	
	}
	else if(value==0)
	{
		switch(port){
			case 'a':
			case 'A':
			CLR_BIT(MYDDRA,bit);
			break;
			case 'b':
			case 'B':
			CLR_BIT(MYDDRB,bit);
			break;
			case 'c':
			case 'C':
			CLR_BIT(MYDDRC,bit);
			break;
			case 'd':
			case 'D':
			CLR_BIT(MYDDRD,bit);
			break;
			default:
			break;
		}
	
	}
}
void DIO_set_direction( u_int8 port,u_int8 value)
{
switch(port){
	case 'a':
	case 'A':
	MYDDRA =value;
	break;
	case 'b':
	case 'B':
	MYDDRB =value;
	break;
	case 'c':
	case 'C':
	MYDDRC =value;
	break;
	case 'd':
	case 'D':
	MYDDRD =value;
	break;
	default:
	break;	
}
}
u_int8 DIO_get_input(u_int8 port)
{
	u_int8 value;
	switch(port){
	case 'a':
	case 'A':
	value=MYPINA;
	break;
	case 'b':
	case 'B':
	value=MYPINB;
	break;
	case 'c':
	case 'C':
	value=MYPINC;
	break;
	case 'd':
	case 'D':
	value=MYPIND;
	break;
	default:
	break;	
}
return value;	
}
u_int8 DIO_get_bit(u_int8 port,u_int8 bit)
{
u_int8 value;
switch(port){
	case 'a':
	case 'A':
	value=READ_BIT(MYPINA,bit);
	break;
	case 'b':
	case 'B':
	value=READ_BIT(MYPINB,bit);
	break;
	case 'c':
	case 'C':
	value=READ_BIT(MYPINC,bit);
	break;
	case 'd':
	case 'D':
	value=READ_BIT(MYPIND,bit);
	break;
	default:
	break;
}
return value;
}
void DIO_Set_Bit(u_int8 port,u_int8 bit)
{
switch(port){
	case 'a':
	case 'A':
	SET_BIT(MYPORTA,bit);
	break;
	case 'b':
	case 'B':
	SET_BIT(MYPORTB,bit);
	break;
	case 'c':
	case 'C':
	SET_BIT(MYPORTC,bit);
	break;
	case 'd':
	case 'D':
	SET_BIT(MYPORTD,bit);
	break;
	default:
	break;
}
}
void DIO_CLR_Bit(u_int8 port,u_int8 bit)
{
	switch(port){
		case 'a':
		case 'A':
		CLR_BIT(MYPORTA,bit);
		break;
		case 'b':
		case 'B':
		CLR_BIT(MYPORTB,bit);
		break;
		case 'c':
		case 'C':
		CLR_BIT(MYPORTC,bit);
		break;
		case 'd':
		case 'D':
		CLR_BIT(MYPORTD,bit);
		break;
		default:
		break;
	}
}

void DIO_put_out(u_int8 port, u_int8 value)
{
	switch(port){
		case 'a':
		case 'A':
		MYPORTA =value;
		break;
		case 'b':
		case 'B':
		MYPORTB =value;
		break;
		case 'c':
		case 'C':
		MYPORTC =value;
		break;
		case 'd':
		case 'D':
		MYPORTD =value;
		break;
		default:
		break;
	}
	
}

void DIO_toggle(u_int8 port)
{
	switch(port){
		case 'a':
		case 'A':
		MYPORTA ^=0xff;
		break;
		case 'b':
		case 'B':
		MYPORTB ^=0xff;
		break;
		case 'c':
		case 'C':
		MYPORTC ^=0xff;
		break;
		case 'd':
		case 'D':
		MYPORTD ^=0xff;
		break;
		default:
		break;
	}
}
void DIO_toggle_bit(u_int8 port ,u_int8 bit)
{
	switch(port){
		case 'a':
		case 'A':
		TOGGLE_BIT(MYPORTA,bit);
		break;
		case 'b':
		case 'B':
		TOGGLE_BIT(MYPORTB,bit);
		break;
		case 'c':
		case 'C':
		TOGGLE_BIT(MYPORTC,bit);
		break;
		case 'd':
		case 'D':
		TOGGLE_BIT(MYPORTD,bit);
		break;
		default:
		break;
	}
}
void Write_low_nibble(u_int8 port,u_int8 value)
{
	value &= 0x0F;
		switch(port){
			case 'a':
			case 'A':
			MYPORTA |=value;
			break;
			case 'b':
			case 'B':
			MYPORTB |=value;
			break;
			case 'c':
			case 'C':
			MYPORTC |=value;
			break;
			case 'd':
			case 'D':
			MYPORTD |=value;
			break;
			default:
			break;
		}
}
void Write_high_nibble(u_int8 port,u_int8 value)
{
	value &= 0xF0;
	switch(port){
		case 'a':
		case 'A':
		MYPORTA |=value;
		break;
		case 'b':
		case 'B':
		MYPORTB |=value;
		break;
		case 'c':
		case 'C':
		MYPORTC |=value;
		break;
		case 'd':
		case 'D':
		MYPORTD |=value;
		break;
		default:
		break;
	}
}
void write_nibble(u_int8 port,u_int8 start_bit,u_int8 value)
{
	u_int8 cup;
	switch(port){
		case 'a':
		case 'A':
		for (char i=0;i<4;i++)
		{
			DIO_CLR_Bit(MYPORTA,(start_bit+i));
			cup=READ_BIT(value,i);
			if (cup==1)
			{
				SET_BIT(MYPORTA,(start_bit+i));
			}
			else if (cup==0)
			{
				CLR_BIT(MYPORTA,(start_bit+i));
			}
		}
		break;
		case 'b':
		case 'B':
		for (char i=0;i<4;i++)
		{
			DIO_CLR_Bit(MYPORTB,(start_bit+i));
			cup=READ_BIT(value,i);
			if (cup==1)
			{
				SET_BIT(MYPORTB,(start_bit+i));
			}
			else if (cup==0)
			{
				CLR_BIT(MYPORTB,(start_bit+i));
			}
		}
		break;
		case 'c':
		case 'C':
		for (char i=0;i<4;i++)
		{
			DIO_CLR_Bit(MYPORTC,(start_bit+i));
			cup=READ_BIT(value,i);
			if (cup==1)
			{
				SET_BIT(MYPORTC,(start_bit+i));
			}
			else if (cup==0)
			{
				CLR_BIT(MYPORTC,(start_bit+i));
			}
		}
		break;
		case 'd':
		case 'D':
		for (char i=0;i<4;i++)
		{
			DIO_CLR_Bit(MYPORTD,(start_bit+i));
			cup=READ_BIT(value,i);
			if (cup==1)
			{
				SET_BIT(MYPORTD,(start_bit+i));
			}
			else if (cup==0)
			{
				CLR_BIT(MYPORTD,(start_bit+i));
			}
		}
		break;
		default:
		break;
	}
}