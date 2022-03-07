/*
 * atmega32_SPI_driver.h
 *
 * Created: 3/6/2022 7:14:18 AM
 *  Author: Mina-Karam
 */ 


#ifndef ATMEGA32_SPI_DRIVER_H_
#define ATMEGA32_SPI_DRIVER_H_

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "atmega32_device_header.h"
#include "atmega32_GPIO_driver.h"

/* ================================================================ */
/* ============= User type definitions (structures) =============== */
/* ================================================================ */

typedef struct
{
	uint8 	SPI_Mode;					// specifies SPI MODE Master/Slave
										// This parameter must be set based on @ref SPI_MODE_DEFINE

	uint8	Communication_Mode;			// specifies SPI Communication mode
										// This parameter must be set based on @ref COMMUNICATION_MODE_DEFINE

	uint8	Frame_Format;				// specifies Data MSB transmit first or LSB transmit first
										// This parameter must be set based on @ref FRAME_FORMAT_DEFINE

	uint8	CLK_Polarity;				// specifies SPI clock Polarity Rising Falling or Falling Rising
										// This parameter must be set based on @ref CLK_POLARITY_DEFINE

	uint8	CLK_Phase;					// specifies SPI clock Phase Sample Setup or Setup Sample
										// This parameter must be set based on @ref CLK_PHASE_DEFINE
	
	uint8	CLK_Speed;					// specifies SPI clock speed Low or high
										// This parameter must be set based on @ref CLK_SPEED_DEFINE
	
	uint8	BaudRate_Prescaler;		    // specifiesRelationship between SCK and Oscillator Frequency
										// This parameter must be set based on @ref BAUDERATE_PRESCALER_DEFINE

	uint8	IRQ_Enable;					// specifies SPI IRQ
										// This parameter must be set based on @ref IRQ_ENABLE_DEFINE

	void (*P_IRQ_CallBack)(void);		//set the C Function which will be called once IRQ Happens

}SPI_Config_t;


/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

// @ref SPI_MODE_DEFINE
#define SPI_MODE_MASTER							(uint8) (1<<4) 	/* SPCR.Bit 4 – MSTR:?Master/Slave Select -> 1: Master configuration */
#define SPI_MODE_SLAVE							(uint8) (0) 	/* 											 0: Slave configuration  */

// @ref COMMUNICATION_MODE_DEFINE
#define COMMUNICATION_MODE_FULL_DUPLEX			(uint8) (0)
#define COMMUNICATION_MODE_3_WIRE				(uint8) (0)	

// @ref FRAME_FORMAT_DEFINE
#define FRAME_FORMAT_MSB_FIRST					(uint8) (0)		/* SPCR.Bit 5 – DORD:?Data Order -> 0: MSB transmitted first */
#define FRAME_FORMAT_LSB_FIRST					(uint8) (1<<5)	/* 									1: LSB transmitted first */

// @ref CLK_POLARITY_DEFINE
#define CLK_POLARITY_RISING_FALLING				(uint8) (0)		/* SPCR.Bit 3 – CPOL:?Clock Polarity -> 0: Rising Falling */
#define CLK_POLARITY_FALLING_RISING				(uint8) (1<<3)  /*								        1: Falling Rising */

// @ref CLK_PHASE_DEFINE
#define CLK_PHASE_SAMPLE_SETUP					(uint8) (0)		/* SPCR.Bit 2 – CPHA:?Clock Phase -> 0: Sample Setup */
#define CLK_PHASE_SETUP_SAMPLE					(uint8) (1<<2)	/* 									 1: Setup Sample */

// @ref CLK_SPEED_DEFINE
#define CLK_SPEED_LOW							(uint8) (0)
#define CLK_SPEED_HIGH							(uint8) (0)

// @ref BAUDERATE_PRESCALER_DEFINE
/* SPCR.Bits 1:0 – SPRn:?SPI Clock Rate Select */
#define BAUDERATE_PRESCALER_4					(uint8) (0<<0)
#define BAUDERATE_PRESCALER_16					(uint8) (1<<0)
#define BAUDERATE_PRESCALER_64					(uint8) (2<<0)
#define BAUDERATE_PRESCALER_128					(uint8) (3<<0)

/* SPSR.Bit 0 – SPI2X:?Double SPI Speed Bit */
#define BAUDERATE_PRESCALER_DOUBLE_SPEED_2		(uint8) (0<<0)
#define BAUDERATE_PRESCALER_DOUBLE_SPEED_8		(uint8) (1<<0)
#define BAUDERATE_PRESCALER_DOUBLE_SPEED_32		(uint8) (2<<0)
#define BAUDERATE_PRESCALER_DOUBLE_SPEED_64		(uint8) (3<<0)

// @ref IRQ_ENABLE_DEFINE
#define IRQ_ENABLE_NONE							(uint8) (0)		/* SPCRBit 7 – SPIE:?SPI Interrupt Enable -> 0: Disable */
#define IRQ_ENABLE								(uint8) (1<<7)	/* 									         1: Enable */

enum SPI_Polling_Mechanism
{
	SPI_disable,
	SPI_enable
};

/* ================================================================ */
/* =========== APIs Supported by "MCAL SPI DRIVER" ================ */
/* ================================================================ */


void MCAL_SPI_Init(SPI_Config_t *Config);
void MCAL_SPI_DeInit(void);

void MCAL_SPI_GPIO_Set_Pins(void);

void MCAL_SPI_Send_Data(uint8 *pTxBuffer, enum SPI_Polling_Mechanism Polling_En);
void MCAL_SPI_Recieve_Data(uint8 *pRxBuffer, enum SPI_Polling_Mechanism Polling_En);

void MCAL_SPI_TX_RX(uint8 *pTxBuffer, enum SPI_Polling_Mechanism Polling_En);

#endif /* ATMEGA32_SPI_DRIVER_H_ */