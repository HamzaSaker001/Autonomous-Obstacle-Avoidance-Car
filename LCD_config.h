/*
 * LCD.h
 *
 * Created: 2/5/2026 2:35:54 PM
 *  Author: hamza
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* Macros for RS config */
#define LCD_RS_PORT   DIO_PORTB 
#define LCD_RS_PIN    DIO_PIN1

/* Macros for DataPort 8_b */
#define LCD_DATA_PORT  DIO_PORTA

/* Macros for Enable config */
#define LCD_E_PORT   DIO_PORTB
#define LCD_E_PIN    DIO_PIN2


#endif /* LCD_CONFIG_H_ */