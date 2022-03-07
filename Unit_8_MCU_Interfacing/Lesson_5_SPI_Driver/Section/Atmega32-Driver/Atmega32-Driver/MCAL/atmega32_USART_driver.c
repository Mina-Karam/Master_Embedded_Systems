/*
 * atmega32_USART_driver.c
 *
 * Created: 3/3/2022 1:40:24 AM
 *  Author: Mina-Karam
 */ 

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "atmega32_USART_driver.h"
#include "avr/interrupt.h"
/* ================================================================ */
/* ========================== Public APIs ========================= */
/* ================================================================ */

void (*GP_IRQ_CallBack)(void);

/* ================================================================
 * @Fn			-MCAL_USART_Init.
 * @brief	    -initialize the USART according to config instance PinConfig.
 * @param [in] 	-PinConfig: pointer to USART_config that contains USART configuration.
 * @retval 		-none
 * Note			-none
 */
void MCAL_USART_Init(USART_Config_t * PinConfig)
{
	/* 1. Set Boudrate */
	USART->UBRRL_ = PinConfig->USART_Baudrate;
	
	/* 2. Set Asynchronous Normal mode (U2X = 0)*/
	USART->UCSRA_.bits.U2X_ = GPIO_PIN_LOW;

	/* 3. Set data bits mode */
	switch(PinConfig->USART_Databits)
	{
		/* UCSZ2 UCSZ1 UCSZ0 Character Size
		 *   0     0     0     5-bit
		 *   0     0     1     6-bit
		 *   0     1     0     7-bit
		 *   0     1     1     8-bit
		 *   1     0     0    Reserved
		 *   1     0     1    Reserved
		 *   1     1     0    Reserved
		 *   1     1     1     9-bit
		 */
		case USART_5_DATA_BITS:
		{
			UCSRC |= (1<<URSEL);	/* The URSEL must be one when writing the UCSRC */
			UCSRC &= ~(1<<UCSZ0);	
			UCSRC &= ~(1<<UCSZ1);
			USART->UCSRB_.bits.UCSZ2_ = GPIO_PIN_LOW;
			break;
		}
		case USART_6_DATA_BITS:
		{
			UCSRC |= (1<<URSEL);	/* The URSEL must be one when writing the UCSRC */
			UCSRC |= (1<<UCSZ0);
			UCSRC &= ~(1<<UCSZ1);
			USART->UCSRB_.bits.UCSZ2_ = GPIO_PIN_LOW;
			break;
		}
		case USART_7_DATA_BITS:
		{
			UCSRC |= (1<<URSEL);	/* The URSEL must be one when writing the UCSRC */
			UCSRC &= ~(1<<UCSZ0);
			UCSRC |= (1<<UCSZ1);
			USART->UCSRB_.bits.UCSZ2_ = GPIO_PIN_LOW;
			break;
		}
		case USART_8_DATA_BITS:
		{
			UCSRC |= (1<<URSEL);	/* The URSEL must be one when writing the UCSRC */
			UCSRC |= (1<<UCSZ0);
			UCSRC |= (1<<UCSZ1);
			USART->UCSRB_.bits.UCSZ2_ = GPIO_PIN_LOW;
			break;
		}
		case USART_9_DATA_BITS:
		{
			UCSRC |= (1<<URSEL);	/* The URSEL must be one when writing the UCSRC */
			UCSRC |= (1<<UCSZ0);
			UCSRC |= ((1<<UCSZ1));
			USART->UCSRB_.bits.UCSZ2_ = GPIO_PIN_HIGH;
			break;
		}
	}
	
	/* 4. Set Parity bit type */
	switch(PinConfig->USART_Paritybit)
	{
		/* UPM1 UPM0 ParityMode
		 *  0    0   Disabled
		 *  0    1   Reserved
		 *  1    0   Enabled, Even Parity
		 *  1    1   Enabled, Odd Parity
		 */
		case USART_NO_PARITY:
		{
			UCSRC |= (1<<URSEL);	/* The URSEL must be one when writing the UCSRC */
			UCSRC &= ~(1<<UPM0);
			UCSRC &= ~(1<<UPM1);
			break;
		}
		case USART_ODD_PARITY:
		{
			UCSRC |= (1<<URSEL);	/* The URSEL must be one when writing the UCSRC */
			UCSRC |= (1<<UPM0);
			UCSRC |= (1<<UPM1);
			break;
		}
		case USART_EVEN_PARITY:
		{
			UCSRC |= (1<<URSEL);	/* The URSEL must be one when writing the UCSRC */
			UCSRC &= ~(1<<UPM0);
			UCSRC |= (1<<UPM1);
			break;
		}
	}
	
	/* 5. Set Stop bit type */
	switch (PinConfig->USART_Stopbits)
	{
		/* USBS Stop Bit(s)
		 *  0      1-bit
		 *  1      2-bit
		 */
		case USART_1_STOP_BIT:
		{
			UCSRC |= (1<<URSEL);		/* The URSEL must be one when writing the UCSRC */
			UCSRC &= ~(1<<USBS);
		}
		case USART_2_STOP_BIT:
		{
			UCSRC |=(1<<URSEL);			/* The URSEL must be one when writing the UCSRC */
			UCSRC |=(1<<USBS);
		}	
	}
	
	/* 6. Set USART Mode */
	switch(PinConfig->USART_Mode)
	{
		/* UMSEL Bit Settings Mode
		 *     0    Asynchronous Operation
		 *     1    Synchronous Operation
		 */
		case USART_MODE_ASYNC:
		{
			UCSRC |= (1<<URSEL);		/* The URSEL must be one when writing the UCSRC */
			UCSRC &= ~(1<<UMSEL);
		}
		case USART_MODE_SYNC:
		{
			UCSRC |=(1<<URSEL);			/* The URSEL must be one when writing the UCSRC */
			UCSRC |=(1<<UMSEL);
		}
	}
	
	/* 7. Enable/Disable interrupt */
	switch(PinConfig->USART_IRQ_Enable)
	{
		case USART_IRQ_DISABLE:
		{
			USART->UCSRB_.bits.RXCIE_ = GPIO_PIN_LOW;
			USART->UCSRB_.bits.TXCIE_ = GPIO_PIN_LOW;
			GP_IRQ_CallBack = (void *)(0x0);
			Disable_G_Interrupt();
			break;
		}
		case USART_IRQ_TXCIE:
		{
			USART->UCSRB_.bits.RXCIE_ = GPIO_PIN_LOW;
			USART->UCSRB_.bits.TXCIE_ = GPIO_PIN_HIGH;
			GP_IRQ_CallBack = PinConfig->P_IRQ_CallBack;
			Enable_G_Interrupt();
			break;
		}
		case USART_IRQ_RXCIE:
		{
			USART->UCSRB_.bits.RXCIE_ = GPIO_PIN_HIGH;
			USART->UCSRB_.bits.TXCIE_ = GPIO_PIN_LOW;
			GP_IRQ_CallBack = PinConfig->P_IRQ_CallBack;
			Enable_G_Interrupt();
			break;
		}
		case USART_IRQ_TXCIE_RXCIE:
		{
			USART->UCSRB_.bits.RXCIE_ = GPIO_PIN_HIGH;
			USART->UCSRB_.bits.TXCIE_ = GPIO_PIN_HIGH;
			GP_IRQ_CallBack = PinConfig->P_IRQ_CallBack;
			Enable_G_Interrupt();
			break;
		}
	}

	/* 8. Enable Sending/Receiving */
	USART->UCSRB_.bits.RXEN_ = GPIO_PIN_HIGH;
	USART->UCSRB_.bits.TXEN_ = GPIO_PIN_HIGH;

}

