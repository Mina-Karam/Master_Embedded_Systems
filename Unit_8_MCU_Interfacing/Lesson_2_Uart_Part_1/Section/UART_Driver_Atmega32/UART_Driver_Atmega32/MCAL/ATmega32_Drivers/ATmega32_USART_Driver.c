/*
 * ATmega32_USART_Driver.c
 *
 * Created: 2/25/2022 6:08:39 AM
 *  Author: Mina-Karam
 */ 

#include "ATmega32_USART_Driver.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif // F_CPU
USART_Config_t USART = {0};

void MCAL_USART_Init(void)
{
	uint8 UCSRA_Temp = 0;
	uint8 UCSRB_Temp = 0;
	uint8 UCSRC_Temp = 0;
	float32_t UBBR_Temp = 0.0;
	
	switch(USART.Micro_State)
	{
		case USART_Disable:
			CLR_BIT(UCSRB_Temp,RXEN);
			CLR_BIT(UCSRB_Temp,TXEN);
			break;
			
		case USART_Receiver:
			SET_BIT(UCSRB_Temp,RXEN);
			CLR_BIT(UCSRB_Temp,TXEN);
			break;
			
		case USART_Transmitter:
			CLR_BIT(UCSRB_Temp,RXEN);
			SET_BIT(UCSRB_Temp,TXEN);
			break;
			
		case USART_Receiver_Transmitter:
			SET_BIT(UCSRB_Temp,RXEN);
			SET_BIT(UCSRB_Temp,TXEN);
			break;
			
		default:
			break;
	}
	switch(USART.Communcation_Mode)
	{
		case USART_Asyn_Normal:
			CLR_BIT(UCSRC_Temp,UMSEL);
			CLR_BIT(UCSRA_Temp,U2X);
			CLR_BIT(UCSRC_Temp,UCPOL);
			UBBR_Temp = ((float32_t)F_CPU)/(16.0 * USART.Baud_Rate) - 0.5;
			break;
			
		case USART_Asyn_DoupleSpeed:
			CLR_BIT(UCSRC_Temp,UMSEL);
			SET_BIT  (UCSRA_Temp,U2X);
			CLR_BIT(UCSRC_Temp,UCPOL);
			UBBR_Temp = ((float32_t)F_CPU)/(8.0 * USART.Baud_Rate) - 0.5;
			break;
			
		case USART_Sync_Master:
			SET_BIT  (UCSRC_Temp,UMSEL);
			CLR_BIT(UCSRA_Temp,U2X);
			UBBR_Temp = ((float32_t)F_CPU)/(2.0 * USART.Baud_Rate) - 0.5;
			
		switch(USART.Clock_Parity)
		{
			case USART_SamplingOnFaling:
				CLR_BIT(UCSRC_Temp,UCPOL);
				break;
				
			case USART_SamplingOnRising:
				SET_BIT(UCSRC_Temp,UCPOL);
				break;
				
			default:
				break;
		}
		
			break;
			
		default:
			break;
	}
	switch(USART.Communication_Processor)
	{
		case USART_SingleProcessor:
			CLR_BIT(UCSRA_Temp,MPCM);
			break;
			
		case USART_MultiProcessor:
			SET_BIT(UCSRA_Temp,MPCM);
			break;
			
		default:
			break;
	}
	switch(USART.Interrupt_Source)
	{
		SET_BIT(SREG,I_Bit);
		
		case USART_Interrupt_Disable:
			break;
		
		case USART_RxComplete_Enable:
			SET_BIT(UCSRB_Temp,RXCIE);
			break;
		
		case USART_TxComplete_Enable:
			SET_BIT(UCSRB_Temp,TXCIE);
			break;
		
		case USART_UDR_Enable:
			SET_BIT(UCSRB_Temp,UDRIE);
			break;
		
		case USART_RX_Complete_UDR_Enable:
			SET_BIT(UCSRB_Temp,RXCIE);
			SET_BIT(UCSRB_Temp,UDRIE);
			break;
		
		case USART_Tx_Complete_UDR_Enable:
			SET_BIT(UCSRB_Temp,TXCIE);
			SET_BIT(UCSRB_Temp,UDRIE);
			break;
		
		case USART_All_Interrupt_Enable:
			SET_BIT(UCSRB_Temp,RXCIE);
			SET_BIT(UCSRB_Temp,TXCIE);
			SET_BIT(UCSRB_Temp,UDRIE);
			break;
		
		default:
			break;
	}
	switch(USART.Character_Size)
	{
		case Size_5bit:
			CLR_BIT(UCSRB_Temp,UCSZ2);
			CLR_BIT(UCSRC_Temp,UCSZ1);
			CLR_BIT(UCSRC_Temp,UCSZ0);
			break;
			
		case Size_6bit:
			CLR_BIT(UCSRB_Temp,UCSZ2);
			CLR_BIT(UCSRC_Temp,UCSZ1);
			SET_BIT(UCSRC_Temp,UCSZ0);
			break;
			
		case Size_7bit:
			CLR_BIT(UCSRB_Temp,UCSZ2);
			SET_BIT(UCSRC_Temp,UCSZ1);
			CLR_BIT(UCSRC_Temp,UCSZ0);
			break;
			
		case Size_8bit:
			CLR_BIT(UCSRB_Temp,UCSZ2);
			SET_BIT(UCSRC_Temp,UCSZ1);
			SET_BIT(UCSRC_Temp,UCSZ0);
			break;
			
		case Size_9bit:
			SET_BIT(UCSRB_Temp,UCSZ2);
			SET_BIT(UCSRC_Temp,UCSZ1);
			SET_BIT(UCSRC_Temp,UCSZ0);
			break;
			
		default:
			break;
			
	}
	switch(USART.Frame_Control)
	{
		case USART_Parity_Disable_1StopBit:
			CLR_BIT(UCSRC_Temp,UPM1);
			CLR_BIT(UCSRC_Temp,UPM0);
			CLR_BIT(UCSRC_Temp,USBS);
			break;
			
		case USART_Parity_Disable_2StopBit:
			CLR_BIT(UCSRC_Temp,UPM1);
			CLR_BIT(UCSRC_Temp,UPM0);
			SET_BIT(UCSRC_Temp,USBS);
			break;
			
		case USART_Parity_Even_1StopBit:
			SET_BIT(UCSRC_Temp,UPM1);
			CLR_BIT(UCSRC_Temp,UPM0);
			CLR_BIT(UCSRC_Temp,USBS);
			break;
		
		case USART_Parity_Even_2StopBit:
			SET_BIT(UCSRC_Temp,UPM1);
			CLR_BIT(UCSRC_Temp,UPM0);
			SET_BIT(UCSRC_Temp,USBS);
			break;
			
		case USART_Parity_Odd_1StopBit:
			SET_BIT(UCSRC_Temp,UPM1);
			SET_BIT(UCSRC_Temp,UPM0);
			CLR_BIT(UCSRC_Temp,USBS);
			break;
			
		case USART_Parity_Odd_2StopBit:
			SET_BIT(UCSRC_Temp,UPM1);
			SET_BIT(UCSRC_Temp,UPM0);
			SET_BIT(UCSRC_Temp,USBS);
			break;
			
		default:
			break;
	}
		
	UBRRH = ((uint16)UBBR_Temp) >> 8; /* Shift right to get the most bits of UBBR */
	UBRRL = ((uint16)UBBR_Temp);
	UCSRA = UCSRA_Temp;
	UCSRC = UCSRC_Temp;
	UCSRB = UCSRB_Temp; /* Put in the last because on it the enable bit of the UART */
}

