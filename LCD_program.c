/*
 * LCD_program.c
 *
 * Created: 2/5/2026 2:34:39 PM
 *  Author: Hamza
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>


/*UTILES_LIB*/
#include "Bit_Math.h"
#include "STD_types.h"

/*MCAL*/
#include "DIO_interface.h"

/*HAL*/
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

static void PRV_voidEnableTriggerWrite(void)
{
	/* H -> L */
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
}

void LCD_voidINIT()
{
	DIO_voidSetPinDirection(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
	
	#if LCD_MODE==LCD_8_BIT_MODE
	DIO_voidSetPortDirection(LCD_DATA_PORT,DIO_PORT_OUTPUT);
	_delay_ms(40);
	
	/* Function set (2Lines , 5*7 Font) */
	LCD_voidSendCommand(0b00111000);
	_delay_us(45);
	
	#elif LCD_MODE==LCD_4_BIT_MODE
	DIO_voidSetPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);
	_delay_ms(40);
	
	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,0);
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,1);
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,0);
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,0);

    /* Enable */
    PRV_voidEnableTriggerWrite();
	
	/* Function set (2Lines , 5*7 Font) */
	LCD_voidSendCommand(0b00101000);
	_delay_us(45);
	#endif
	/* Display On/Off Control (DisplayOn, Cursor on, Blink on) */
	LCD_voidSendCommand(0b00001111);
	_delay_us(45);
	
	/* Display Clear */
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	
	/* Entry Mode Set (Increment on, Shift off)*/
	LCD_voidSendCommand(0b00000110);
	
}
void LCD_voidDisplayChar(u8 copy_u8Data)

{
	/* set RS pin = 1 (data) */
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	
	#if LCD_MODE==LCD_8_BIT_MODE
	
	/* write bits of Data on data pins */
	DIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Data);
	
	/* Enable */
	PRV_voidEnableTriggerWrite();
	
	#elif LCD_MODE==LCD_4_BIT_MODE
	
	/* write MSB of Data on data pins */
    DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Data,4));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Data,5));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Data,6));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Data,7));
	
	/* Enable */
	PRV_voidEnableTriggerWrite();	
	
	/* write LSB of Data on data pins */
    DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8Data,0));
    DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8Data,1));
    DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8Data,2));
    DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8Data,3));
		
	/* Enable */
	PRV_voidEnableTriggerWrite();	
	#endif
}

void LCD_voidSendCommand(u8 copy_u8cmnd)
{
	/* set RS pin = 0 (command) */
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	
	#if LCD_MODE==LCD_8_BIT_MODE
	
	/* write bits of command on data pins */
	DIO_voidSetPortValue(LCD_DATA_PORT,copy_u8cmnd);
	
	/* Enable */
	PRV_voidEnableTriggerWrite();
	
	#elif LCD_MODE==LCD_4_BIT_MODE
	
	/* write MSB of Data on data pins */
	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8cmnd,4));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8cmnd,5));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8cmnd,6));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8cmnd,7));
	
	/* Enable */
	PRV_voidEnableTriggerWrite();
	
	/* write LSB of Data on data pins */
	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(copy_u8cmnd,0));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(copy_u8cmnd,1));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(copy_u8cmnd,2));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(copy_u8cmnd,3));
	
	/* Enable */
	PRV_voidEnableTriggerWrite();
	#endif	
}

void LCD_voidDisplayString(u8* pu8String)
{
	u8 Local_u8Counter=0;
	while(pu8String[Local_u8Counter] != '\0')
	{
		LCD_voidDisplayChar(pu8String[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void LCD_voidClear(void)
{
	LCD_voidSendCommand(0b00000001);
	_delay_ms(2);
}

void LCD_voidShift(u8 copy_u8ShifttingDirection)
{
	switch (copy_u8ShifttingDirection)
	{
		case LCD_SHIFT_LEFT:
		LCD_voidSendCommand(0b00011000);
		_delay_us(45);	
		break;
		case LCD_SHIFT_RIGHT:
		LCD_voidSendCommand(0b00011100);
		_delay_us(45);
		break;		
	}
}

void LCD_voidgoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position)
{
	switch (copy_u8LineNumber)
	{
		case LCD_LINE_1:
		LCD_voidSendCommand(0b10000000 + copy_u8Position);
		_delay_us(45);
		break;
		case LCD_LINE_2:
		LCD_voidSendCommand(0b11000000 + copy_u8Position);
		_delay_us(45);
		break;
	}
}

void LCD_voidGoToStartPosition(void)
{
	LCD_voidSendCommand(0b00000010);
	_delay_us(45);
}