/* ================================================================
 * @Fn			-MCAL_USART_DeInit.
 * @brief	    -deinitialize the USART.
 * @param [in] 	-none
 * @retval 		-none
 * Note			-none
 */
void MCAL_USART_DeInit(void)
{
	while(!(USART->UCSRA_.bits.UDRE_));
	
	USART->UBRRL_ = 0x00;
	USART->UCSRA_.bits.MPCM_ = 0b0;
	USART->UCSRA_.bits.U2X_	= 0b0;
	USART->UCSRA_.bits.TXC_	= 0b0;
	USART->UCSRB_.UCSRB_ &= ~(0x02);
	UCSRC = 0x86;
	USART->UBRRL_ = 0x00;
	UBRRH = 0x00;
}

/* ================================================================
 * @Fn			-MCAL_UART_SendData.
 * @brief	    -transmits the data through USART.
 * @param [in] 	-pTxBuffer: data to be transmitted.
 * @retval 		-none
 * Note			-none
 */
void MCAL_UART_SendData(uint16 TxBuffer, enum Polling_Mechanism PollingEn)
{
	if(PollingEn)
	{
		while(!(USART->UCSRA_.bits.UDRE_));
	}
	
	if(USART->UCSRB_.bits.UCSZ2_)
	{
		/* TXB8 is the ninth data bit of the received character */
		/* Must be read before reading the low bits from UDR. */
		USART->UCSRB_.bits.TXB8_ = ((TxBuffer & (1<<8))>>8);
		USART->UDR_	= ((uint8)TxBuffer);
	}
	else
	{
		USART->UDR_ = (uint8)TxBuffer;
	}
}

