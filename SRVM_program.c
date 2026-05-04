/*
 * SRVM_program.c
 *
 * Created: 2/14/2026 3:40:49 PM
 *  Author: hamza
 */ 

/*UTILES Lib*/
#include "STD_types.h"
#include "Bit_Math.h"

/*MCAL*/
#include "PWM1_interface.h"
#include "DIO_interface.h"

/*HAL*/
#include "SRVM_interface.h"


void SRVM_voidInit()
{
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
	PWM1_voidInitChannel1A();
}

void SRVM_voidOn(u8 copy_u8Angle)
{
	f32 Local_f32Duty = (((1 + (copy_u8Angle/180.0)) * (2-1)) / 20) * 100;
	
	PWM1_voidGenrateChannel1A(50, Local_f32Duty);
}

void SRVM_voidOff()
{
	PWM1_voidStop();
}