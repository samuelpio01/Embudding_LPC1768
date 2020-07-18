#include "LCD.h"

void lcd_send_nibble(uint8_t ui8RS, uint8_t ui8Val)
{
	/* is the value cmd or data*/
	if( ui8RS == 0 )
		LCD_COMMAND_PINS->FIOCLR |= BS(LCD_RS);
	else
		LCD_COMMAND_PINS->FIOSET |= BS(LCD_RS);
	
	/* write data */
	LCD_COMMAND_PINS->FIOCLR |= BS(LCD_RW);
	// write nibble on D4 to D7 pins
	LCD_DATA_PINS->FIOCLR = (BS(LCD_D7)|BS(LCD_D6)|BS(LCD_D5)|BS(LCD_D4));
//		LCD_DATA_PINS->FIOCLR = 0x000000f0; //Alternate Before sending data, clear pins
	LCD_DATA_PINS->FIOSET |= ((uint32_t)uiVal << 4); //shit the data to higher order
	// falling edge of en.
	LCD_COMMAND_PINS->FIOSET |= BS(LCD_EN);
//		LCD_COMMAND_PINS->FIOSET |= 1 << 22; //Alternate
	sw_delay(1); //asm("nop");
	LCD_COMMAND_PINS->FIOCLR = BS(LCD_EN);
//		LCD_COMMAND_PINS->FIOCLR |= 1 << 22; //Alternate
			
}

/* Busy flags of LCD can be read at pin 7, hence make it input */
void lcd_busy_wait(void)
{
	LCD_DATA_PINS->FIODIR &= ~BS(LCD_D7);
//	LCD_DATA_PINS->FIODIR = 0x00000080; //Alternate
	/* Select the command register */
	LCD_COMMAND_PINS->FIOCLR = BS(LCD_RS);
//	LCD_COMMAND_PINS->FIOCLR |= 1 << 24; //Alternate
	/* Read data with EN High */
	LCD_COMMAND_PINS->FIOSET |= (BS(LCD_RW) | BS(LCD_EN));
//	LCD_COMMAND_PINS->FIOSET |= 1 << 23; // Alternate
//	LCD_COMMAND_PINS->FIOSET |= 1 << 22; // Alternate
	while( LCD_DATA_PINS->FIOPIN & BS(LCD_D7) );
	/* Make EN Low*/
	LCD_COMMAND_PINS->FIOCLR = BS(LCD_EN);
//	LCD_COMMAND_PINS->FIOCLR |= 1 << 22; //Alternate
	// make D7 pin as output
	LCD_DATA_PINS->FIODIR |= BS(LCD_D7);
//	LCD_DATA_PINS->FIOSET = 0x00000080; //Alternate
}

void lcd_send_byte(uint8_t uiRS, uint8_t ui8Val)
{
	/* First divide the value into two halves */
	uint8_t high = (uiVal >> 4); //get higher order
	uint8_t low = (uiVal & 0x0F); //and the rest as 1
	lcd_send_nibble(uiRS, high);
	lcd_send_nibble(uiRS, low);
	lcd_busy_wait();
	sw_delay(3);
}

void lcdinit()
{
	/* Make the GPIO output/input */
	LCD_COMMAND_PINS->FIODIR |= (BS(LCD_RS) | BS(LCD_RW) | BS(LCD_EN));
	LCD_DATA_PINS->FIODIR |= (BS(LCD_D7)|BS(LCD_D6)|BS(LCD_D5)|BS(LCD_D4));
	
	/* Alternate Datalines directly
	LCD_COMMAND_PINS->FIODIR = 0x01C00000 // 22,23,24
	LCD_DATA_PINS->FIODIR = 0x000000f0 // 4,5,6,7 pins
	*/
	/* Clear the lines before use*/
	LCD_COMMAND_PINS->FIOCLR |= (BS(LCD_RS) | BS(LCD_RW) | BS(LCD_EN));
	LCD_DATA_PINS->FIOCLR |= (BS(LCD_D7)|BS(LCD_D6)|BS(LCD_D5)|BS(LCD_D4));	
	
	/* Alternate Clear all the pins 
	LCD_COMMAND_PINS->FIOCLR = 0x01c00000; //22,23,24
	LCD_DATA_PINS->FIOCLR = 0x000000f0; //4,5,6,7
	*/
	
	/* 6ms delay*/
	sw_delay(6);
	
	/* set lcd mode/function. */
	lcd_send_byte(LCD_CMD, LCD_MODE_4); //4 bit
	lcd_send_byte(LCD_CMD, LCD_DISP_CURS_2); //dispaly on cursor off
	lcd_send_byte(LCD_CMD, LCD_ENTRY); // entry mode
	
}

void sw_delay(uint32_t count)
{
	volatile int i, j;
	for(j=0;j<count;j++)
	{
		for(i=0;i<6000;i++)
			__NOP();
	}
}