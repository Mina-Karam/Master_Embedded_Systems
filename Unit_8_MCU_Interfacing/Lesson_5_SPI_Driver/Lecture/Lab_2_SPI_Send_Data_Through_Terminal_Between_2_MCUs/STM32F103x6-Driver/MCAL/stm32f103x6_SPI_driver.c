/*
 * stm32f103x6_SPI_driver.c
 *
 *  Created on: Mar 5, 2022
 *      Author: Mina-Karam
 */

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "stm32f103x6_SPI_driver.h"

/* ================================================================ */
/* ===================== Generic Variables ======================== */
/* ================================================================ */

SPI_Config_t *G_SPI_Config[2] = {NULL, NULL};

/* ================================================================ */
/* ======================= Generic Macros ========================= */
/* ================================================================ */

#define SPI1_INDEX 		0
#define SPI2_INDEX 		1

#define SPI_SR_TXE		(uint16_t)(1<<1)
#define SPI_SR_RXNE		(uint16_t)(1<<0)

/* ================================================================ */
/* ======================== Public APIs =========================== */
/* ================================================================ */

/* ================================================================
 * @Fn 				- MCAL_SPI_Init
 * @brief 			- Initializes SPIx according to the specified parameters in SPI_Config_t
 * @param [in] 		- SPIx : where x can be (1..2 depending on device used) to select SPI peripheral
 * @param [in] 		- Config : a pointer to SPI_Config_t structure that contains the configuration information for the specified SPI Module
 * @retval 			- None
 * Note 			- Supported for SPI FULL DUPLEX Master/Slave only & NSS Hardware/Software
 * 					- You have to configure RCC to select clock for the selected SPI Module
 */
void MCAL_SPI_Init(SPI_Typedef_t *SPIx, SPI_Config_t *Config)
{
	/* Safety for register, Using this technique for protect the peripheral form working before the full configurations */
	uint16_t tempReg_CR1 = 0;
	uint16_t tempReg_CR2 = 0;

	if(SPIx == SPI1)
	{
		/* If SPI1 Put all configurations in the global config */
		G_SPI_Config[SPI1_INDEX] = Config;

		/* 1. Open the SPI1 RCC Clock */
		RCC_SPI1_CLK_EN();
	}
	else if(SPIx == SPI2)
	{
		/* If SPI2 Put all configurations in the global config */
		G_SPI_Config[SPI2_INDEX] = Config;

		/* 1. Open the SPI1 RCC Clock */
		RCC_SPI2_CLK_EN();
	}

	/* 2. Enable the SPI */
	tempReg_CR1 |= (uint16_t)(1<<6); 	/* Bit 6 SPE: SPI enable */

	/* 3. Set Master or Slave */
	tempReg_CR1 |= Config->SPI_Mode;

	/* 4. Set Communication Mode */
	tempReg_CR1 |= Config->Communication_Mode;

	/* 5. Set Frame format */
	tempReg_CR1 |= Config->Frame_Format;

	/* 6. Set Data size */
	tempReg_CR1 |= Config->Frame_Size;

	/* 7. Set Clock Polarity */
	tempReg_CR1 |= Config->CLK_Polarity;

	/* 8. Set Clock Phase */
	tempReg_CR1 |= Config->CLK_Phase;

	/* 9. Set Slave Select Management */
	if(Config->NSS == NSS_HW_MASTER_SS_OUTPUT_ENABLED)
	{
		tempReg_CR2 |= Config->NSS;
	}
	else if(Config->NSS == NSS_HW_MASTER_SS_OUTPUT_DISABLED)
	{
		tempReg_CR2 &= Config->NSS;
	}
	else
	{
		tempReg_CR1 |= Config->NSS;
	}

	/* 10. Set BoudRate Pre-scaler */
	tempReg_CR1 |= Config->BaudRate_Prescaler;

	/* 11. Set Interrupt Type */
	if(Config->IRQ_Enable != IRQ_ENABLE_NONE)
	{
		tempReg_CR2 |= Config->IRQ_Enable;

		/* 12. Open the global Interrupt for each peripheral */
		if (SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_EN();
		}
		else if(SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_EN();
		}
	}

	/*13. Config your register using the temp register used to protect the configurations */
	SPIx->CR1 = tempReg_CR1;
	SPIx->CR2 = tempReg_CR2;

}

