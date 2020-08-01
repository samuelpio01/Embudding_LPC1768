#include "LCD.h"

	
/* To send a nibble of data to the LCD 
Check if it needs to be sent to cmd or data register
Insert the value
Write nibble on D4 to D7 pins 
Shift the data to higher order 
Falling edge of en. 
Delay
*/
void Lcd_Send_Nibble(uint8_t ui8RS, uint8_t ui8Val)
{
	if( ui8RS == LCD_CMD )
	{
		LCD_COMMAND_PINS->FIOCLR |= BS(LCD_RS);
	}
	else
	{
		LCD_COMMAND_PINS->FIOSET |= BS(LCD_RS);
	}

	LCD_COMMAND_PINS->FIOCLR |= BS(LCD_RW);
	LCD_DATA_PINS->FIOCLR = (BS(LCD_D7)|BS(LCD_D6)|BS(LCD_D5)|BS(LCD_D4));
	LCD_DATA_PINS->FIOSET |= ((uint32_t)ui8Val << 4); 
	LCD_COMMAND_PINS->FIOSET |= BS(LCD_EN);
	Delay(1); 
	LCD_COMMAND_PINS->FIOCLR = BS(LCD_EN);
}

/* Busy flags of LCD can be read at pin 7, hence make it input 
Select the command register
Read data with EN High
Make EN Low
Dake D7 pin as output 
*/
void Lcd_Busy_Wait(void)
{
	LCD_DATA_PINS->FIODIR &= ~BS(LCD_D7);
	LCD_COMMAND_PINS->FIOCLR = BS(LCD_RS);
	LCD_COMMAND_PINS->FIOSET |= (BS(LCD_RW) | BS(LCD_EN));
	while( LCD_DATA_PINS->FIOPIN & BS(LCD_D7) );
	LCD_COMMAND_PINS->FIOCLR = BS(LCD_EN);
	LCD_DATA_PINS->FIODIR |= BS(LCD_D7);
}

/* Accept byte of data from user
Divide the value into two nibble
Send higher nibble first and later lower nibble
Check for busy flag
*/
void Lcd_Send_Byte(uint8_t uiRS, uint8_t ui8Val)
{
	uint8_t high = (uiVal >> 4); 
	uint8_t low = (uiVal & 0x0F); 
	Lcd_Send_Nibble(uiRS, high);
	Lcd_Send_Nibble(uiRS, low);
	Lcd_Busy_Wait();
	Delay(3);
}

/* Initialize the LCD module
Selct the respective GPIO as output/input pins
Clear the lines before use
Set lcd mode/function. 
*/
void lcdinit()
{
	LCD_COMMAND_PINS->FIODIR |= (BS(LCD_RS) | BS(LCD_RW) | BS(LCD_EN));
	LCD_DATA_PINS->FIODIR |= (BS(LCD_D7)|BS(LCD_D6)|BS(LCD_D5)|BS(LCD_D4));
	LCD_COMMAND_PINS->FIOCLR |= (BS(LCD_RS) | BS(LCD_RW) | BS(LCD_EN));
	LCD_DATA_PINS->FIOCLR |= (BS(LCD_D7)|BS(LCD_D6)|BS(LCD_D5)|BS(LCD_D4));	
	Delay(6);
	Lcd_Send_Byte(LCD_CMD, LCD_4_BIT_2_LINE);
	Lcd_Send_Byte(LCD_CMD, LCD_DISP_ON_CURS_OFF);
	Lcd_Send_Byte(LCD_CMD, LCD_ENTRY);
}

/*
Generate a delay
*/
void Delay(uint32_t uiCount)
{
	volatile int iLoopIterator1, iLoopIterator2;
	for(iLoopIterator2=0;iLoopIterator2<count;iLoopIterator2++)
	{
		for(iLoopIterator1=0;iLoopIterator1<6000;iLoopIterator1++)
		{
			__NOP();
		}
	}
}