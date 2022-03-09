/*
 * stm32f103x6_I2C_driver.c
 *
 *  Created on: Mar 9, 2022
 *      Author: Mina-Karam
 */

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "stm32f103x6_I2C_driver.h"

/* ================================================================ */
/* ===================== Generic Variables ======================== */
/* ================================================================ */

I2C_Config_t G_I2C_Config[2] = {0};

/* ================================================================ */
/* ======================= Generic Macros ========================= */
/* ================================================================ */

#define I2C1_Index				0
#define I2C2_Index				1

/* ================================================================ */
/* ======================== Public APIs =========================== */
/* ================================================================ */

/* ================================================================
 * @Fn 				- MCAL_I2C_Init
 * @brief 			- Initializes I2Cx according to the specified parameters in I2C_Config
 * @param [in] 		- I2Cx : where x can be (1..2 depending on device used) to select I2C peripheral
 * @param [in] 		- I2C_Config : a pointer to I2C_Config_t structure that contains the configuration information for the specified I2C Module
 * @retval 			- None
 * Note 			- Supported for I2C SM mode only
 * 					- Support only 7-bit address mode
 */
void MCAL_I2C_Init(I2C_Typedef_t *I2Cx, I2C_Config_t *I2C_Config)
{
	uint16_t Temp_Register = 0 , Freq_Range = 0;
	uint32_t Pclk1 = 8000000;
	uint16_t Result = 0;

	/* 1. Enable the RCC Clock */
	if(I2Cx == I2C1)
	{
		/* If I2C1 Put all configurations in the global configuration */
		G_I2C_Config[I2C1_Index] = *I2C_Config;

		/* Open the I2C1 RCC Clock */
		RCC_I2C1_CLK_EN();
	}
	else if(I2Cx == I2C2)
	{
		/* If I2C2 Put all configurations in the global configuration */
		G_I2C_Config[I2C2_Index] = *I2C_Config;

		/* Open the I2C2 RCC Clock */
		RCC_I2C2_CLK_EN();
	}

	/* 2. Set I2C Mode */
	if(I2C_Config->Mode == I2C_MODE_I2C_MODE)
	{
		/* =================== Initialize Timing ==================== */
		/*
		 * --- I2C_CR2 -> Bits 5:0 FREQ[5:0]: Peripheral clock frequency
		 */
		/* 1. Get the I2Cx "CR2" Control register 2 Value */
		Temp_Register = I2Cx->CR2;

		/* 2. Clear frequency -> FREQ[5:0] bits */
		Temp_Register &= ~(I2C_CR2_FREQ_Msk); // (0x3FUL << 0)

		/* 3. Get Pclk1 frequency value */
		Pclk1 = MCAL_RCC_GetPCLK1Freq();

		/* 4. Set frequency bits depending in Pclk1 value */
		Freq_Range = (uint16_t)(Pclk1/1000000);

		/* 5. Move the configuration in the temp register to set it in the CR2 register */
		Temp_Register |= Freq_Range;

		/* 6. Set the "CR2" register with our new value */
		I2Cx->CR2 = Temp_Register;

		/* ========= Configure "I2C_CCR" Clock control register ========= */

		/* 7. Disable the selected I2C peripheral to configure time */
		I2Cx->CR1 &= ~(I2C_CR1_PE);

		/* 8. Put the temp register with zero ready to put data on it */
		Temp_Register = 0;

		/* 9. Configure the speed in the standard mode / Fast Mode */
		if((I2C_Config->Clock_Speed == I2C_CLOCK_SPEED_50KHZ)||(I2C_Config->Clock_Speed == I2C_CLOCK_SPEED_100KHZ))
		{
			/* 10. Enable standard mode but its zero as default */

			/* 11. Put the standard mode calculation */
			/*
			 * Tclk / 2 = CCR * Tpclk1
			 * CCR = Tclk / (2 * Tpclk1)
			 * CCR = Fpclk / (2 * I2C_ClockFrequency)
			 */
			Result = (uint16_t)(Pclk1/(I2C_Config->Clock_Speed << 1));

			/* 12. Move the configuration in the temp register to set it in the I2C_CCR register */
			Temp_Register |= Result;

			/* 13. Set the "I2C_CCR" register with our new value */
			I2Cx->CCR = Temp_Register;

			/* ========= Configure "I2C_TRISE" Rise time register ============ */
			/*
			 * For instance: in Sm mode, the maximum allowed SCL rise time is 1000 ns.
			 * If, in the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns
			 * therefore the TRISE[5:0] bits must be programmed with 09h.
			 * (1000 ns / 125 ns = 8 + 1)
			 */
			/* 14. Set the "I2C_TRISE" register with "Frequency Range + 1" as data sheet */
			I2Cx->TRISE = Freq_Range + 1;
		}
		else
		{
			/* Fast Mode not supported */
		}

		/* =================== End Timing Initialization  ==================== */

		/* ========================================================================================== */

		/* ========= Configure "I2C_CR1" Control register 1 ========= */

		/* 1. Get the I2C CR1 value */
		Temp_Register = I2Cx->CR1;

		/* 2. Set All configuration to the temp register  */
		Temp_Register |= (uint16_t)(I2C_Config->ACK_Control | I2C_Config->General_Call | I2C_Config->Mode | I2C_Config->Stretch_Mode);

		/* 3. Set the "I2C_CR1" register with our new value */
		I2Cx->CR1 = Temp_Register;

		/* ========================================================================================== */

		/* ========= Configure "I2C_OAR" Own address registers ========= */

		/* 1. Put the temp register with zero ready to put data on it */
		Temp_Register = 0;

		/* 2. Check the Slave_Address type & Configure depends on it */
		if(I2C_Config->Slave_Address.Enable_Dual_Address == 1)
		{
			/* 1. Enable the Dual addressing mode */
			Temp_Register = I2C_OAR2_ENDUAL;

			/* 2. Put the input Second address form the user to the register */
			/*
			 * Bits 7:1 ADD2[7:1]: Interface address
			 * 		bits 7:1 of address in dual addressing mode
			 */
			Temp_Register |= I2C_Config->Slave_Address.Slave_Second_Address << I2C_OAR2_ADD2_Pos; // Shifting with the first bit in the register

			/* 3. Set the "I2C_OAR2" register with our new value */
			I2Cx->OAR2 = Temp_Register;
		}

		/* 4. Put the temp register with zero ready to put data on it */
		Temp_Register = 0;

		/* 5. Put the input First address form the user to the register */
		Temp_Register |= I2C_Config->Slave_Address.Slave_First_Address << 1 ;

		/* 6. Configure ADDMODE Addressing mode (slave mode) */
		Temp_Register |= I2C_Config->Slave_Address.Slave_Address_Mode ;

		/* 7. Set the "I2C_OAR1" register with our new value */
		I2Cx->OAR1 = Temp_Register;
	}
	else
	{
		/* Not support I2C_MODE_SMBUS_MODE*/
	}


	/* 3. Interrupt mode (Slave Mode) ==> Check the callback pointer != NULL */
	if(I2C_Config->P_Slave_CallBack != NULL) // That enable slave IRQ states mode
	{
		/* 1. Enable IRQ */
		I2Cx->CR2 |= (I2C_CR2_ITERREN); // Error interrupt enable
		I2Cx->CR2 |= (I2C_CR2_ITEVTEN); // Event interrupt enable
		I2Cx->CR2 |= (I2C_CR2_ITBUFEN); // Buffer interrupt enable

		/* 2. Enable IRQ in NVIC */
		if(I2Cx == I2C1)
		{
			NVIC_IRQ31_I2C1_EV_IRQ_EN();
			NVIC_IRQ32_I2C1_ER_IRQ_EN();
		}
		else if (I2Cx == I2C2)
		{
			NVIC_IRQ33_I2C2_EV_IRQ_EN();
			NVIC_IRQ34_I2C2_ER_IRQ_EN();
		}

		/* 3. Put the status registers with zero */
		I2Cx->SR1 = 0;
		I2Cx->SR2 = 0;
	}

	/* 4. Enable the selected I2C peripheral */
	I2Cx->CR1 |= I2C_CR1_PE;
}