/* ================================================================
 * @Fn 				- MCAL_SPI_DeInit
 * @brief 			- Resets Selected SPI Module
 * @param [in] 		- SPIx : where x can be (1..2 depending on device used) to select SPI peripheral
 * @retval 			- None
 * Note 			- Reset The Module By RCC & Disable NVIC
 */
void MCAL_SPI_DeInit(SPI_Typedef_t *SPIx)
{
	if (SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_DI();
		RCC_SPI1_RESET();
	}
	else if(SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_DI();
		RCC_SPI2_RESET();
	}
}

/* ================================================================
 * @Fn 				- MCAL_SPI_GPIO_Set_Pins
 * @brief 			- Initializes GPIO Pins to be connected with the selected SPI
 * @param [in] 		- SPIx : where x can be (1..2 depending on device used) to select SPI peripheral
 * @retval 			- None
 * Note 			- Must open clock for AFIO & GPIO After GPIO Initialization
 * 					- Supported for SPI FULL DUPLEX Master/Slave only & NSS Hardware/Software
 */
void MCAL_SPI_GPIO_Set_Pins(SPI_Typedef_t *SPIx)
{
	GPIO_PinConfig_t SPI_GPIO_Config;

	/* Depending the recommendation in data sheet -> Table 25. SPI 	*/
	/*  "SPI pin-out"    "Configuration"     "GPIO configuration" 	*/
	if (SPIx == SPI1)
	{
		if(G_SPI_Config[SPI1_INDEX]->SPI_Mode == SPI_MODE_MASTER) /* Master */
		{
			/* PA4 : SPI1_NSS */
			switch (G_SPI_Config[SPI1_INDEX]->NSS)
			{
			 	 /* Input */
				case NSS_HW_MASTER_SS_OUTPUT_DISABLED:
					/* Hardware Master/Slave Input Floating */
					SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_4;
					SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
					MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
					break;

				/* Output */
				case NSS_HW_MASTER_SS_OUTPUT_ENABLED:
					/* Hardware Master/NNS Output Alternate function push-pull */
					SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_4;
					SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
					SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
					MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
					break;
			}

			/* PA5 : SPI1_SCK */
			/* Master Alternate function push-pull */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_5;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);

			/* PA6 : SPI1_MISO */
			/* Full duplex / master Input floating / Input pull-up */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_6;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);

			/* PA7 : SPI1_MOSI */
			/* Full duplex / master Alternate function push-pull */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_7;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
		}
		else /* Slave */
		{
			/* PA4 : SPI1_NSS */
			if(G_SPI_Config[SPI1_INDEX]->NSS == NSS_HW_SLAVE)
			{
				/* Hardware Master/Slave Input Floating */
				SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_4;
				SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
			}

			/* PA5 : SPI1_SCK */
			/* Slave Input floating */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_5;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);

			/* PA6 : SPI1_MISO */
			/* Full duplex / slave (point to point) Alternate function push-pull */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_6;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);

			/* TODO Full duplex / slave (multi-slave) Alternate function open drain */

			/* PA7 : SPI1_MOSI */
			/* Full duplex / slave Input floating / Input pull-up */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_7;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
		}
	}
	else if(SPIx == SPI2)
	{
		if(G_SPI_Config[SPI2_INDEX]->SPI_Mode == SPI_MODE_MASTER) /* Master */
		{
			/* PB12 : SPI2_NSS */
			switch (G_SPI_Config[SPI2_INDEX]->NSS)
			{
				 /* Input */
				case NSS_HW_MASTER_SS_OUTPUT_DISABLED:
					/* Hardware Master/Slave Input Floating */
					SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_12;
					SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
					MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
					break;

				/* Output */
				case NSS_HW_MASTER_SS_OUTPUT_ENABLED:
					/* Hardware Master/NNS Output Alternate function push-pull */
					SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_12;
					SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
					SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
					MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
					break;
			}

			/* PB13 : SPI2_SCK */
			/* Master Alternate function push-pull */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_13;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);

			/* PB14 : SPI2_MISO */
			/* Full duplex / master Input floating / Input pull-up */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_14;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);

			/* PB15 : SPI2_MOSI */
			/* Full duplex / master Alternate function push-pull */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_15;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		}
		else /* Slave */
		{
			/* PB12 : SPI2_NSS */
			if(G_SPI_Config[SPI2_INDEX]->NSS == NSS_HW_SLAVE)
			{
				/* Hardware Master/Slave Input Floating */
				SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_12;
				SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
			}

			/* PB13 : SPI2_SCK */
			/* Slave Input floating */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_13;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);

			/* PB14 : SPI2_MISO */
			/* Full duplex / slave (point to point) Alternate function push-pull */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_14;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			SPI_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);

			/* TODO Full duplex / slave (multi-slave) Alternate function open drain */

			/* PB15 : SPI2_MOSI */
			/* Full duplex / slave Input floating / Input pull-up */
			SPI_GPIO_Config.GPIO_PinNumber = GPIO_PIN_15;
			SPI_GPIO_Config.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		}
	}
}

