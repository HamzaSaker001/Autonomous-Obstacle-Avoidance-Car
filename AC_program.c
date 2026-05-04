/*
 * AC_program.c
 *
 * Created: 2/27/2026 11:14:37 PM
 *  Author: hamza
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL Drivers */
#include "SRVM_interface.h"
#include "DCM_interface.h"
#include "DCM_config.h"
#include "LCD_interface.h"
#include "ULTRASONIC_interface.h"   

#include "AC_interface.h"
#include "AC_config.h"

/* Servo scanning */
static void AC_voidSetServoAngle(u8 angle)
{
	SRVM_voidOn(angle);      
	_delay_ms(150);
}

/* Initialization */
void AC_voidInit(void)
{
	/* Motors */
	DCM_voidInitWithCtrlSpeed(DCM_MOTOR_A);
	DCM_voidInitWithCtrlSpeed(DCM_MOTOR_B);

	/* Servo */
	SRVM_voidInit();

	/* Ultrasonic module Init */
	HULTRASONIC_voidInit();

	/* LCD */
	LCD_voidINIT();
}

/* Main update loop */
void AC_voidUpdate(void)
{
	u16 distFront, distRight, distLeft;
	
	LCD_voidClear();

	/* Front scan */
	AC_voidSetServoAngle(90);
	distFront = HULTRASONIC_u16GetDistance();  

	if(distFront > 25)
	{
		DCM_voidOnWithCtrlSpeed(DCM_MOTOR_A, DCM_CW, 70);
		DCM_voidOnWithCtrlSpeed(DCM_MOTOR_B, DCM_CW, 70);
		LCD_voidDisplayString((u8*)"FORWARD");
	}
	else
	{
		DCM_voidOffWithCtrlSpeed(DCM_MOTOR_A);
		DCM_voidOffWithCtrlSpeed(DCM_MOTOR_B);

		/* Right scan */
		AC_voidSetServoAngle(0);
		distRight = HULTRASONIC_u16GetDistance();

		/* Left scan */
		AC_voidSetServoAngle(180);
		distLeft = HULTRASONIC_u16GetDistance();

		/* Choose direction */
		if(distRight >= distLeft)
		{
			DCM_voidOnWithCtrlSpeed(DCM_MOTOR_A, DCM_CW, 70);
			DCM_voidOnWithCtrlSpeed(DCM_MOTOR_B, DCM_CCW, 70);
			LCD_voidDisplayString((u8*)"RIGHT");
		}
		else if(distRight <= distLeft)
		{
			DCM_voidOnWithCtrlSpeed(DCM_MOTOR_A, DCM_CCW, 70);
			DCM_voidOnWithCtrlSpeed(DCM_MOTOR_B, DCM_CW, 70);
			LCD_voidDisplayString((u8*)"LEFT");
		}
	}
}