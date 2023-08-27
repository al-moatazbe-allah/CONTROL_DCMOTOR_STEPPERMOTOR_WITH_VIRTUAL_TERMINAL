/*
 * timers.h
 *
 * Created: 8/21/2023 4:02:12 PM
 *  Author: dell
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
#include "STD.h"
#include "INT.h"
#define AS2 3
enum TIMER_0_CONTROL{CS00=0,CS01,CS02,WGM01,COM00,COM01,WGM00,FOC0};
enum TIMSK_C{TOIE0=0,OCIE0,TOIE1,OCIE1B,OCIE1A,TICIE1,TOIE2,OCIE2};
enum TIFR_C{TOV0=0 ,OCF0,TOV1,OCF1B,OCF1A,ICF1,TOV2,OCF2};
enum TCCR1_A{COM1A1=7,COM1A0=6,COM1B1=5,COM1B0=4,FOC1A=3,FOC1B=2,WGM11=1,WGM10=0};
enum TCCR1_B{ICNC1=7,ICES1=6,RES=5,WGM13=4,WGM12=3,CS12=2,CS11=1,CS10=0};
enum TIMER_2_CONTROL{CS20=0,CS21,CS22,WGM21,COM20,COM21,WGM20,FOC2};	
void T0_NM();
void T0_CTC(u_int8 compare);
void T0_FPWMI(float duty_cycle);
void T0_PCPWMI(float duty_cycle);
void T0_PCPWMI(float duty_cycle);
void T0_FPWMI(float duty_cycle);
void T1_NM();
void T1_CTC(u_int16 compare);
void T1_FPWM(float duty_cycle);
void T1_PCPWM(float duty_cycle);
void T2_NM_DF_OSC();
void T2_CTC(u_int8 compare);
void T2_FPWM(float duty_cycle);
void T2_PCPWM(float duty_cycle);
void ICU();


#endif /* TIMERS_H_ */