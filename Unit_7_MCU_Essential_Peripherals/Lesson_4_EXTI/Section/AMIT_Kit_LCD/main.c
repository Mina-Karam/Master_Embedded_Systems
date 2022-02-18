/*
 * main.c
 *
 * Created: 2/8/2022 7:53:45 PM
 *  Author: Mina Karam
 */ 

#define F_CPU 1000000UL

#include "ATmega32_Device_Header.h"
#include "ATmega32_GPIO_Driver.h"
#include "lcd.h"

GPIO_PinConfig_t * PinConfig_A;
GPIO_PinConfig_t * PinConfig_B;


int main(void)
{
	/* AMIT LCD Data Lines
	 * Configure the PORTA Pins (4..7) as Output
	 * LCD_D4 -> PORTA.4
	 * LCD_D5 -> PORTA.5
	 * LCD_D6 -> PORTA.6
	 * LCD_D7 -> PORTA.7
	 */
	
	// Configure PIN4 as Output(push-pull)
	PinConfig_A->GPIO_PinNumber = GPIO_PIN_4;
	PinConfig_A->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN5 as Output(push-pull)
	PinConfig_A->GPIO_PinNumber = GPIO_PIN_5;
	PinConfig_A->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN6 as Output(push-pull)
	PinConfig_A->GPIO_PinNumber = GPIO_PIN_6;
	PinConfig_A->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN7 as Output(push-pull)
	PinConfig_A->GPIO_PinNumber = GPIO_PIN_7;
	PinConfig_A->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	MCAL_GPIO_Init(GPIOA, PinConfig_A);
	
	/* AMIT LCD Control Lines
	 * Configure the PortB PINs as Output(push-pull)
	 * LCD_RS -> PORTB.1
	 * LCD_RW -> PORTB.2
	 * LCD_E  -> PORTB.3
	 */
	
	// Configure PIN1 as Output(push-pull)
	PinConfig_B->GPIO_PinNumber = GPIO_PIN_1;
	PinConfig_B->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN2 as Output(push-pull)
	PinConfig_B->GPIO_PinNumber = GPIO_PIN_2;
	PinConfig_B->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	// Configure PIN3 as Output(push-pull)
	PinConfig_B->GPIO_PinNumber = GPIO_PIN_3;
	PinConfig_B->GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	
	MCAL_GPIO_Init(GPIOB, PinConfig_B);
	
	//#########################################
	
	// Initialize the LCD
	LCD_INIT();
	
	LCD_WRITE_STRING("Learn in Depth");
	
    while (1) 
    {
		
    }
	return 0;
}