/* ================================================================
 * @Fn 				- MCAL_I2C_DeInit
 * @brief 			- Resets Selected I2C Module and disable NVIC IRQs
 * @param [in] 		- I2Cx : where x can be (1..2 depending on device used) to select I2C peripheral
 * @retval 			- None
 * Note 			- Reset The Module By RCC & Disable NVIC
 */
void MCAL_I2C_DeInit(I2C_Typedef_t *I2Cx)
{
	if (I2Cx == I2C1)
	{
		NVIC_IRQ31_I2C1_EV_IRQ_DI();
		NVIC_IRQ32_I2C1_ER_IRQ_DI();
		RCC_I2C1_RESET();
	}
	else if(I2Cx == I2C2)
	{
		NVIC_IRQ33_I2C2_EV_IRQ_DI();
		NVIC_IRQ34_I2C2_ER_IRQ_DI();
		RCC_I2C2_RESET();
	}
}

/* ================================================================
 * @Fn 				- MCAL_I2C_GPIO_Set_Pins
 * @brief 			- Initializes GPIO Pins to be connected with the selected I2C
 * @param [in] 		- I2Cx : where x can be (1..2 depending on device used) to select I2C peripheral
 * @retval 			- None
 * Note 			- Must open clock for AFIO & GPIO After GPIO Initialization
 * 					- Supported for I2C SM MODE only
 */
