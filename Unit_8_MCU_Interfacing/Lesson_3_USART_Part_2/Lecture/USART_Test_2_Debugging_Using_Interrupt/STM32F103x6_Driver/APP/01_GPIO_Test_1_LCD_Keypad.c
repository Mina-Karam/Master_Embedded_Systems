/*
 * 01_GPIO_Test_1_LCD_Keypad.c
 *
 * Created: 2/8/2022 7:53:45 PM
 *  Author: Mina Karam
 */

#define F_CPU 1000000UL

#include "LCD.h"
#include "Keypad.h"

void GPIO_Test_1_LCD_Keypad(void)
{
	HAL_LCD_INIT();
	HAL_KEYPAD_INIT();
	char pressed_key;

	while (1)
	{
		pressed_key = HAL_KEYPAD_GET_KEY();
		switch(pressed_key)
		{
			case '?':
				HAL_LCD_CLEAR_SCREEN();
				break;

			case 'A':
				break;

			default:
				HAL_LCD_WRITE_CHAR(pressed_key);
				break;
		}
	}
}
