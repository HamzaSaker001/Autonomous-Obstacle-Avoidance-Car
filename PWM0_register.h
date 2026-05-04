/*
 * PWM_register.h
 *
 * Created: 2/12/2026 9:34:53 AM
 *  Author: hamza
 */ 


#ifndef PWM0_REGISTER_H_
#define PWM0_REGISTER_H_

#define TCCR0_REG			(*(volatile u8*)0x53)
#define FOC0                7
#define WGM00               6
#define COM01               5
#define COM00               4
#define WGM01               3
#define CS02                2
#define CS01                1
#define CS00                0

#define TCNT0_REG			(*(volatile u8*)0x52)

#define OCR0_REG			(*(volatile u8*)0x5C)

#define TIMSK_REG			(*(volatile u8*)0x59)
#define OCIE0               1
#define TOIE0               0

#define TIFR_REG			(*(volatile u8*)0x58)
#define OCF0                1
#define TOV0                0



#endif /* PWM_REGISTER_H_ */