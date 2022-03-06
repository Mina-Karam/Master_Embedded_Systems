/*
 * 03_GPIO_Test_3_Keypad_LCD_7_Segment.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Mina Karam
 */


/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Mina Karam
 */

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */

#include "LCD.h"
#include "Keypad.h"
#include "S7_Segment.h"
#include "stm32f103x6_EXTI_driver.h"

/* ========== Prototypes ========= */
static void clock_init(void);
static void delay_ms(uint32_t delay);

/* =========== Main Program ========== */
void GPIO_Test_3_Keypad_LCD_7_Segment(void)
{
	// Initializing the clock
	clock_init();

	// Initializing the LCD
	HAL_LCD_INIT();

	// Initializing the 7-segment
	HAL_7_segment_init();
	HAL_LCD_WRITE_STRING("HEY THERE !        Mina Karam");
	delay_ms(30);
	HAL_LCD_CLEAR_SCREEN();

	// Variable to check pressed key of Keypad
	uint8_t pressed_key;

	// Array to store of 7 segments shapes
	uint8_t seg_Numbers[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};

	// Array to store Numbers from 1 >>> 9 to be displayed on LCD
	uint8_t LCD_Numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

	// Loop to display the same number to LCD and 7-SEGMENT
	for (uint8_t i = 0; i < 11; i++)
	{
		// Display current number on the 7 segment
		MCAL_GPIO_WritePort(GPIOB, seg_Numbers[i] << 9);
		// We shifted by 9 as we used the First 9 Ports for Keypad and started connecting 7 segment from PB10

		// Display current number on the LCD
		HAL_LCD_WRITE_CHAR(LCD_Numbers[i]);
		// Delay to be able to see the change in numbers
		delay_ms(100);  // delay
	}

	// Clear screen after displaying Numbers
	HAL_LCD_CLEAR_SCREEN();

	// Initializing the Keypad
	HAL_KEYPAD_INIT();

	HAL_LCD_WRITE_STRING("Keypad is ready!");
	delay_ms(30);
	HAL_LCD_CLEAR_SCREEN();

	while(1)
	{
		pressed_key = HAL_KEYPAD_GET_KEY();

		switch(pressed_key)
		{
			case 'A':
				break;

			case '?':
				HAL_LCD_CLEAR_SCREEN();
				break;

			default:
				HAL_LCD_WRITE_CHAR(pressed_key);
				break;
		}
	}
}

/* ======== clock init definition ======= */
static void clock_init(void)
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();

	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
}

static void delay_ms(uint32_t delay)
{
	uint32_t i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
}
