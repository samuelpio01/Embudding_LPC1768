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
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

#define LCD_EN 22
#define LCD_RW 23
#define LCD_RS 24

/* Select LCD registers */
#define LCD_CMD		0
#define LCD_DATA	1

/* LCD Modes */
#define LCD_MODE_1	0x30 // 8 bit and 1 line
#define LCD_MODE_2	0x38 // 8 bit and 2 lines
#define LCD_MODE_3	0x20 // 4 bit and 1 line
#define LCD_MODE_4	0x2C // 4 bit and 2 lines

/* Cursor and display mode */
#define LCD_DISP_CURS_1		0x08 // display off, cursor off
#define LCD_DISP_CURS_2		0x0C // display on, cursor off
#define LCD_DISP_CURS_3		0x0E // display on, cursor on
#define LCD_DISP_CURS_4		0x0F // display on, cursor blinking


#define LCD_CLEAR		0x01 //clears the display
#define LCD_ENTRY		0x06 //Entry mode, accepts each character and prints
#define LCD_LEFTSHIFT	0x18 //shift entire dislay left
#define LCD_RIGHTSHIFT	0x1C //shift entire dislay right

#define LCD_ONE_LEFTSHIFT	 10 //move one character left
#define LCD_ONE_RIGHTSHIFT	 14 //move one character right

#define LCD_START_LINE_1 80 //Force cursor to beggining of 1st line
#define LCD_START_LINE_2 C0 //Force cursor to beggining of 2nd line

void lcd_send_nibble(uint8_t ui8RS, uint8_t ui8Val);
void lcd_busy_wait(void);
void lcd_send_byte(uint8_t uiRS, uint8_t ui8Val);
void sw_delay(uint32_t count);
void lcdinit(void);