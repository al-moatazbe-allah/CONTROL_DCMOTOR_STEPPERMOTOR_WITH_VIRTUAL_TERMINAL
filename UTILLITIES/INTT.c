/*
 * .c
 *
 * Created: 8/19/2023 10:11:41 PM
 *  Author: dell
 */ 
#include "INT.h"

void EXTERNAL_1()
{
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	SET_BIT(GICR,6);
	
}
void EXTERNAL_2()
{
SET_BIT(MCUCR,2);
SET_BIT(MCUCR,3);
SET_BIT(GICR,7);
}
void EXTERNAL_3()
{
SET_BIT(MCUSCR,6);
SET_BIT(GICR,5);
}