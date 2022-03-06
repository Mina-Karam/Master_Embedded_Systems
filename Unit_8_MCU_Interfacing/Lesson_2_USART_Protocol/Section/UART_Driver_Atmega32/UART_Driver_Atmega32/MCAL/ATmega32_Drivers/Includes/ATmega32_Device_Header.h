/*
 * ATmega32_Device_Header.h
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

#define SREG_Base			0x3F
#define SREG				(*(vuint8_t*)(SREG_Base + IO_MAPPING_OFFSET))
#define I_Bit				7
/* ================================================================ */
/* ================ Bus Peripheral Base Addresses ================= */
/* ================================================================ */

/* The Constant Difference between Memory Mapped Register Address  and  IO Mapped Register Address */
#define IO_MAPPING_OFFSET	0x20

#define GPIOA_Base			0x19	/* GPIO Port A address */
#define GPIOB_Base			0x16	/* GPIO Port B address */
#define GPIOC_Base			0x13	/* GPIO Port C address */
#define GPIOD_Base			0x10	/* GPIO Port D address */

#define UDR_Base			0x0C	/* USART I/O Data Register */
#define UCSRA_Base			0x0B	/* USART Control and Status Register A */
#define UCSRB_Base			0x0A	/* USART Control and Status Register B */
#define UCSRC_Base			0x20	/* USART Control and Status Register C */
#define UBRRL_Base			0x09	/* USART Baud Rate Register Low */
#define UBRRH_Base			0x20	/* USART Baud Rate Register High */

/* ================================================================ */
/* ================= Peripheral Registers GPIO ==================== */
/* ================================================================ */

// typedef struct
// {
// 	vuint8_t PIN;	/* GPIO Input Pins Address */
// 	vuint8_t DDR;	/* GPIO Data Direction Register */
// 	vuint8_t PORT;  /* GPIO Data Register */
// }GPIO_Typedef_t;

typedef struct{

	// PIN Register
	volatile union {
		vuint8_t PIN;
		struct{
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
	//####################################

	// DDR Register
	volatile union {
		vuint8_t DDR;
		struct{
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
	//###################################

	// PORT Register
	volatile union{
		vuint8_t PORT;
		struct{
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


/* ================================================================ */
/* =================== Peripheral Instants  ======================= */
/* ================================================================ */

/*-*-*-*-*-*-* GPIO_Instants *-*-*-*-*-*-*/
#define GPIOA			(((GPIO_Typedef_t*) (GPIOA_Base + IO_MAPPING_OFFSET)));
#define GPIOB			(((GPIO_Typedef_t*) (GPIOB_Base + IO_MAPPING_OFFSET)));
#define GPIOC			(((GPIO_Typedef_t*) (GPIOC_Base + IO_MAPPING_OFFSET)));
#define GPIOD			(((GPIO_Typedef_t*) (GPIOD_Base + IO_MAPPING_OFFSET)));


/*-*-*-*-*-*-* USART_Instants *-*-*-*-*-*-*/
#define UDR				(*(vuint8_t*)(UDR_Base + IO_MAPPING_OFFSET))	/* USART I/O Data Register */

/*
 * USART Control and Status Register A
 */
#define    MPCM         0	/* Multi-processor Communication Mode */
#define    U2X          1	/* Double the USART Transmission Speed */
#define    PE           2	/* Parity Error */
#define    DOR          3	/* Data OverRun */
#define    FE           4	/* Frame Error */
#define    UDRE         5	/* USART Data Register Empty */
#define    TXC          6	/* USART Transmit Complete */
#define    RXC          7	/* USART Receive Complete */

#define UCSRA			(*(vuint8_t*)(UCSRA_Base + IO_MAPPING_OFFSET))	/* USART Control and Status Register A */

/*
 * USART Control and Control Register B
 */
#define    TXB8         0	/* Transmit Data Bit 8 */
#define    RXB8         1	/* Receive Data Bit 8 */
#define    UCSZ2        2	/* Character Size */
#define    TXEN         3	/* Transmitter Enable */
#define    RXEN         4	/* Receiver Enable */
#define    UDRIE        5	/* USART Data Register Empty Interrupt Enable */
#define    TXCIE        6	/* TX Complete Interrupt Enable */
#define    RXCIE        7	/* RX Complete Interrupt Enable */

#define	UCSRB			(*(vuint8_t*)(UCSRB_Base + IO_MAPPING_OFFSET))	/* USART Control and Status Register B */

/*
 * USART Control and Control Register C
 */
#define    UCPOL        0	/* Clock Polarity */
#define    UCSZ0        1	/* Character Size */
#define    UCSZ1        2	/* Character Size */
#define    USBS         3	/* Stop Bit Select */
#define    UPM0         4	/* Parity Mode */
#define    UPM1         5	/* Parity Mode */
#define    UMSEL        6	/* Mode Select */
#define    URSEL        7	/* Register Select */

#define UCSRC			(*(vuint8_t*)(UCSRC_Base + IO_MAPPING_OFFSET))	/* USART Control and Status Register C */

#define UBRRL			(*(vuint8_t*)(UBRRL_Base + IO_MAPPING_OFFSET))	/* USART Baud Rate Register Low */
#define UBRRH			(*(vuint8_t*)(UBRRH_Base + IO_MAPPING_OFFSET))	/* USART Baud Rate Register High */

#endif /* ATMEGA32_DEVICE_HEADER_H_ */