/*
 * LCD_private.h
 *
 * Created: 2/5/2026 2:35:18 PM
 *  Author: hamza
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


static void PRV_voidEnableTriggerWrite(void);

/*optins of LCD Mode
1-4-Bit Mode
2-*-bit mode
*/

#define LCD_8_BIT_MODE  1
#define LCD_4_BIT_MODE  2


#define LCD_MODE   LCD_4_BIT_MODE

/* Macros for Data Port &Pins 4-bit */

#define LCD_D4_PORT   DIO_PORTA
#define LCD_D4_PIN    DIO_PIN4

#define LCD_D5_PORT   DIO_PORTA   
#define LCD_D5_PIN    DIO_PIN5

#define LCD_D6_PORT   DIO_PORTA
#define LCD_D6_PIN    DIO_PIN6

#define LCD_D7_PORT   DIO_PORTA
#define LCD_D7_PIN    DIO_PIN7

#endif /* LCD_PRIVATE_H_ */