/*
 * 04_EXTI_Test_1_LCD_Push_Button.c
 *
 *  Created on: Feb 16, 2022
 *      Author: Mina Karam
 */

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */

#include "LCD.h"
#include "stm32f103x6_EXTI_driver.h"

/* ========= Global variables ========== */
uint8_t IRQ_Flag = 0; // Interrupt Flag

/* ========== Prototypes ========= */
static void clock_init(void);
static void delay_ms(uint32_t delay);
static void EXTI9_CallBack(void);

/* =========== Main Program ========== */
void EXTI_Test_1_LCD_Push_Button(void)
{
	// Initializing the clock
	clock_init();

	// Initializing the LCD
	HAL_LCD_INIT();

	HAL_LCD_WRITE_STRING("HEY THERE !        Mina Karam");
	delay_ms(30);
	HAL_LCD_CLEAR_SCREEN();

	/* Define an object of external interrupt pin configuration */
	EXTI_PinConfig_t EXTI_Config;

	/*
	 * Configuration of the external interrupt pin 9
	 */

	/* Select the port and pin */
	EXTI_Config.EXTI_Pin = EXTI9PB9;

	/* Select the trigger case ---> Rising */
	EXTI_Config.Trigger_Case = EXTI_RT;

	/* Set the callback of the interrupt */
	EXTI_Config.P_IRQ_CallBack = EXTI9_CallBack;

	/* Enable EXTI IRQ*/
	EXTI_Config.IRQ_Enable = EXTI_IRQ_Enable;

	MCAL_EXTI_GPIO_Init(&EXTI_Config);


	IRQ_Flag = 1;

	while(1)
	{
		if (IRQ_Flag)
		{
			HAL_LCD_CLEAR_SCREEN();
			IRQ_Flag = 0;
		}

		delay_ms(1000);
	}
}

/* ======== clock init definition ======= */
static void clock_init(void)
{
	/* Enable clock GPIOA */
	RCC_GPIOA_CLK_EN();

	/* Enable clock GPIOB */
	RCC_GPIOB_CLK_EN();

	/* Enable Clock For AFIO */
	RCC_AFIO_CLK_EN();
}

static void delay_ms(uint32_t delay)
{
	uint32_t i, j;
	for (i = 0; i < delay; i++)
	{
		for (j = 0; j < 255; j++);
	}
}

/* ======== CallBack definition ======= */
static void EXTI9_CallBack(void)
{
	IRQ_Flag = 1;
	HAL_LCD_WRITE_STRING("IRQ EXTI9 has happened _|- ");
	delay_ms(1000);
}
