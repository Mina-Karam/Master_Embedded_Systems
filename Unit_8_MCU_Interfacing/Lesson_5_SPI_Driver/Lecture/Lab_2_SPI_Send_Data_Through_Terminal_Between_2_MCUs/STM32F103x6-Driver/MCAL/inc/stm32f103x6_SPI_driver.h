/*
 * stm32f103x6_SPI_driver.h
 *
 *  Created on: Mar 5, 2022
 *      Author: Mina-Karam
 */

#ifndef INC_STM32F103X6_SPI_DRIVER_H_
#define INC_STM32F103X6_SPI_DRIVER_H_

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "stm32f103x6.h"
#include "stm32f103x6_GPIO_driver.h"

/* ================================================================ */
/* ============= User type definitions (structures) =============== */
/* ================================================================ */

struct S_IRQ_SRC
{
	uint8_t		TXE:1;						// TX Buffer Empty Interrupt
	uint8_t		RXNE:1;						// RX Buffer Not Empty Interrupt
	uint8_t		ERRI:1;						// Error Interrupt
	uint8_t		Reserved:5;
};

typedef struct
{
	/* uint16_t --> Because the data in register not more than 16-bit the remaining bits are reserved  */

	uint16_t 	SPI_Mode;					// specifies SPI MODE Master/Slave
											// This parameter must be set based on @ref SPI_MODE_DEFINE

	uint16_t	Communication_Mode;			// specifies SPI Communication mode
											// This parameter must be set based on @ref COMMUNICATION_MODE_DEFINE

	uint16_t	Frame_Format;				// specifies Data MSB transmit first or LSB transmit first
											// This parameter must be set based on @ref FRAME_FORMAT_DEFINE

	uint16_t	Frame_Size;					// specifies Data frame size 8-bit or 16_bit
											// This parameter must be set based on @ref FRABaudRate_PrescalerME_SIZE_DEFINE

	uint16_t	CLK_Polarity;				// specifies SPI clock Polarity idle on low or idle on high
											// This parameter must be set based on @ref CLK_POLARITY_DEFINE

	uint16_t	CLK_Phase;					// specifies SPI clock Phase,first clock capture or second clock capture
											// This parameter must be set based on @ref CLK_PHASE_DEFINE

	uint16_t	NSS;						// specifies slave select management by hardware or by software
											// This parameter must be set based on @ref NSS_DEFINE

	uint16_t	BaudRate_Prescaler;		    // specifies SPI clock BaudRate Prescaler
											// This parameter must be set based on @ref BAUDERATE_PRESCALER_DEFINE

	uint16_t	IRQ_Enable;					// specifies SPI Interrupt Requests
											// This parameter must be set based on @ref IRQ_ENABLE_DEFINE

	void (* P_IRQ_CallBack)(struct S_IRQ_SRC IRQ_src);	//set the C Function which will be called once IRQ Happens


}SPI_Config_t;

/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

// @ref SPI_MODE_DEFINE
#define SPI_MODE_MASTER							(uint16_t) (1<<2) 	/* CR1.Bit 2 MSTR: Master selection -> 	1: Master configuration */
#define SPI_MODE_SLAVE							(uint16_t) (0) 		/* 										0: Slave configuration  */

// @ref COMMUNICATION_MODE_DEFINE
#define COMMUNICATION_MODE_1LINE_RX_ONLY		(uint16_t) (1<<15)				/* CR1.Bit 15 BIDIMODE: Bidirectional data mode enable -> 	1: 1-line bidirectional data mode selected */
#define COMMUNICATION_MODE_1LINE_TX_ONLY		(uint16_t) ((1<<15) | (1<<14))	/* CR1.Bit 15 BIDIMODE: Bidirectional data mode enable -> 	1: 1-line bidirectional data mode selected */
																				/* CR1. Bit 14 BIDIOE: Output enable in bidirectional mode -> 1: Output enabled (transmit-only mode) */
#define COMMUNICATION_MODE_2LINE_FULL_DUPLEX	(uint16_t) (0)					/* CR1.Bit 15 BIDIMODE: Bidirectional data mode enable -> 	0: 2-line unidirectional data mode selected */
#define COMMUNICATION_MODE_2LINE_RXE_ONLY		(uint16_t) (1<<10)				/* CR1.Bit 10 RXONLY: Receive only -> 	1: Output disabled (Receive-only mode) */

