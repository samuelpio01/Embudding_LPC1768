#inlcude "LCD.h"

int main (void)
{	    			
	SystemInit();	
	lcdinit();
	lcd_send_byte(0, 0x80); // to cmd register line 1
	lcd_send_byte(1, 'E');  //send H 
	lcd_send_byte(1, 'M');  //send H
	lcd_send_byte(1, 'B');  //send H
	lcd_send_byte(1, 'E');  //send H
	lcd_send_byte(1, 'D');  //send H
	lcd_send_byte(1, 'D');  //send H
	lcd_send_byte(1, 'I');  //send H
	lcd_send_byte(1, 'N');  //send H
	lcd_send_byte(1, 'G');  //send H

	return 0;
}