void MCAL_I2C_GPIO_Set_Pins(I2C_Typedef_t *I2Cx)
{
	GPIO_PinConfig_t I2C_GPIO_Config;

	/* Depending the recommendation in data sheet -> Table 27. I2C 	*/
	/*  "I2C pin-out"    "Configuration"     "GPIO configuration" 	*/
	if(I2Cx == I2C1)
	{
		/* PB6 : I2C1_SCL */
		I2C_GPIO_Config.GPIO_PinNumber = GPIO_PIN_6;
		I2C_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD;
		I2C_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &I2C_GPIO_Config);

		/* PB7 : I2C1_SDA */
		I2C_GPIO_Config.GPIO_PinNumber = GPIO_PIN_7;
		I2C_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD;
		I2C_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &I2C_GPIO_Config);
	}
	else if(I2Cx == I2C2)
	{
		/* PB10 : I2C2_SCL */
		I2C_GPIO_Config.GPIO_PinNumber = GPIO_PIN_10;
		I2C_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD;
		I2C_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &I2C_GPIO_Config);

		/* PB10 : I2C2_SDA */
		I2C_GPIO_Config.GPIO_PinNumber = GPIO_PIN_11;
		I2C_GPIO_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD;
		I2C_GPIO_Config.GPIO_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &I2C_GPIO_Config);
	}
}

/* ================================================================
 * @Fn 				- MCAL_I2C_MASTER_TX
 * @brief 			- Master Send data with I2C
 * @param [in] 		- I2Cx : where x can be (1..2 depending on device used) to select I2C peripheral
 * @param [in] 		- Device_Address : slave address
 * @param [in] 		- pTxData : a pointer to the data which will be send
 * @param [in] 		- Data_Length : number of data bytes to be Transmitted
 * @param [in] 		- Stop : select send stop bit or not
 * @param [in] 		- Start : select send start or repeated start
 * @retval 			- None
 * Note 			- None
 */