/* ================================================================
 * @Fn			-MCAL_UART_ReceiveData.
 * @brief	    -reads the data received by USART.
 * @param [in] 	-none
 * @retval 		-RxBuffer: data received by USART.
 * Note			-none
 */
uint16 MCAL_UART_ReceiveData(enum Polling_Mechanism PollingEn)
{
	uint16 RxBuffer = 0;
	
	if(PollingEn)
	{
		while(!(USART->UCSRA_.bits.RXC_));
	}
	
	if(USART->UCSRB_.bits.UCSZ2_)
	{
		/* RXB8 is the ninth data bit of the received character */
		/* Must be read before reading the low bits from UDR. */
		RxBuffer |= ((USART->UCSRB_.bits.RXB8_)<<8);
		RxBuffer |= USART->UDR_;
	}
	else
	{
		RxBuffer = USART->UDR_;
	}
	return RxBuffer;
}

/* ================================================================
 * @Fn			-MCAL_USART_SendString.
 * @brief	    -transmits a string through USART.
 * @param [in] 	-pTxBuffer: pointer to the string to be transmitted.
 * @retval 		-none
 * Note			-to work properly it is preferred to use 8bit data in frame
 */
void MCAL_USART_SendString(uint8 *pTxBuffer)
{
	while(*pTxBuffer !='\0')
	{
		while(!(USART->UCSRA_.bits.UDRE_));
		
		if(USART->UCSRB_.bits.UCSZ2_)
		{
			USART->UCSRB_.bits.TXB8_ = 0;
			USART->UDR_ = ((uint8)(*pTxBuffer));
		}
		else
		{
			USART->UDR_ = (*pTxBuffer);
			pTxBuffer++;
		}
	}
	
	while(!(USART->UCSRA_.bits.UDRE_));
	
	USART->UDR_ = '\0';
}

/* ================================================================
 * @Fn			-MCAL_USART_ReceiveString.
 * @brief	    -reads the received string by USART char by char.
 * @param [in] 	-pRxBuffer: pointer to array of char to store received string.
 * @retval 		-none
 * Note			-to work properly it is preferred to use 8bit data in frame
 */
void MCAL_USART_ReceiveString(uint8 *pRxBuffer)
{
	while(1)
	{
		while(!(USART->UCSRA_.bits.RXC_));
		
		*pRxBuffer = USART->UDR_;
		
		if(*pRxBuffer == '\0')
		{
			break;
		}
		else
		{
			pRxBuffer++;
		}
	}
}

ISR(USART_RXC_vect)
{
	GP_IRQ_CallBack();
}

ISR(USART_TXC_vect)
{
	GP_IRQ_CallBack();
}