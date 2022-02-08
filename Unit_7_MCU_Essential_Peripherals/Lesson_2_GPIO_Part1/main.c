/*
 * main.c
 *
 * Created: 2/8/2022 7:53:45 PM
 *  Author: Mina Karam
 */ 

#define F_CPU 1000000UL

#include "avr/io.h"
#include "util/delay.h"

#include "LCD_driver/lcd.h"
#include "Keypad_driver/keypad.h"

int main(void)
{
	LCD_INIT();
	KEYPAD_INIT();
	char pressed_key;
	
	while (1)
	{
		pressed_key = KEYPAD_GET_KEY();
		switch(pressed_key)
		{
			case '?':
				LCD_CLEAR_SCREEN();
				break;
				
			case 'A':
				break;
				
			default:
				LCD_WRITE_CHAR(pressed_key);
				break;
		}	
	}
	
	return 0;
}