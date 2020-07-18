#inlcude "LCD.h"

int main (void)
{	    			
	SystemInit();	
	lcdinit();
	lcd_send_byte(LCD_CMD, LCD_START_LINE_1); // to cmd register line 1
	lcd_send_byte(LCD_DATA, 'E');  
	lcd_send_byte(LCD_DATA, 'M');
	lcd_send_byte(LCD_DATA, 'B');
	lcd_send_byte(LCD_DATA, 'E');
	lcd_send_byte(LCD_DATA, 'D'); 
	lcd_send_byte(LCD_DATA, 'D');
	lcd_send_byte(LCD_DATA, 'I'); 
	lcd_send_byte(LCD_DATA, 'N'); 
	lcd_send_byte(LCD_DATA, 'G');

	return 0;
}