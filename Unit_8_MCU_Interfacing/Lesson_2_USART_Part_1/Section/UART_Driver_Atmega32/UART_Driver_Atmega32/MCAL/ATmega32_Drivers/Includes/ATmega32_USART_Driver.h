/*
 * ATmega32_USART_Driver.h
 *
 * Created: 2/25/2022 6:08:18 AM
 *  Author: Mina-Karam
 */ 


#ifndef ATMEGA32_USART_DRIVER_H_
#define ATMEGA32_USART_DRIVER_H_

#include "ATmega32_Device_Header.h"

/* ========================================================= */
/* =============== Configuration References ================ */
/* ========================================================= */
typedef enum
{
	USART_Asyn_Normal,
	USART_Asyn_DoupleSpeed,
	USART_Sync_Master,
}USART_Mode;

typedef enum
{
	USART_Disable,
	USART_Receiver,
	USART_Transmitter,
	USART_Receiver_Transmitter,
}USART_Micro_State;

typedef enum
{
	USART_Interrupt_Disable,
	USART_RxComplete_Enable,
	USART_TxComplete_Enable,
	USART_UDR_Enable,
	USART_Rx_Tx_Complete_Enable,
	USART_RX_Complete_UDR_Enable,
	USART_Tx_Complete_UDR_Enable,
	USART_All_Interrupt_Enable,
}USART_Interrupt_Source;
typedef enum
{
	Size_5bit,
	Size_6bit,
	Size_7bit,
	Size_8bit,
	Size_9bit,
}USART_Character_Size;

typedef enum
{
	USART_SingleProcessor,
	USART_MultiProcessor,
}USART_Communication_Processor;

typedef enum
{
	USART_NoError,
	USART_ParityError,
	USART_DataOverRunError,
	USART_FrameError,
}USART_ErrorsType;

typedef enum
{
	USART_SamplingOnFaling,
	USART_SamplingOnRising,
}USART_Clock_Parity;

typedef enum
{
	USART_Parity_Disable_1StopBit,
	USART_Parity_Disable_2StopBit,
	USART_Parity_Even_1StopBit,
	USART_Parity_Even_2StopBit,
	USART_Parity_Odd_1StopBit,
	USART_Parity_Odd_2StopBit,
}USART_Frame_Control;

/* ================================================================ */
/* =============== User type definitions (structures) ============= */
/* ================================================================ */

typedef struct
{
	USART_Micro_State             Micro_State;
	USART_Mode                    Communcation_Mode;
	USART_Communication_Processor Communication_Processor;
	USART_Interrupt_Source        Interrupt_Source;
	USART_Character_Size          Character_Size;
	USART_Frame_Control           Frame_Control;
	USART_Clock_Parity            Clock_Parity;
	uint16						  Baud_Rate:10;
	USART_ErrorsType              Error_Type;
}USART_Config_t;

/* ================================================================ */
/* ============= APIs Supported by "MCAL USART DRIVER" ============ */
/* ================================================================ */
extern USART_Config_t USART;

void MCAL_USART_Init(void);

void MCAL_USART_Send(uint16 data);
uint16 MCAL_USART_Receive (void);

#endif /* ATMEGA32_USART_DRIVER_H_ */