/* ================================================================
 * @Fn 				- MCAL_SPI_Send_Data
 * @brief 			- Send Buffer With SPI
 * @param [in] 		- SPIx : where x can be (1..2 depending on device used) to select SPI peripheral
 * @param [in] 		- pTxBuffer : Pointer to buffer Which holds the Tx data
 * @param [in] 		- Polling_En : Enable Polling or Disable it
 * @retval 			- None
 * Note 			- None
 *
 */
void MCAL_SPI_Send_Data(SPI_Typedef_t *SPIx, uint16_t *pTxBuffer, enum Polling_Mechanism Polling_En)
{
	// TODO Checker

	if(Polling_En == SPI_enable)
	{
		/* Wait for transmission complete */
		while(! (SPIx->SR & SPI_SR_TXE));
	}

	/* Start transmission, Write data to SPI data register */
	SPIx->DR = *(pTxBuffer);
}

/* ================================================================
 * @Fn 				- MCAL_SPI_Recieve_Data
 * @brief 			- Receive Buffer With SPI
 * @param [in] 		- SPIx : where x can be (1..2 depending on device used) to select SPI peripheral
 * @param [in] 		- pRxBuffer : Pointer to buffer which holds Rx data
 * @param [in] 		- Polling_En : Enable Polling or Disable it
 * @retval 			- None
 * Note 			- None
 */
void MCAL_SPI_Recieve_Data(SPI_Typedef_t *SPIx, uint16_t *pRxBuffer, enum Polling_Mechanism Polling_En)
{
	if(Polling_En == SPI_enable)
	{
		/* Wait for reception complete */
		while(! (SPIx->SR & SPI_SR_RXNE));
	}

	/* Start reception, Write data to SPI data register */
	*(pRxBuffer) = SPIx->DR;
}

/* ================================================================
 * @Fn 				- MCAL_SPI_TX_RX
 * @brief 			- Transmit and Receive Data
 * @param [in] 		- SPIx : where x can be (1..2 depending on device used) to select SPI peripheral
 * @param [in] 		- pTxBuffer : Pointer to buffer which holds Transmit and Received data
 * @param [in] 		- Polling_En : Enable Polling or Disable it
 * @retval 			- None
 * Note 			- None
 */
void MCAL_SPI_TX_RX(SPI_Typedef_t *SPIx, uint16_t *pTxBuffer, enum Polling_Mechanism Polling_En)
{
	if(Polling_En == SPI_enable)
	{
		/* Wait for transmission complete */
		while(! (SPIx->SR & SPI_SR_TXE));
	}

	/* Start transmission, Write data to SPI data register */
	SPIx->DR = *(pTxBuffer);

/* =================================================== */

	if(Polling_En == SPI_enable)
	{
		/* Wait for reception complete */
		while(! (SPIx->SR & SPI_SR_RXNE));
	}

	/* Start reception, Write data to SPI data register */
	*(pTxBuffer) = SPIx->DR;
}

/* ================================================================ */
/* ================= IRQ Function Definitions ===================== */
/* ================================================================ */

void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC IRQ;

	IRQ.TXE = ((SPI1->SR & (1<<1)) >> 1);
	IRQ.RXNE = ((SPI1->SR & (1<<0)) >> 0);
	IRQ.ERRI = ((SPI1->SR & (1<<4)) >> 4);

	G_SPI_Config[SPI1_INDEX]->P_IRQ_CallBack(IRQ);
}


void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC IRQ;

	IRQ.TXE = ((SPI2->SR & (1<<1)) >> 1);
	IRQ.RXNE = ((SPI2->SR & (1<<0)) >> 0);
	IRQ.ERRI = ((SPI2->SR & (1<<4)) >> 4);

	G_SPI_Config[SPI2_INDEX]->P_IRQ_CallBack(IRQ);
}
