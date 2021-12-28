#include "Platform_Types.h"
#include "uart.h"

/* Registers Address */
/* Uart Registers */
#define UART0DR *((vuint32_t* const)((uint32_t*)0x101f1000)) // casting for warning

/* Function Definations */
void Uart_Send_String(uint8_t* P_TX_Sting)
{
	while(*P_TX_Sting != '\0') /* Loop untill end of string */
	{
		UART0DR = (uint32_t)(*P_TX_Sting); // casting char(8) to int(32) // Transmit char
		P_TX_Sting++; // for next character  
	}
}