void MCAL_I2C_MASTER_TX(I2C_Typedef_t *I2Cx, uint16_t Device_Address, uint8_t *pTxData, uint8_t Data_Length, STOP_Condition Stop, START_Condition Start)
{
	int i = 0;

	/* TODO Support timeout (configure timer working for specific duration rise interrupt)
	 * TODO Timer_interrupt(){flag =}
	 * TODO so any code exist in while (check flag || any polling conditions)
	 */
	/* 1. Set the start bit in the I2C_CR1 register to generate a start condition from this will start as master */
	I2C_Generate_Start(I2Cx, Start, Enable);

	/* 2. Wait for EV5 */
	/* EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address. */
	while(!(I2C_Get_FlagStatus(I2Cx, SB)));

	/* 3. Writing DR register with Address, Send Address */
	I2C_Send_Address(I2Cx, Device_Address, Transmitter);

	/* 4. Wait for EV6 */
	/* EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2. */
	while(!(I2C_Get_FlagStatus(I2Cx, ADDR)));

	/* 5. Wait for EV8_1 */
	/* EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR. */
	/* Check for TRA: Transmitter/receiver, BUSY: Bus busy, MSL: Master/slave, TxE Flags */
	while(!(I2C_Get_FlagStatus(I2Cx, Master_Transmitter_Event)));

	/* Loop inside the data ready to send it */
	for (i = 0; i < Data_Length; ++i)
	{
		/* 6. Write in the DR register the data to be sent */
		I2Cx->DR = pTxData[i];

		/* 7. Wait for EV8 */
		/* EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register. */
		while(!(I2C_Get_FlagStatus(I2Cx, TXE)));
		/* 8. Wait for EV8 */
		/* EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition. */
	}

	/* 9. Send Stop Condition */
	if(Stop == With_STOP)
	{
		I2C_Stop(I2Cx, Enable);
	}
}

/* ================================================================
 * @Fn 				- MCAL_I2C_MASTER_RX
 * @brief 			- Master Receive data with I2C
 * @param [in] 		- I2Cx : where x can be (1..2 depending on device used) to select I2C peripheral
 * @param [in] 		- Device_Address : slave address
 * @param [in] 		- pRxData : a pointer to the data which will be send
 * @param [in] 		- Data_Length : number of data bytes to be Received
 * @param [in] 		- Stop : select send stop bit or not
 * @param [in] 		- Start : select send start or repeated start
 * @retval 			- None
 * Note 			- None
 */
void MCAL_I2C_MASTER_RX(I2C_Typedef_t *I2Cx, uint16_t Device_Address, uint8_t *pRxData, uint8_t Data_Length, STOP_Condition Stop, START_Condition Start)
{
	int i = 0;

	uint8_t index = I2Cx == I2C1 ? I2C1_Index : I2C2_Index;
	/* TODO Support timeout (configure timer working for specific duration rise interrupt)
	 * TODO Timer_interrupt(){flag =}
	 * TODO so any code exist in while (check flag || any polling conditions)
	 */
	/* 1. Set the start bit in the I2C_CR1 register to generate a start condition from this will start as master */
	I2C_Generate_Start(I2Cx, Start, Enable);

	/* 2. Wait for EV5 */
	/* EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address. */
	while(!(I2C_Get_FlagStatus(I2Cx, SB)));

	/* 3. Writing DR register with Address, Send Address */
	I2C_Send_Address(I2Cx, Device_Address, Receiver);

	/* 4. Wait for EV6 */
	/* EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2. */
	while(!(I2C_Get_FlagStatus(I2Cx, ADDR)));

	/* 5. Enable Automatic ACK */
	/* To get ready to send ACK */
	I2C_ACKConfig(I2Cx, Enable);

	/* 6. Check if there is Data length available */
	if(Data_Length)
	{
		/* 7. Loop inside the data to read it till length become zero */
		for (i = Data_Length; i > 1 ; i--)
		{
			/* 8. Wait for EV7 */
			/* EV7: RxNE=1 cleared by reading DR register */
			while(!(I2C_Get_FlagStatus(I2Cx, RXNE)));

			/* 9. Read the data in the DR register */
			*pRxData = I2Cx->DR;

			/* 10. Go to next address */
			pRxData++;
		}
	}

	/* 11. After getting all data received send ACK , to stop it */
	/* To generate the non-acknowledge pulse after the last received data byte, the ACK bit
		must be cleared just after reading the second last data byte (after second last RxNE
		event).
	 */
	/* Send ---- > NACK */
	I2C_ACKConfig(I2Cx, Disable);

	/* 12. Send Stop Condition */
	if(Stop == With_STOP)
	{
		I2C_Stop(I2Cx, Enable);
	}

	/* 13. Re-Enable the automatic ACK */
	if(G_I2C_Config[index].ACK_Control == I2C_ACK_CONTROL_ENABLE)
		I2C_ACKConfig(I2Cx, Enable);
	else
		I2C_ACKConfig(I2Cx, Disable);
}

