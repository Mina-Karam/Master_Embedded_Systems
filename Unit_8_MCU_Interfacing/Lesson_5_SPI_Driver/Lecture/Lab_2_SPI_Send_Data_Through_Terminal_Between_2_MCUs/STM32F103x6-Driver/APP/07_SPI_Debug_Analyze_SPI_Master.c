/*
 * 07_SPI_Debug_Analyze_SPI_Master.c
 *
 *  Created on: Mar 5, 2022
 *      Author: Mina-Karam
 *
 * Description:
 * 			MCU1 >>>>> Terminal1 <---> USART1 : SPI1 Master
 */

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */
#include "STM32F103x6.h"
#include "stm32f103x6_GPIO_driver.h"
#include "stm32f103x6_USART_driver.h"
#include "stm32f103x6_SPI_driver.h"

/* ========= Global Macros ========== */
#define MCU_Act_As_Master
//#define MCU_Act_As_Slave

/* ========= Global variables ========== */
uint16_t data;

/* ========== Prototypes ========= */
static void Clock_Init(void);
static void USART1_CallBack(void);

/* =========== Main Program ========== */
void SPI_Debug_Analyze_SPI_Master(void)
{
	/* Initialization */
	Clock_Init();

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

	/* Configuration of SPI1 */
	SPI_Config_t SPI1_Config;

	/* Common Configuration */
	SPI1_Config.BaudRate_Prescaler = BAUDERATE_PRESCALER_8;
	SPI1_Config.CLK_Phase = CLK_PHASE_SECOND;
	SPI1_Config.CLK_Polarity = CLK_POLARITY_IDLE_HIGH;
	SPI1_Config.Frame_Format = FRAME_FORMAT_MSB_FIRST;
	SPI1_Config.Frame_Size = FRAME_SIZE_8BIT;
	SPI1_Config.Communication_Mode = COMMUNICATION_MODE_2LINE_FULL_DUPLEX;

#ifdef MCU_Act_As_Master
	SPI1_Config.SPI_Mode = SPI_MODE_MASTER;
	SPI1_Config.IRQ_Enable = IRQ_ENABLE_NONE;
	SPI1_Config.P_IRQ_CallBack = NULL;
	SPI1_Config.NSS = NSS_SW_SSI_SET;	/* To Control when open & when close, Set as Active High */

	/* Configuration of SS */
	GPIO_PinConfig_t SS_Config;

	/* Configure SS at PA4 by GPIO */
	SS_Config.GPIO_PinNumber = GPIO_PIN_4;
	SS_Config.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	SS_Config.GPIO_Speed = GPIO_SPEED_10M;

	MCAL_GPIO_Init(GPIOA, &SS_Config);

#endif

	MCAL_SPI_Init(SPI1, &SPI1_Config);
	MCAL_SPI_GPIO_Set_Pins(SPI1);

	/* Force the slave select (High) idle mode */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);


	/* Loop For Ever */
	while(1){}
}

/* ======== clock Initialize definition ======= */
static void Clock_Init(void)
{
	/* Enable clock GPIOA */
	RCC_GPIOA_CLK_EN();

	/* Enable clock GPIOB */
	RCC_GPIOB_CLK_EN();

	/* Enable Clock For AFIO */
	RCC_AFIO_CLK_EN();
}



static void USART1_CallBack(void)
{
#ifdef MCU_Act_As_Master
	MCAL_UART_ReceiveData(USART1, &data, USART_disable);
	MCAL_UART_SendData(USART1, &data, USART_enable);

	/* ========= Send Data To SPI1 =========== */

	/* Slave Selection (Low), to listen  */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

	/* Send & Receive data */
	MCAL_SPI_TX_RX(SPI1, &data, SPI_enable);

	/* Slave Selection (High) idle mode */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif
}

