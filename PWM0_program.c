/*
 * PWM_program.c
 *
 * Created: 2/12/2026 9:13:08 AM
 *  Author: hamza
 */ 

/*UTILES Lib*/
#include "STD_types.h"
#include "Bit_Math.h"

/*MCAL*/
#include "PWM0_interface.h"
#include "PWM0_register.h"



void PWM0_voidInit(void)
{
    #if PWM0_MODE == PWM0_FAST_MODE

	/* Select FAST Mode */
	SET_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);
	
	/* Select non inverting output */
	CLR_BIT(TCCR0_REG, COM00);
	SET_BIT(TCCR0_REG, COM01);

	#elif PWM0_MODE == PWM0_NON_INVERTING_OUTPUT_MODE

	/* Select FAST Mode *
	SET_BIT(TCCR0_REG, WGM00);
	CLR_BIT(TCCR0_REG, WGM01);

	/* Set Preload Value *
	OCR0_REG = TMR0_OUTPUT_COMPARE_VLAUE;

 	/* Enable OC Interrupt	*
	SET_BIT(TIMSK_REG, OCIE0);*/
	#endif
}
	
void PWM0_voidGenrate(u8 copy_u8DutyCycle)
{
	if (copy_u8DutyCycle <= 100)
	{
		/* non inverting output */
		OCR0_REG = ((copy_u8DutyCycle * 256) / 100) - 1;
		
		/* Select Prescaler Value = 64 */
		SET_BIT(TCCR0_REG, CS00);
		SET_BIT(TCCR0_REG, CS01);
		CLR_BIT(TCCR0_REG, CS02);
	} 
	else
	{
		//return error state
	}
}

void PWM0_voidStop(void)
{
	CLR_BIT(TCCR0_REG, CS00);
	CLR_BIT(TCCR0_REG, CS01);
	CLR_BIT(TCCR0_REG, CS02);
}