/* ================================================================
 * @Fn 				- MCAL_I2C_Slave_TX
 * @brief 			- Slave send data to master using interrupt mechanism
 * @param [in] 		- I2Cx : where x can be (1..2 depending on device used) to select I2C peripheral
 * @param [in] 		- TxData : slave data to be sent to master
 * @retval 			- None
 * Note 			- Support interrupt mechanism only
 */
void MCAL_I2C_Slave_TX(I2C_Typedef_t *I2Cx, uint8_t TxData)
{
	I2Cx->DR = TxData;
}

/* ================================================================
 * @Fn 				- MCAL_I2C_Slave_RX
 * @brief 			- Slave Receive data from master using interrupt mechanism
 * @param [in] 		- I2Cx : where x can be (1..2 depending on device used) to select I2C peripheral
 * @retval 			- Received data
 * Note 			- Support interrupt mechanism only
 *
 */
uint8_t MCAL_I2C_Slave_RX(I2C_Typedef_t *I2Cx)
{
	return (I2Cx->DR);
}


/* ================================================================ */
/* ======================== Generic APIs ========================== */
/* ================================================================ */


I2C_Flagstatus I2C_Get_FlagStatus(I2C_Typedef_t *I2Cx, Status Flag)
{
	//vuint32_t Dummy_Read = 0; // Volatile for compiler optimization
	uint32_t Flag_1 = 0, Flag_2 = 0, Last_Event;
	I2C_Flagstatus Bit_Status = RESET;

	switch (Flag)
	{
	case BUS_BUSY:
	{
		/*  Bit 1 BUSY: Bus busy
				0: No communication on the bus
				1: Communication ongoing on the bus
				– Set by hardware on detection of SDA or SCL low
				– cleared by hardware on detection of a Stop condition.
				It indicates a communication in progress on the bus. This information is still updated when the interface is disabled (PE=0).
		 */
		if((I2Cx->SR2) & (I2C_SR2_BUSY))
			Bit_Status = SET;
		else
			Bit_Status = RESET;
		break;
	}

	case SB:
	{
		/*
		 * Bit 0 SB: Start bit (Master mode)
					0: No Start condition
					1: Start condition generated.
			   – Set when a Start condition generated.
			   – Cleared by software by reading the SR1 register followed by writing the DR register, or by hardware when PE=0
		 */
		if((I2Cx->SR1) & (I2C_SR1_SB))
			Bit_Status = SET;
		else
			Bit_Status = RESET;
		break;
	}

	case ADDR:
	{
		/*
		 * 	Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
				This bit is cleared by software reading SR1 register followed reading SR2, or by hardware when PE=0.

				Address matched (Slave)
				0: Address mismatched or not received.
				1: Received address matched.
				– Set by hardware as soon as the received slave address matched with the OAR registers
				content or a general call (when enabled depending on configuration).
				Note: In slave mode, it is recommended to perform the complete clearing sequence (READ
				SR1 then READ SR2) after ADDR is set.

				Address sent (Master)
				0: No end of address transmission
				1: End of address transmission
				– For 10-bit addressing, the bit is set after the ACK of the 2nd byte.
				– For 7-bit addressing, the bit is set after the ACK of the byte.

				Note: ADDR is not set after a NACK reception
		 */
		if((I2Cx->SR1) & (I2C_SR1_ADDR))
			Bit_Status = SET;
		else
			Bit_Status = RESET;

		/* This bit is cleared by software reading SR1 register followed reading SR2, or by hardware when PE=0. */
		//Dummy_Read = I2Cx->SR2;
		break;
	}

	case TXE:
	{
		/*
		 *  Bit 7 TxE: Data register empty (transmitters)
				0: Data register not empty
				1: Data register empty
				– Set when DR is empty in transmission. TxE is not set during address phase.
				– Cleared by software writing to the DR register or by hardware after a start or a stop condition or when PE=0.
				TxE is not set if either a NACK is received, or if next byte to be transmitted is PEC (PEC=1)
				Note: TxE is not cleared by writing the first data being transmitted, or by writing data when
				BTF is set, as in both cases the data register is still empty.
		 */
		if((I2Cx->SR1) & (I2C_SR1_TXE))
			Bit_Status = SET;
		else
			Bit_Status = RESET;
		break;
	}

	case RXNE :
	{
		/*
		 *  Bit 6 RxNE: Data register not empty (receivers)
				0: Data register empty
				1: Data register not empty
				– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
				– Cleared by software reading or writing the DR register or by hardware when PE=0.
				RxNE is not set in case of ARLO event.
				Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full.
		 */
		if((I2Cx->SR1) & (I2C_SR1_RXNE))
			Bit_Status = SET;
		else
			Bit_Status = RESET;
		break;
	}

	case Master_Transmitter_Event :
	{
		/* Check if BUSY ,TRA ,MSL W,TXE flags are all set */

		/*Read the I2C status register */
		Flag_1 = Master_Transmitter_Event & (0x0000FFFF);
		Flag_2 = Master_Transmitter_Event >> 16;

		/* Get the last event value form the I2C status register */
		Last_Event = ((I2Cx->SR1 & Flag_1) | ((I2Cx->SR2 & Flag_2) << 16) );

		if(Last_Event == Flag)
			Bit_Status = SET;
		else
			Bit_Status = RESET;
		break;
	}

	default:
		break;
	}
	return Bit_Status;
}

