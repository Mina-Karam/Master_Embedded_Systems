/*
 * 06_USART_Test_2_Debugging_Using_Interrupt.c
 *
 *  Created on: Mar 2, 2022
 *      Author: Mina-Karam
 */

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */

#include "STM32F103x6.h"
#include "stm32f103x6_GPIO_driver.h"
#include "stm32f103x6_USART_driver.h"

/* ========= Global variables ========== */
uint16_t data;

/* ========== Prototypes ========= */
static void clock_init(void);
static void USART1_CallBack(void);

/* =========== Main Program ========== */
void USART_Test_2_Debugging_Using_Interrupt(void)
{
	/* Initializing the clock */
	clock_init();

	/* Configuration of USART1 */
	USART_Config_t USART1_Config;

	USART1_Config.BaudRate = UART_BaudRate_115200;
	USART1_Config.HwFlowCtl = UART_HwFlowCtl_NONE;
	USART1_Config.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
	USART1_Config.P_IRQ_CallBack = USART1_CallBack;
	USART1_Config.Parity = UART_Parity_NONE;
	USART1_Config.Payload_Length = UART_Payload_Length_8B;
	USART1_Config.StopBits = UART_StopBits_1;
	USART1_Config.USART_Mode = UART_Mode_TX_RX;

	MCAL_UART_Init(USART1, &USART1_Config);
	MCAL_UART_GPIO_Set_Pins(USART1);

	while(1){}
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

/* ======== IRQ CallBack Function ======= */

static void USART1_CallBack(void)
{
	MCAL_UART_ReceiveData(USART1, &data, USART_disable);
	MCAL_UART_SendData(USART1, &data, USART_enable);
}

