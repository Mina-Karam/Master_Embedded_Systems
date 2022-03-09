/*
 * stm32f103x6_I2C_driver.h
 *
 *  Created on: Mar 9, 2022
 *      Author: Mina-Karam
 */

#ifndef INC_STM32F103X6_I2C_DRIVER_H_
#define INC_STM32F103X6_I2C_DRIVER_H_

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "stm32f103x6.h"
#include "stm32f103x6_GPIO_driver.h"
#include "stm32f103x6_RCC_driver.h"

/* ================================================================ */
/* ============= User type definitions (structures) =============== */
/* ================================================================ */

typedef struct
{
	uint32_t	Enable_Dual_Address;		  	//Enable : 1, Disable	: 0
	uint8_t		Slave_First_Address;
	uint8_t		Slave_Second_Address;
	uint32_t	Slave_Address_Mode;			   	// This parameter must be set based on @ref I2C_SLAVE_ADDRESS_MODE_DEFINE
}I2C_slave_address_t;



typedef enum
{
	I2C_EV_STOP,
	I2C_EV_ADD_MATCHED,
	I2C_EV_DATA_REQ,							// APP_Layer should send data (I2C slave send data)
	I2C_EV_DATA_RCV								// APP_Layer should receive data (I2C slave receive data)
}Slave_State;

typedef struct
{
	uint32_t	Clock_Speed;					// Specifies I2C clock speed
												// This parameter must be set based on @ref I2C_CLOCK_SPEED_DEFINE

	uint32_t	Stretch_Mode;					// specifies Enable or Disable clock stretching in slave mode only
												// This parameter must be set based on @ref I2C_STRETCH_MODE_DEFINE

	uint32_t	General_Call;					// specifies Enable or Disable General_Call
												// This parameter must be set based on @ref I2C_GENERAL_CALL_DEFINE

	uint32_t	Master_Mode;					// specifies I2C Master mode SM mode or FM mode
												// This parameter must be set based on @ref I2C_MASTER_MODE_DEFINE

	uint32_t	Mode;							// specifies I2C SMBUS mode or I2C mode
												// This parameter must be set based on @ref I2C_MODE_DEFINE

	uint32_t	ACK_Control;					// Enable ACK by Hardware or Disable ACK
												// This parameter must be set based on @ref I2C_ACK_CONTROL_DEFINE

	I2C_slave_address_t		Slave_Address;		// Slave address information from user


	void(*P_Slave_CallBack)(Slave_State state); // Set the C Function which will be called once IRQ Happens

}I2C_Config_t;

/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

//@ref I2C_CLOCK_SPEED_DEFINE
/* Standard Speed (up to 100 kHz)
 * Fast Speed (up to 400 kHz)
 * to configure clock before enable the peripheral
 * I2C_CR2 -> Bits 5:0 FREQ[5:0]: Peripheral clock frequency
 * • Configure the clock control registers
 *     T_high = CCR * Tpclk1
 * • Configure the rise time register
 */
#define I2C_CLOCK_SPEED_50KHZ					(50000U)
#define I2C_CLOCK_SPEED_100KHZ					(100000U)


//@ref I2C_STRETCH_MODE_DEFINE
/* I2C_CR1
 * Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
 * This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
 * it is reset by software.
 * 0: Clock stretching enabled
 * 1: Clock stretching disabled
 */
#define I2C_STRETCH_MODE_ENABLE				(uint32_t)(0)
#define I2C_STRETCH_MODE_DISABLE			(uint32_t)(1<<7)

//@ref I2C_GENERAL_CALL_DEFINE
/* I2C_CR1
 * Bit 6 ENGC: General call enable
 * 0: General call disabled. Address 00h is NACKed.
 * 1: General call enabled. Address 00h is ACKed
 */
#define I2C_GENERAL_CALL_ENABLE					(uint32_t)(1<<6)
#define I2C_GENERAL_CALL_DISABLE				(uint32_t)(0)

// @ref I2C_MASTER_MODE_DEFINE
/* I2C_CCR
 * Bit 15 F/S: I2C master mode selection
 * 0: Sm mode I2C
 * 1: Fm mode I2C
 */
#define I2C_MASTER_MODE_SM						(uint32_t)(0)
#define I2C_MASTER_MODE_FM						(uint32_t)(1<<15)