void I2C_Generate_Start(I2C_Typedef_t *I2Cx,START_Condition Start, Functional_State State)
{
	/* Check the type of start (Start or Repeated Start) */
	if(Start != Repeated_START)
	{
		/* Check if the bus is idle */
		while(I2C_Get_FlagStatus(I2Cx, BUS_BUSY));
	}

	/* Write start condition */
	/*
	 *	Bit 8 START: Start generation
		This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
		In Master Mode:
		0: No Start generation
		1: Repeated start generation
		In Slave mode:
		0: No Start generation
		1: Start generation when the bus is free
	 */
	if(State != Disable)
	{
		/* Generate a START condition */
		I2Cx->CR1 |= I2C_CR1_START;
	}
	else
	{
		/* Disable the START condition generation */
		I2Cx->CR1 &= ~(I2C_CR1_START);
	}

}

void I2C_Send_Address(I2C_Typedef_t *I2Cx, uint16_t Device_Address,I2C_Direction Direction)
{
	/* Support 7-bit address mode only */
	if(Direction == Receiver)
	{
		/* Set the address bit 0 for read */
		I2Cx->DR = ((Device_Address << 1) | (0x01));
	}
	else if(Direction == Transmitter)
	{
		/* Reset the address bit 0 for write */
		I2Cx->DR = (Device_Address << 1);
	}
}

void I2C_Stop(I2C_Typedef_t *I2Cx, Functional_State State)
{
	if(State == Enable)
	{
		/* Generate a stop condition, Enable stop bit */
		I2Cx->CR1 |= (I2C_CR1_STOP);
	}
	else
	{
		/* Disable the stop condition generation, Disable stop bit */
		I2Cx->CR1 &= ~(I2C_CR1_STOP);
	}
}

