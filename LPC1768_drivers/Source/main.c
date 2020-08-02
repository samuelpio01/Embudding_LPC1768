#include<stdio.h>
#include "LPC17xx.h"
#include "lcd.h"

int main()
{
	SystemInit();
	lcd_init();
	lcd_puts(LCD_LINE1, "Prep in progress...");
	lcd_puts(LCD_LINE2, "Sheta todya mare?");
	return 0;
}
