/*
 * 05_USART_Test_1_Debugging_Using_Polling.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Mina-Karam
 */

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */

#include "STM32F103x6.h"
#include "stm32f103x6_GPIO_driver.h"
#include "stm32f103x6_EXTI_driver.h"
#include "stm32f103x6_USART_driver.h"

#include "LCD.h"

/* ========= Global variables ========== */
uint16_t data;

/* ========== Prototypes ========= */
static void clock_init(void);

/* =========== Main Program ========== */
void USART_Test_1_Debugging_Using_Polling(void)
{
	/* Initializing the clock */
	clock_init();

	/* Configuration of USART1 */
	USART_Config_t USART1_Config;

	USART1_Config.BaudRate = UART_BaudRate_115200;
	USART1_Config.HwFlowCtl = UART_HwFlowCtl_NONE;
	USART1_Config.IRQ_Enable = UART_IRQ_Enable_NONE;
	USART1_Config.P_IRQ_CallBack = NULL;
	USART1_Config.Parity = UART_Parity_NONE;
	USART1_Config.Payload_Length = UART_Payload_Length_8B;
	USART1_Config.StopBits = UART_StopBits_1;
	USART1_Config.USART_Mode = UART_Mode_TX_RX;

	MCAL_UART_Init(USART1, &USART1_Config);
	MCAL_UART_GPIO_Set_Pins(USART1);

	while(1)
	{
		MCAL_UART_ReceiveData(USART1, &data, USART_enable);
		MCAL_UART_SendData(USART1, &data, USART_enable);
	}
}

/* ======== clock Initialize definition ======= */
static void clock_init(void)
{
	/* Enable clock GPIOA */
	RCC_GPIOA_CLK_EN();

	/* Enable clock GPIOB */
	RCC_GPIOB_CLK_EN();

	/* Enable Clock For AFIO */
	RCC_AFIO_CLK_EN();
}
