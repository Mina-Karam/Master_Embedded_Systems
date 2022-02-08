/*
 * main.c
 *
 * Created: 2/8/2022 7:53:45 PM
 *  Author: Mina Karam
 */ 

#include "avr/io.h"
#include "LCD_driver/lcd.h"

int main(void)
{
	LCD_INIT();
	
	LCD_WRITE_STRING("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
	while (1)
	{
		
	}
	
	return 0;
}