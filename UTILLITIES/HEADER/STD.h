/*
 * STD.h
 *
 * Created: 8/7/2023 3:45:57 PM
 *  Author: dell
 */ 


#ifndef STD_H_
#define STD_H_
typedef  unsigned char u_int8;
typedef  unsigned int u_int16;

#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define SET_BIT(reg,bit)  reg|=(1<<bit)
#define CLR_BIT(reg,bit)  reg&= (~(1<<bit))
#define TOGGLE_BIT(reg,bit) reg^= (1<<bit)
#define IS_BIT_SET(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit) !((reg&(1<<bit))>>bit)
/*------------DIO Registers------------------*/


#define MYPORTA *((volatile u_int8*)(0x3B))
#define MYDDRA *((volatile u_int8*)(0x3A))
#define MYPINA *((volatile u_int8*)(0x39))
#define MYPORTB *((volatile u_int8*)(0x38))
#define MYDDRB *((volatile u_int8*)(0x37))
#define MYPINB *((volatile u_int8*)(0x36))
#define MYPORTC *((volatile u_int8*)(0x35))
#define MYDDRC *((volatile u_int8*)(0x34))
#define MYPINC *((volatile u_int8*)(0x33))
#define MYPORTD *((volatile u_int8*)(0x32))
#define MYDDRD *((volatile u_int8*)(0x31))
#define MYPIND *((volatile u_int8*)(0x30))
/*------------------------------------------------------------------------
external interrupts registers*/

#define MCUCR *((volatile u_int8 *)(0X55))
#define  MCUSCR *((volatile u_int8*)(0x54))
#define GIFR *((volatile u_int8*)(0x5A))
#define GICR *((volatile u_int8*)(0x5B))
#define  SREG *((volatile u_int8*)(0x5F))
/*-----------------------------------------------*/
   /*EEPROM REGISTERS*/
#define EEARH *((volatile u_int8*)(0x3F))
#define EEARL *((volatile u_int8*)(0x3E))
#define EEDR *((volatile u_int8*)(0x3D))
#define EECR *((volatile u_int8*)(0x3C))
#define SPMCR *((volatile u_int8*)(0x57)) 

/*----------------------------------------------*/
	/*timer registers*/
#define TCCR0 *((volatile u_int8*)(0x53))
#define TCNT0 *((volatile u_int8*)(0X52))
#define OCR0 *((volatile u_int8*)(0X5C))
#define TIMSK *((volatile u_int8*)(0X59))
#define TIFR *((volatile u_int8*)(0X58))
#define TCCR2 *((volatile u_int8*)(0x45))
#define TCNT2 *((volatile u_int8*)(0X44))
#define OCR2 *((volatile u_int8*)(0X43))
#define TCCR1B *((volatile u_int8*)(0x4E))
#define TCCR1A *((volatile u_int8*)(0x4F))
#define ICRL1 *((volatile u_int8*)(0X46))
#define ICRH1 *((volatile u_int8*)(0X47))
#define OCR1BL *((volatile u_int8*)(0x48))
#define OCR1BH *((volatile u_int8*)(0X49))
#define OCR1AL *((volatile u_int8*)(0X4A))
#define OCR1AH *((volatile u_int8*)(0x4B))
#define TCNT1L *((volatile u_int8*)(0X4C))
#define TCNT1H *((volatile u_int8*)(0X4D))
#define ASSR *((volatile u_int8*)(0x42))

/*---------------------------------------------*/
/*UART_REG*/
#define UCSRC *((volatile u_int8*)(0X40))
#define UBRRH *((volatile u_int8*)(0X40)) 
#define UDR *((volatile u_int8*)(0X2C))
#define UCSRA *((volatile u_int8*)(0X2B))
#define UCSRB *((volatile u_int8*)(0X2A))
#define UBRRL *((volatile u_int8*)(0X29))
#define SREG *((volatile u_int8*)(0X5F))
/*--------------------------------------------------*/
/*ADC*/


#endif /* STD_H_ */