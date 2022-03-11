/*
 * atmega32_SPI_Test.c
 *
 * Created: 3/7/2022 10:38:44 AM
 *  Author: Mina-Karam
 */ 

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */
#include "atmega32_device_header.h"
#include "atmega32_GPIO_driver.h"
#include "atmega32_USART_driver.h"
#include "atmega32_SPI_driver.h"

#include "atmega32_SPI_Test.h"

/* ========= Global Macros ========== */
#define MCU_Act_As_Master
//#define MCU_Act_As_Slave

/* ========= Global variables ========== */
uint8 data;

/* ========== Prototypes ========= */
static void USART_CallBack(void);

/* =========== Main Program ========== */
void SPI_Test(void)
{

	/* Configuration of USART1 */
	USART_Config_t USART_Config;

	USART_Config.USART_Baudrate = USART_BAUD_RATE_115200;
	USART_Config.USART_IRQ_Enable = USART_IRQ_RXCIE;
	USART_Config.P_IRQ_CallBack = USART_CallBack;
	USART_Config.USART_Paritybit = USART_NO_PARITY;
	USART_Config.USART_Databits = USART_8_DATA_BITS;
	USART_Config.USART_Stopbits = USART_1_STOP_BIT;
	USART_Config.USART_Mode = USART_MODE_ASYNC;

	MCAL_USART_Init(&USART_Config);

	/* Configuration of SPI1 */
	SPI_Config_t SPI_Config;

	/* Common Configuration */
	SPI_Config.BaudRate_Prescaler = BAUDERATE_PRESCALER_4;
	SPI_Config.CLK_Phase = CLK_PHASE_SAMPLE_SETUP;
	SPI_Config.CLK_Polarity = CLK_POLARITY_RISING_FALLING;
	SPI_Config.Frame_Format = FRAME_FORMAT_MSB_FIRST;
	SPI_Config.Communication_Mode = COMMUNICATION_MODE_FULL_DUPLEX;

	#ifdef MCU_Act_As_Master
	SPI_Config.SPI_Mode = SPI_MODE_MASTER;
	SPI_Config.IRQ_Enable = IRQ_ENABLE_NONE;
	SPI_Config.P_IRQ_CallBack = NULL;

	#endif

	MCAL_SPI_Init(&SPI_Config);
	MCAL_SPI_GPIO_Set_Pins();

	/* Set Idle High (Active High) */
	MCAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);


	/* Loop For Ever */
	while(1){}
}


static void USART_CallBack(void)
{
	#ifdef MCU_Act_As_Master
	MCAL_UART_ReceiveData(USART_disable);
	MCAL_UART_SendData(data, USART_enable);

	/* ========= Send Data To SPI1 =========== */

	/* Slave Selection (Low), to listen  */
	MCAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);

	/* Send & Receive data */
	MCAL_SPI_TX_RX(&data, SPI_enable);

	/* Slave Selection (High) idle mode */
	MCAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);
	#endif
}