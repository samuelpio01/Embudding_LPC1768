#ifndef __LCD_H
#define __LCD_H

#include "LPC17xx.h"
#include "stdint.h"

/*
LCD-----ARM Pins ------- Base Board
RS-----	P1.24 -------------P2.16
R/W----	P1.23 -------------P3.4
EN-----	P1.22 -------------P3.8
D4-----	P2.4 --------------P3.3
D5-----	P2.5 --------------P3.5
D6-----	P2.6 --------------P3.6
D7-----	P2.7 --------------P3.7
*/

/* Bit-shift */
#define BS(n) (1<<(n))

#define LCD_DATA_PINS LPC_GPIO2
#define LCD_COMMAND_PINS LPC_GPIO1

#define LCD_D4 4
#define LCD_D5 						5
#define LCD_D6 						6
#define LCD_D7 						7

#define LCD_EN 						22
#define LCD_RW 						23
#define LCD_RS 						24

/* Select LCD registers */
#define LCD_CMD						0
#define LCD_DATA					1

/* LCD Modes */
#define LCD_8_BIT_1_LINE			0x30
#define LCD_8_BIT_2_LINE			0x38
#define LCD_4_BIT_1_LINE			0x20
#define LCD_4_BIT_2_LINE			0x2C

/* Cursor and display mode */
#define LCD_DISP_OFF_CURS_OFF		0x08
#define LCD_DISP_ON_CURS_OFF		0x0C
#define LCD_DISP_ON_CURS_ON			0x0E
#define LCD_DISP_ON_CURS_BLK		0x0F


#define LCD_CLEAR					0x01
#define LCD_ENTRY					0x06
#define LCD_LEFTSHIFT				0x18
#define LCD_RIGHTSHIFT				0x1C

#define LCD_ONE_LEFTSHIFT	 		0x10
#define LCD_ONE_RIGHTSHIFT	 		0x14

#define LCD_START_LINE_1 			0x80
#define LCD_START_LINE_2 			0xC0

void Lcd_Send_Nibble(uint8_t ui8RS, uint8_t ui8Val);
void Lcd_Busy_Wait(void);
void Lcd_Send_Byte(uint8_t uiRS, uint8_t ui8Val);
void Delay(uint32_t uiCount);
void Lcd_Init(void);

#endif