/*
 * atmega32_device_header.h
 *
 * Created: 2/17/2022 3:41:34 AM
 *  Author: Mina Karam
 */ 


#ifndef ATMEGA32_DEVICE_HEADER_H_
#define ATMEGA32_DEVICE_HEADER_H_

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "Platform_Types.h"
#include "Util.h"

/* ================================================================ */
/* ========== Base Addresses of FLASH and SRAM memories =========== */
/* ================================================================ */

#define FLASH_MEMORY		0x00
#define SRAM				0x60

/* ================================================================ */
/* ================ Bus Peripheral Base Addresses ================= */
/* ================================================================ */

/* The Constant Difference between Memory Mapped Register Address  and  IO Mapped Register Address */
#define IO_MAPPING_OFFSET	0x20

#define GPIOA_Base			0x19	/* GPIO Port A address */
#define GPIOB_Base			0x16	/* GPIO Port B address */
#define GPIOC_Base			0x13	/* GPIO Port C address */
#define GPIOD_Base			0x10	/* GPIO Port D address */

#define USART_Base			0x09	/* USART address */
	
#define UCSRC_Base			0x20	/* USART Control and Status Register C */
#define UBRRH_Base			0x20	/* USART Baud Rate Register High */

/* ================================================================ */
/* ================= Peripheral Registers GPIO ==================== */
/* ================================================================ */
typedef struct
{
	/* GPIO Input Pins Address */
	volatile union 
	{
		vuint8_t PIN;		
		struct
		{
			vuint8_t PIN0 :1;
			vuint8_t PIN1 :1;
			vuint8_t PIN2 :1;
			vuint8_t PIN3 :1;
			vuint8_t PIN4 :1;
			vuint8_t PIN5 :1;
			vuint8_t PIN6 :1;
			vuint8_t PIN7 :1;
		}bits;
	}PIN;
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/

	/* GPIO Data Direction Register */
	volatile union 
	{
		vuint8_t DDR;
		struct
		{
			vuint8_t DD0 :1;
			vuint8_t DD1 :1;
			vuint8_t DD2 :1;
			vuint8_t DD3 :1;
			vuint8_t DD4 :1;
			vuint8_t DD5 :1;
			vuint8_t DD6 :1;
			vuint8_t DD7 :1;
		}bits;
	}DDR;
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/

	/* GPIO Port Register */
	volatile union
	{
		vuint8_t PORT;
		struct
		{
			vuint8_t PORT0 :1;
			vuint8_t PORT1 :1;
			vuint8_t PORT2 :1;
			vuint8_t PORT3 :1;
			vuint8_t PORT4 :1;
			vuint8_t PORT5 :1;
			vuint8_t PORT6 :1;
			vuint8_t PORT7 :1;
		}bits;
	}PORT;
	
}GPIO_Typedef_t;

/* ================================================================ */
/* ================ Peripheral Registers USART ==================== */
/* ================================================================ */

typedef struct{
	
	volatile uint8 UBRRL_;		/* USART Baud Rate Register Low, Address Offset: 0x09 */
		
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	/* USART Control and Status Register B */
	volatile union {
		volatile uint8 UCSRB_;
		struct {
			volatile uint8 TXB8_	:1;		/* Transmit Data Bit 8 */
			volatile uint8 RXB8_ 	:1;		/* Receive Data Bit 8 */
			volatile uint8 UCSZ2_   :1;		/* Character Size */
			volatile uint8 TXEN_    :1;		/* Transmitter Enable */
			volatile uint8 RXEN_    :1;		/* Receiver Enable */
			volatile uint8 UDRIE_   :1;		/* USART Data Register Empty Interrupt Enable */
			volatile uint8 TXCIE_   :1;		/* TX Complete Interrupt Enable */
			volatile uint8 RXCIE_   :1;		/* RX Complete Interrupt Enable */
		}bits;
	}UCSRB_;
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	volatile union 
	{
		volatile uint8 UCSRA_;		/* USART Control and Status Register A, Address Offset: 0x0B  */
		struct 
		{
			volatile uint8 MPCM_	:1;		/* Multi-processor Communication Mode */
			volatile uint8 U2X_		:1;		/* Double the USART Transmission Speed */
			volatile uint8 PE_		:1;		/* Parity Error */
			volatile uint8 DOR_		:1;		/* Data OverRun */
			volatile uint8 FE_		:1;		/* Frame Error */
			volatile uint8 UDRE_	:1;		/* USART Data Register Empty */
			volatile uint8 TXC_		:1;		/* USART Transmit Complete */
			volatile uint8 RXC_		:1;		/* USART Receive Complete */
		}bits;
	}UCSRA_;	
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	volatile uint8 UDR_;			/* USART I/O Data Register, Address Offset: 0x0C  */
			

}USART_typedef_t;

/* ================================================================ */
/* =================== Peripheral Instants  ======================= */
/* ================================================================ */

/*-*-*-*-*-*-* GPIO_Instants *-*-*-*-*-*-*/

#define GPIOA			((GPIO_Typedef_t*) (GPIOA_Base + IO_MAPPING_OFFSET))
#define GPIOB			((GPIO_Typedef_t*) (GPIOB_Base + IO_MAPPING_OFFSET))
#define GPIOC			((GPIO_Typedef_t*) (GPIOC_Base + IO_MAPPING_OFFSET))
#define GPIOD			((GPIO_Typedef_t*) (GPIOD_Base + IO_MAPPING_OFFSET))

/*-*-*-*-*-*-* USART_Instants *-*-*-*-*-*-*/
#define USART			((USART_typedef_t*) (USART_Base + IO_MAPPING_OFFSET))



/*
 * USART Control and Control Register C , Address Offset: 0x20 
 */
#define UCSRC			(*(vuint8_t*)(UCSRC_Base + IO_MAPPING_OFFSET))

#define UCPOL			0	/* Clock Polarity */
#define UCSZ0			1	/* Character Size */
#define UCSZ1			2	/* Character Size */
#define USBS			3	/* Stop Bit Select */
#define UPM0			4	/* Parity Mode */
#define UPM1			5	/* Parity Mode */
#define UMSEL			6	/* Mode Select */
#define URSEL			7	/* Register Select */

/* 
 * USART Baud Rate Register High , Address Offset: 0x20 
 */
#define UBRRH			(*(vuint8_t*)(UBRRH_Base + IO_MAPPING_OFFSET))	

/* ================================================================ */
/* ====================== Generic Macros  ========================= */
/* ================================================================ */

/*
 * Interrupt Macros
 */
#define SREG_Base		0x3F
#define SREG			(*(vuint8_t*)(SREG_Base + IO_MAPPING_OFFSET))
#define I_Bit			7

#define Enable_G_Interrupt()	SREG |= (1 << I_Bit)
#define Disable_G_Interrupt()	SREG &= ~(1 << I_Bit)

#endif /* ATMEGA32_DEVICE_HEADER_H_ */