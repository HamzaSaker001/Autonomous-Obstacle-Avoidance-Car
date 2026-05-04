/*
 * ULTRASONIC_program.c
 *
 * Created: 2/27/2026 11:43:41 PM
 *  Author: hamza
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"

/* Timer2 Registers */
#define TCCR2_REG   *((volatile u8*)0x45)
#define TCNT2_REG   *((volatile u8*)0x44)
#define TIFR_REG    *((volatile u8*)0x58)

#define TOV2  6
#define CS20  0
#define CS21  1
#define CS22  2

void HULTRASONIC_voidInit(void)
{
	/* Trigger Output */
	DIO_voidSetPinDirection(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_PIN_OUTPUT);

	/* Echo Input */
	DIO_voidSetPinDirection(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, DIO_PIN_INPUT);
}

u16 HULTRASONIC_u16GetDistance(void)
{
	u32 Local_u32Ticks = 0;
	u16 Local_u16Distance = 0;
	u8  Local_u8Overflow = 0;
	u32 Local_u32Timeout = 0;
	u8 Local_u8PinValue;

	/* Send 15us Trigger Pulse */
	DIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_PIN_HIGH);
	_delay_us(15);
	DIO_voidSetPinValue(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, DIO_PIN_LOW);

	/* Wait Rising Edge with timeout */
	DIO_voidGetPinValue(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, &Local_u8PinValue);
	while(Local_u8PinValue == 0)
	{
		Local_u32Timeout++;
		if(Local_u32Timeout > 60000)
		return 0;
		
		
		DIO_voidGetPinValue(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, &Local_u8PinValue);
	}

	/* Reset Timer2 */
	TCNT2_REG = 0;
	Local_u8Overflow = 0;

	/* Start Timer2 Prescaler = 64 */
	SET_BIT(TCCR2_REG, CS20);
	SET_BIT(TCCR2_REG, CS21);
	CLR_BIT(TCCR2_REG, CS22);
	
	/* Measure HIGH Time */
	DIO_voidGetPinValue(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, &Local_u8PinValue);
	while(Local_u8PinValue == 1)
	{
		if(GET_BIT(TIFR_REG, TOV2))
		{
			SET_BIT(TIFR_REG, TOV2);
			Local_u8Overflow++;
		}
		
		
		DIO_voidGetPinValue(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN, &Local_u8PinValue);
	}

	/* Stop Timer */
	CLR_BIT(TCCR2_REG, CS20);
	CLR_BIT(TCCR2_REG, CS21);
	CLR_BIT(TCCR2_REG, CS22);

	/* Calculate total ticks */
	Local_u32Ticks = (Local_u8Overflow * 256UL) + TCNT2_REG;

	/* Convert to cm */
	Local_u16Distance = Local_u32Ticks / 14;

	return Local_u16Distance;
}