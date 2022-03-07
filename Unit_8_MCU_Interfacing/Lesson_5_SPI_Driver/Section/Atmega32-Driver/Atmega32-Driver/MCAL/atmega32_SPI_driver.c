/*
 * atmega32_SPI_driver.c
 *
 * Created: 3/6/2022 7:14:04 AM
 *  Author: Mina-Karam
 */ 
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "atmega32_SPI_driver.h"
#include "avr/interrupt.h"

/* ================================================================ */
/* ===================== Generic Variables ======================== */
/* ================================================================ */

SPI_Config_t *G_SPI_Config = {NULL};	

/* ================================================================ */
/* ======================== Public APIs =========================== */
/* ================================================================ */

/* ================================================================
 * @Fn 				- MCAL_SPI_Init
 * @brief 			- Initializes SPI according to the specified parameters in SPI_Config_t
 * @param [in] 		- Config : a pointer to SPI_Config_t structure that contains the configuration information for the specified SPI Module
 * @retval 			- None
 * Note 			- None
 * 					- None
 */
void MCAL_SPI_Init(SPI_Config_t *Config)
{
	/* Safety for register, Using this technique for protect the peripheral form working before the full configurations */
	uint8 tempReg_SPCR = 0;
	
	/* Add all configuration to the global config to use it with all driver */
	G_SPI_Config = Config;
	
	/* 1. Enable the SPI */
	tempReg_SPCR |= (1<<6);
	
	/* 2. Set Master or Slave */
	tempReg_SPCR |= Config->SPI_Mode;
	
	/* 3. Set Communication Mode */
	tempReg_SPCR |= Config->Communication_Mode;
	
	/* 4. Set Frame format */
	tempReg_SPCR |= Config->Frame_Format;

	/* 5. Set Clock Polarity */
	tempReg_SPCR |= Config->CLK_Polarity;

	/* 6. Set Clock Phase */
	tempReg_SPCR |= Config->CLK_Phase;
	
	/* Check If Double Speed Selected to set the BaudRate Pre-scaler */
	if (Config->CLK_Speed == CLK_SPEED_LOW)
	{
		/* 7. Set BoudRate Pre-scaler */
		tempReg_SPCR |= Config->BaudRate_Prescaler;
	}
	else
	{
		/* 7. Set BoudRate Pre-scaler */
		tempReg_SPCR |= Config->BaudRate_Prescaler;
		SPI->SPSR_.bits.SPI2X_ = 1;
	}
	
	/* Check If IRQ Enabled */
	if (Config->IRQ_Enable != IRQ_ENABLE_NONE)
	{
		/* Open Global Interrupt */
		Enable_G_Interrupt();
		
		/* 8. Open Interrupt */
		tempReg_SPCR |= Config->IRQ_Enable;
	}
	else
	{
		/* 8. Disable Interrupt */
		tempReg_SPCR |= Config->IRQ_Enable;
	}
	
	/* 9. Config your register using the temp register used to protect the configurations */
	SPI->SPCR_.SPCR_ = tempReg_SPCR;
}

/* ================================================================
 * @Fn 				- MCAL_SPI_DeInit
 * @brief 			- Resets Selected SPI Module
 * @retval 			- none
 * Note 			- Reset The Module & Disable Global Interrupt
 */
void MCAL_SPI_DeInit(void)
{
	/* Put all writeable regiter in reset mode */
	SPI->SPCR_.SPCR_ = 0x00;
	SPI->SPSR_.bits.SPI2X_ = 0;
}

/* ================================================================
 * @Fn 				- MCAL_SPI_GPIO_Set_Pins
 * @brief 			- Initializes GPIO Pins to be connected with the selected SPI
 * @retval 			- None
 * Note 			- None
 */