void MCAL_USART_Send(uint16 data)
{
	while(GET_BIT(UCSRA,UDRE) == 0);
	
	if(USART.Character_Size == Size_9bit)
	{
		/*
		* UCSRB & 1111 1110 to make sure the bit 0 is reset to hold the new value because it does not mention in data sheet
		* we need to take the bit 9  in the data and hold it in the bit 0  in the UCSRB so we & the data with 8 to get
		*  and shift it again to put in the position of the bit 0
		*/
		UCSRB = (UCSRB & 0xFE) | ((data & (1<<8))>>8);
	}
	
	UDR = (uint8) data;
	
}

uint16 MCAL_USART_Receive (void)
{
	uint16 Recived_Data = 0;
	
	if(GET_BIT(UCSRA,RXC) != 0);
	
	if(GET_BIT(UCSRA,FE) | GET_BIT(UCSRA,DOR) | GET_BIT(UCSRA,PE))
	{
		if(GET_BIT(UCSRA,FE))
		{
			USART.Error_Type = USART_FrameError;
		}
		else if (GET_BIT(UCSRA,DOR))
		{
			USART.Error_Type = USART_DataOverRunError;
		}
		else if (GET_BIT(UCSRA,PE))
		{
			USART.Error_Type = USART_ParityError;
		}
	}
	
	if(USART.Character_Size == Size_9bit)
	{
		/* read the 9bit from the bit 1 in the UCSRB then shift it to left by 7 to hold in 9bit */
		Recived_Data = UCSRB & (1 << RXB8) >> 7;
	}
	
	Recived_Data = UDR;
	
	return Recived_Data;
}