void I2C_ACKConfig(I2C_Typedef_t *I2Cx, Functional_State State)
{
	if(State == Enable)
	{
		/* Enable Automatic ACK */
		I2Cx->CR1 |= (I2C_CR1_ACK);
	}
	else
	{
		/* Disable Automatic ACK */
		I2Cx->CR1 &= ~(I2C_CR1_ACK);
	}
}

/* ================================================================ */
/* ================= IRQ Function Definitions ===================== */
/* ================================================================ */

void I2C1_EV_IRQHandler(void)
{
	//vuint32_t Dummy_Read = 0; // Volatile for compiler optimization

	/* Interrupt handling for both master and slave mode of the device */
	uint32_t Temp_1, Temp_2, Temp_3;

	Temp_1 = (I2C1->CR2 & (I2C_CR2_ITEVTEN));	// Event interrupt enable
	Temp_2 = (I2C1->CR2 & (I2C_CR2_ITBUFEN));	// Buffer interrupt enable
	Temp_3 = (I2C1->SR1 & (I2C_SR1_STOPF));		// Stop detection (slave mode)

	/* Handle Stop Condition Event */
	if(Temp_1 && Temp_3)
	{
		/* STOPF Cleared by software reading the SR1 register followed by a write in the CR1 register,
		 * i have already read SR1 in Temp_3
		 * then next statement i write to CR1
		 */
		I2C1->CR1 |= 0x0000;
		G_I2C_Config[I2C1_Index].P_Slave_CallBack(I2C_EV_STOP);
	}

	/* =============================================================================== */

	/* Handle Received address matched. */
	Temp_3 = (I2C1->SR1 & (I2C_SR1_ADDR));		//ADDR
	if(Temp_1 && Temp_3)
	{
		/* clear ADDR flag
		 * In slave mode, it is recommended to perform the complete clearing sequence (READ SR1 then READ SR2) after ADDR is set.
		 */
		//Dummy_Read  = I2C1->SR1;
		//Dummy_Read  = I2C1->SR2;

		/* Check master mode or slave mode */
		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			/* Master mode (Using polling mechanism not interrupt) */
		}
		else
		{
			/* Slave mode */
			G_I2C_Config[I2C1_Index].P_Slave_CallBack(I2C_EV_ADD_MATCHED);
		}

	}

	/* =============================================================================== */

	/* Handle TxE: Data register empty (Master request data from slave)--> slave_transmitter */
	Temp_3 = (I2C1->SR1 & (I2C_SR1_TXE));		// TXE
	if(Temp_1 && Temp_2 && Temp_3)				// In case TXE=1, ITEVTEN=1, ITBUFEN=1
	{
		/* Check master mode or slave mode */
		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			/* Master mode (Using polling mechanism not interrupt) */
		}
		else
		{
			/* Slave mode */
			/* Check if slave in transmit mode */
			if(I2C1->SR2 & (I2C_SR2_TRA))		//TRA: Transmitter/receiver: 1: Data bytes transmitted
			{
				G_I2C_Config[I2C1_Index].P_Slave_CallBack(I2C_EV_DATA_REQ);
			}
		}
	}

	/* =============================================================================== */

	/* Handle RxNE: Data register not empty (slave receive data)-->slave_Receiver */
	Temp_3 = (I2C1->SR1 & (I2C_SR1_RXNE));		// RXNE
	if(Temp_1 && Temp_2 && Temp_3)				// In case RXNE=1, ITEVTEN=1, ITBUFEN=1
	{
		/* Check master mode or slave mode */
		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			/* Master mode (Using polling mechanism not interrupt) */
		}
		else
		{
			/* Slave mode */
			if(!(I2C1->SR2 & (I2C_SR2_TRA)))		//TRA: Transmitter/receiver: 0: Data bytes received
			{
				G_I2C_Config[I2C1_Index].P_Slave_CallBack(I2C_EV_DATA_RCV);
			}
		}
	}
}

void I2C1_ER_IRQHandler(void)
{

}


void I2C2_EV_IRQHandler(void)
{

}


void I2C2_ER_IRQHandler(void)
{

}
