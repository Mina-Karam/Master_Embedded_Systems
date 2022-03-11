/*
 * atmega32_USART_Test.c
 *
 * Created: 3/3/2022 3:23:22 PM
 *  Author: Mina-Karam
 */ 

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */

#include "atmega32_device_header.h"
#include "atmega32_GPIO_driver.h"
#include "atmega32_USART_driver.h"

#include "atmega32_USART_Test.h"
#include "atmega32_LCD.h"

/* ========= Global variables ========== */
uint16 data;
uint8 buffer[30];
/* =========== Main Program ========== */
void atmega32_USART_Test(void)
{
	//USART_Config_t Config;
	
	HAL_LCD_INIT();
	
// 	Config.USART_Baudrate = USART_BAUD_RATE_9600;
// 	Config.USART_Databits = USART_8_DATA_BITS;
// 	Config.USART_IRQ_Enable = USART_IRQ_DISABLE;
// 	Config.USART_Mode = USART_MODE_ASYNC;
// 	Config.USART_Paritybit = USART_NO_PARITY;
// 	Config.USART_Stopbits = USART_1_STOP_BIT;
// 	Config.P_IRQ_CallBack = NULL;
// 	
	//MCAL_USART_Init(&Config);
	
	HAL_LCD_WRITE_CHAR('M');
	HAL_LCD_WRITE_CHAR('I');
	HAL_LCD_WRITE_CHAR('N');
	HAL_LCD_WRITE_CHAR('A');
	
// 	MCAL_USART_SendString(((uint8*)"Hello"));
// 	MCAL_USART_ReceiveString(buffer);
// 	HAL_LCD_WRITE_STRING(((char*)buffer));
	
	//MCAL_UART_SendData('M',enable);
	while (1)
	{
// 		data = MCAL_UART_ReceiveData(enable);
// 		MCAL_UART_SendData(data, enable);
	}
}