// @ref FRAME_FORMAT_DEFINE
#define FRAME_FORMAT_MSB_FIRST					(uint16_t) (0)		/* CR1.Bit 7 LSBFIRST: Frame format -> 	0: MSB transmitted first */
#define FRAME_FORMAT_LSB_FIRST					(uint16_t) (1<<7)	/* 									 	1: LSB transmitted first */


// @ref FRAME_SIZE_DEFINE
#define FRAME_SIZE_8BIT							(uint16_t) (0)		/* CR1.Bit 11 DFF: Data frame format -> 0: 8-bit data frame format is selected for transmission/reception */
#define FRAME_SIZE_16BIT						(uint16_t) (1<<11)	/* 										1: 16-bit data frame format is selected for transmission/reception */


// @ref CLK_POLARITY_DEFINE
#define CLK_POLARITY_IDLE_LOW					(uint16_t) (0)		/* CR1.Bit1 CPOL: Clock polarity -> 0: CK to 0 when idle */
#define CLK_POLARITY_IDLE_HIGH					(uint16_t) (1<<1)	/* 									1: CK to 1 when idle */

// @ref CLK_PHASE_DEFINE
#define CLK_PHASE_FIRST							(uint16_t) (0)		/* CR1.Bit 0 CPHA: Clock phase -> 0: The first clock transition is the first data capture edge */
#define CLK_PHASE_SECOND						(uint16_t) (1<<0)   /*								  1: The second clock transition is the first data capture edge */

// @ref NSS_DEFINE
/* Hardware (SPI_CR2 Register) */
#define NSS_HW_SLAVE							(uint16_t) (0)
#define NSS_HW_MASTER_SS_OUTPUT_ENABLED			(uint16_t) (1<<2)	/* Bit 2 SSOE: SS output enable -> 1: SS output is enabled in master mode and when the cell is enabled.
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  	  	  	  	  	  	  	  The cell cannot work in a multimaster environment. */
#define NSS_HW_MASTER_SS_OUTPUT_DISABLED		(uint16_t) ~(1<<2)

/* Software (NSS is driven by Software for "Master or Slave" )*/
#define NSS_SW_SSI_SET							(uint16_t) ((1<<9) | (1<<8))
#define NSS_SW_SSI_RESET						(uint16_t) (1<<9)

// @ref BAUDERATE_PRESCALER_DEFINE
/* CR1.Bit1 CPOL: Clock polarity */
#define BAUDERATE_PRESCALER_2					(uint16_t) (0)
#define BAUDERATE_PRESCALER_4					(uint16_t) (1<<3)
#define BAUDERATE_PRESCALER_8					(uint16_t) (2<<3)
#define BAUDERATE_PRESCALER_16					(uint16_t) (3<<3)
#define BAUDERATE_PRESCALER_32					(uint16_t) (4<<3)
#define BAUDERATE_PRESCALER_64					(uint16_t) (5<<3)
#define BAUDERATE_PRESCALER_128					(uint16_t) (6<<3)
#define BAUDERATE_PRESCALER_256					(uint16_t) (7<<3)

// @ref IRQ_ENABLE_DEFINE
#define IRQ_ENABLE_NONE							(uint16_t) (0)			// IRQ Disable
#define IRQ_ENABLE_TXEIE						(uint16_t) (1<<7)		// TX buffer empty interrupt enable
#define IRQ_ENABLE_RXNEIE						(uint16_t) (1<<6)		// RX buffer not empty interrupt enable
#define IRQ_ENABLE_ERRIE						(uint16_t) (1<<5)		// Error interrupt enable

enum Polling_Mechanism
{
	SPI_disable,
	SPI_enable
};

/* ================================================================ */
/* =========== APIs Supported by "MCAL SPI DRIVER" ================ */
/* ================================================================ */


void MCAL_SPI_Init(SPI_Typedef_t *SPIx, SPI_Config_t *Config);
void MCAL_SPI_DeInit(SPI_Typedef_t *SPIx);

void MCAL_SPI_GPIO_Set_Pins(SPI_Typedef_t *SPIx);

void MCAL_SPI_Send_Data(SPI_Typedef_t *SPIx, uint16_t *pTxBuffer, enum Polling_Mechanism Polling_En);
void MCAL_SPI_Recieve_Data(SPI_Typedef_t *SPIx, uint16_t *pRxBuffer, enum Polling_Mechanism Polling_En);

void MCAL_SPI_TX_RX(SPI_Typedef_t *SPIx, uint16_t *pTxBuffer, enum Polling_Mechanism Polling_En);

#endif /* INC_STM32F103X6_SPI_DRIVER_H_ */
