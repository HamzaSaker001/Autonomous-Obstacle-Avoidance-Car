/*
 * LCD_iterface.h
 *
 * Created: 2/5/2026 2:34:59 PM
 *  Author: hamza
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Macros for shift direction */
#define LCD_SHIFT_LEFT   1
#define LCD_SHIFT_RIGHT  2

/* Macros for line direction */
#define LCD_LINE_1   1 
#define LCD_LINE_2   2

/************************************** APIs Prototypes **************************************/

void LCD_voidINIT();
void LCD_voidDisplayChar(u8 copy_u8Data);
void LCD_voidSendCommand(u8 copy_u8cmnd);

void LCD_voidDisplayString(u8* pu8String);
void LCD_voidClear(void);
void LCD_voidShift(u8 copy_u8ShifttingDirection);
void LCD_voidgoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position);
void LCD_voidGoToStartPosition(void);

#endif /* LCD_INTERFACE_H_ */