void MCAL_SPI_GPIO_Set_Pins(void)
{
	/*
	 * Port Pin Alternate Functions
	 *   PB7      SCK (SPI Bus Serial Clock)
	 *   PB6      MISO (SPI Bus Master Input/Slave Output)
	 *   PB5      MOSI (SPI Bus Master Output/Slave Input)
	 *   PB4      SS (SPI Slave Select Input) 
	 */
	GPIO_PinConfig_t SPI_GPIO_Config;
	
	/* Master */
	if (G_SPI_Config->SPI_Mode == SPI_MODE_MASTER)
	{
		/* PB7      SCK: Master Clock output */
		SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_7;
		SPI_GPIO_Config.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
		MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		
		/* PB6      MISO: Master Data input */
		SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_6;
		SPI_GPIO_Config.GPIO_PinMode = GPIO_MODE_INPUT_HiZ;
		MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		
		/* PB5      MOSI: SPI Master Data output */
		SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_5;
		SPI_GPIO_Config.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
		MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		
		/* PB4      SS: SPI Master Data Output */
		SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_4;
		SPI_GPIO_Config.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
		MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
	}
	/* Slave */
	else 
	{
		/* PB7      SCK:  Slave Clock input pin */
		SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_7;
		SPI_GPIO_Config.GPIO_PinMode = GPIO_MODE_INPUT_HiZ;
		MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		
		/* PB6      MISO: Slave Data output pin */
		SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_6;
		SPI_GPIO_Config.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
		MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		
		/* PB5      MOSI: Slave Data input */
		SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_5;
		SPI_GPIO_Config.GPIO_PinMode = GPIO_MODE_INPUT_HiZ;
		MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		
		/* PB4      SS: SPI Slave Select input */
		SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_4;
		SPI_GPIO_Config.GPIO_PinMode = GPIO_MODE_INPUT_HiZ;
		MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
	}
	
}

/* ================================================================
 * @Fn 				- MCAL_SPI_Send_Data
 * @brief 			- Send Buffer With SPI
 * @param [in] 		- pTxBuffer : Pointer to buffer Which holds the Tx data
 * @param [in] 		- Polling_En : Enable Polling or Disable it
 * @retval 			- None
 * Note 			- None
 *
 */
void MCAL_SPI_Send_Data(uint8 *pTxBuffer, enum SPI_Polling_Mechanism Polling_En)
{
	/* Start transmission, Write data to SPI data register */
	SPI->SPDR_ = *pTxBuffer;
	
	/* Wait for transmission complete */
	if (Polling_En == SPI_enable)
	{
		while (!(SPI->SPSR_.bits.SPIF_));
	}
}

/* ================================================================
 * @Fn 				- MCAL_SPI_Recieve_Data
 * @brief 			- Receive Buffer With SPI
 * @param [in] 		- pRxBuffer : Pointer to buffer which holds Rx data
 * @param [in] 		- Polling_En : Enable Polling or Disable it
 * @retval 			- None
 * Note 			- None
 */
void MCAL_SPI_Recieve_Data(uint8 *pRxBuffer, enum SPI_Polling_Mechanism Polling_En)
{
	/* Wait for reception complete */
	if (Polling_En == SPI_enable)
	{
		while (!(SPI->SPSR_.bits.SPIF_));
	}
	
	/* Start reception, Write data to SPI data register */
	*pRxBuffer = SPI->SPDR_;
}

/* ================================================================
 * @Fn 				- MCAL_SPI_TX_RX
 * @brief 			- Transmit and Receive Data
 * @param [in] 		- pTxBuffer : Pointer to buffer which holds Transmit and Received data
 * @param [in] 		- Polling_En : Enable Polling or Disable it
 * @retval 			- None
 * Note 			- None
 */
void MCAL_SPI_TX_RX(uint8 *pTxBuffer, enum SPI_Polling_Mechanism Polling_En)
{
	/* Start transmission, Write data to SPI data register */
	SPI->SPDR_ = *pTxBuffer;
	
	/* Wait for transmission complete */
	if (Polling_En == SPI_enable)
	{
		while (!(SPI->SPSR_.bits.SPIF_));
	}
	
	/* =================================================== */
	
	/* Wait for reception complete */
	if (Polling_En == SPI_enable)
	{
		while (!(SPI->SPSR_.bits.SPIF_));
	}
	
	/* Start reception, Write data to SPI data register */
	*pTxBuffer = SPI->SPDR_;
}

/* ================================================================ */
/* ================= IRQ Function Definitions ===================== */
/* ================================================================ */

ISR(SPI_STC_vect)
{
	G_SPI_Config->P_IRQ_CallBack();
}