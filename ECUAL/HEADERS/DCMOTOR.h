/*
 * DCMOTOR.h
 *
 * Created: 8/23/2023 8:17:08 PM
 *  Author: dell
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "DIO.h"
#include "timers.h"

#define F 1
#define R 0
void DC_INIT();
void DC_MOVE(u_int8 Duty_cycle,u_int8 direction);


#endif /* DCMOTOR_H_ */