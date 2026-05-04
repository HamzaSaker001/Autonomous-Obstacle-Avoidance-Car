/*
 * DCM_program.c
 *
 * Created: 2/12/2026 3:03:40 PM
 *  Author: hamza
 */ 


/*UTILES_LIB*/
#include "Bit_Math.h"
#include "STD_types.h"

/*MCAL*/
#include "DIO_interface.h"
#include "PWM0_interface.h"

/*HAL*/
#include "DCM_interface.h"
#include "DCM_config.h"

void DCM_voidInit(u8 copy_u8MotorId)
{
	switch(copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		DIO_voidSetPinDirection(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN1_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN2_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_EN_PORT,DCM_MOTOR_A_EN_PIN,DIO_PIN_OUTPUT);
		break;
		
		case DCM_MOTOR_B:
		DIO_voidSetPinDirection(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN1_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN2_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_EN_PORT,DCM_MOTOR_B_EN_PIN,DIO_PIN_OUTPUT);	
		break;
	}
}

void DCM_voidOn(u8 copy_u8MotorId, u8 copy_u8Dir)
{
	switch(copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		switch(copy_u8Dir)
		{
			case DCM_CW:
			DIO_voidSetPinValue(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN1_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN2_PIN,DIO_PIN_LOW);
			break;
			
			case DCM_CCW:
			DIO_voidSetPinValue(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN2_PIN,DIO_PIN_HIGH);
			break;
		}
		DIO_voidSetPinValue(DCM_MOTOR_A_EN_PORT,DCM_MOTOR_A_EN_PIN,DIO_PIN_HIGH);
		break;
		
		case DCM_MOTOR_B:
		switch(copy_u8Dir)
		{
			case DCM_CW:
			DIO_voidSetPinValue(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN1_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN2_PIN,DIO_PIN_LOW);
			break;
			
			case DCM_CCW:
			DIO_voidSetPinValue(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN2_PIN,DIO_PIN_HIGH);
			break;
		}
		DIO_voidSetPinValue(DCM_MOTOR_B_EN_PORT,DCM_MOTOR_B_EN_PIN,DIO_PIN_HIGH);
		break;
	}
}

void DCM_voidOff(u8 copy_u8MotorId)
{
	switch(copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		DIO_voidSetPinValue(DCM_MOTOR_A_EN_PORT,DCM_MOTOR_A_EN_PIN,DIO_PIN_LOW);
		break;
		
		case DCM_MOTOR_B:
		DIO_voidSetPinValue(DCM_MOTOR_B_EN_PORT,DCM_MOTOR_B_EN_PIN,DIO_PIN_LOW);
		break;
	}
}

void DCM_voidInitWithCtrlSpeed(u8 copy_u8MotorId)
{
	switch(copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		DIO_voidSetPinDirection(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN1_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN2_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_EN_PORT,DCM_MOTOR_A_EN_PIN,DIO_PIN_OUTPUT);
		break;
		
		case DCM_MOTOR_B:
		DIO_voidSetPinDirection(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN1_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN2_PIN,DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_EN_PORT,DCM_MOTOR_B_EN_PIN,DIO_PIN_OUTPUT);
		break;
	}	
	PWM0_voidInit();
}

void DCM_voidOnWithCtrlSpeed(u8 copy_u8MotorId, u8 copy_u8Dir, u8 copy_u8Speed)
{
	switch(copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		switch(copy_u8Dir)
		{
			case DCM_CW:
			DIO_voidSetPinValue(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN1_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN2_PIN,DIO_PIN_LOW);
			break;
			
			case DCM_CCW:
			DIO_voidSetPinValue(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM_MOTOR_A_IN_PORT,DCM_MOTOR_A_IN2_PIN,DIO_PIN_HIGH);
			break;
		}
		PWM0_voidGenrate(copy_u8Speed);
		break;
		
		case DCM_MOTOR_B:
		switch(copy_u8Dir)
		{
			case DCM_CW:
			DIO_voidSetPinValue(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN1_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN2_PIN,DIO_PIN_LOW);
			break;
			
			case DCM_CCW:
			DIO_voidSetPinValue(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM_MOTOR_B_IN_PORT,DCM_MOTOR_B_IN2_PIN,DIO_PIN_HIGH);
			break;
		}
		PWM0_voidGenrate(copy_u8Speed);
		break;
	}	
}

void DCM_voidOffWithCtrlSpeed(u8 copy_u8MotorId)
{
	switch(copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		PWM0_voidStop();
		break;
		
		case DCM_MOTOR_B:
		PWM0_voidStop();
		break;
	}
}
