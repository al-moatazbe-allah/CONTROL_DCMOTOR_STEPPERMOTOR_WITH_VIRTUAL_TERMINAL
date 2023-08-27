/*
 * STEPPER.h
 *
 * Created: 8/26/2023 9:21:01 PM
 *  Author: dell
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_
#include "DIO.h"
#include "DELAYM.h"
void stepper_motor_init();
void set_mode( u_int8 data);
void move_stepper_motor(u_int8 angel,u_int8 direction);
void change_direction (u_int8 angel,u_int8 direction);





#endif /* STEPPER_H_ */