//@ref I2C_MODE_DEFINE
/* I2C_CR1
 * Bit 1 SMBUS: SMBus mode
 * 0: I2C mode
 * 1: SMBus mode
 */
#define I2C_MODE_I2C_MODE						(uint32_t)(0)
#define I2C_MODE_SMBUS_MODE						(uint32_t)(1<<1)

//@ref I2C_SLAVE_ADDRESS_MODE_DEFINE
/* I2C_OAR1
 * Bit 15 ADDMODE Addressing mode (slave mode)
 * 0: 7-bit slave address (10-bit address not acknowledged)
 * 1: 10-bit slave address (7-bit address not acknowledged)
 */
#define I2C_SLAVE_ADDRESS_MODE_7_BIT			(uint32_t)(0)
#define I2C_SLAVE_ADDRESS_MODE_10_BIT			(uint32_t)(1<<15)

//@ref I2C_ACK_CONTROL_DEFINE
/* I2C_CR1
 * Bit 10 ACK: Acknowledge enable
 * This bit is set and cleared by software and cleared by hardware when PE=0.
 * 0: No acknowledge returned
 * 1: Acknowledge returned after a byte is received (matched address or data)
 */
#define I2C_ACK_CONTROL_ENABLE					(uint32_t)(1<<10)
#define I2C_ACK_CONTROL_DISABLE					(uint32_t)(0)

/* ================================================================================== */

/* I2C MODE SELECTION  */
#define I2C_MASTER_MODE
//#define I2C_SLAVE_MODE


typedef enum
{
	RESET,
	SET
}I2C_Flagstatus;


typedef enum
{
	BUS_BUSY,												/* BUSY: Bus busy 1: Communication ongoing on the bus */
	SB,														/* SB: Start bit (Master mode) 1: Start condition generated. */
	ADDR,													/* ADDR: Address sent (master mode)/matched (slave mode) */
	TXE,													/* TxE: Data register empty (transmitters) */
	RXNE,													/* RxNE: Data register not empty (receivers) */
	Master_Transmitter_Event = ((uint32_t)(0x00070080))		/* Check if BUSY ,TRA ,MSL W,TXE flags are all set */
}Status;


typedef enum
{
	With_STOP,
	Without_STOP
}STOP_Condition;


typedef enum
{
	START,
	Repeated_START
}START_Condition;


typedef enum
{
	Disable,
	Enable
}Functional_State;


typedef enum
{
	Transmitter,
	Receiver
}I2C_Direction;

/* ================================================================ */
/* =========== APIs Supported by "MCAL SPI DRIVER" ================ */
/* ================================================================ */

void MCAL_I2C_Init(I2C_Typedef_t *I2Cx, I2C_Config_t *I2C_Config);
void MCAL_I2C_DeInit(I2C_Typedef_t *I2Cx);

void MCAL_I2C_GPIO_Set_Pins(I2C_Typedef_t *I2Cx);

/*
 * Master Polling Mechanism
 */
void MCAL_I2C_MASTER_TX(I2C_Typedef_t *I2Cx, uint16_t Device_Address, uint8_t *pTxData, uint8_t Data_Length, STOP_Condition Stop, START_Condition Start);
void MCAL_I2C_MASTER_RX(I2C_Typedef_t *I2Cx, uint16_t Device_Address, uint8_t *pRxData, uint8_t Data_Length, STOP_Condition Stop, START_Condition Start);


/*
 * Slave Interrupt Mechanism
 */
void MCAL_I2C_Slave_TX(I2C_Typedef_t *I2Cx, uint8_t TxData);
uint8_t MCAL_I2C_Slave_RX(I2C_Typedef_t *I2Cx);


/*
 * Generic APIs
 */
I2C_Flagstatus I2C_Get_FlagStatus(I2C_Typedef_t *I2Cx, Status Flag);

void I2C_Generate_Start(I2C_Typedef_t *I2Cx,START_Condition Start, Functional_State State);
void I2C_Send_Address(I2C_Typedef_t *I2Cx, uint16_t Device_Address,I2C_Direction Direction);
void I2C_Stop(I2C_Typedef_t *I2Cx, Functional_State State);
void I2C_ACKConfig(I2C_Typedef_t *I2Cx, Functional_State State);


#endif /* INC_STM32F103X6_I2C_DRIVER_H_ */
