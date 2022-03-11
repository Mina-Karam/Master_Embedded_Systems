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
	
#define UCSRC_Base			0x20	/* USART Control and Status Register C address */
#define UBRRH_Base			0x20	/* USART Baud Rate Register High address */

#define SPI_Base			0x0D	/* SPI address */

#define TIMER0_Base			0x23	/* TIMER0 address */

#define TIFR_Base			0x36	/* Timer/Counter Interrupt Flag Register address */
#define TIMSK_Base			0x37	/* Timer/Counter Interrupt Mask Register address */

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
	
	vuint8_t UBRRL_;		/* USART Baud Rate Register Low, Address Offset: 0x09 */
		
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	/* USART Control and Status Register B */
	volatile union {
		vuint8_t UCSRB_;
		struct {
			vuint8_t TXB8_	  :1;		/* Transmit Data Bit 8 */
			vuint8_t RXB8_ 	  :1;		/* Receive Data Bit 8 */
			vuint8_t UCSZ2_   :1;		/* Character Size */
			vuint8_t TXEN_    :1;		/* Transmitter Enable */
			vuint8_t RXEN_    :1;		/* Receiver Enable */
			vuint8_t UDRIE_   :1;		/* USART Data Register Empty Interrupt Enable */
			vuint8_t TXCIE_   :1;		/* TX Complete Interrupt Enable */
			vuint8_t RXCIE_   :1;		/* RX Complete Interrupt Enable */
		}bits;
	}UCSRB_;
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	volatile union 
	{
		vuint8_t UCSRA_;		/* USART Control and Status Register A, Address Offset: 0x0B  */
		struct 
		{
			vuint8_t MPCM_	    :1;		/* Multi-processor Communication Mode */
			vuint8_t U2X_		:1;		/* Double the USART Transmission Speed */
			vuint8_t PE_		:1;		/* Parity Error */
			vuint8_t DOR_		:1;		/* Data OverRun */
			vuint8_t FE_		:1;		/* Frame Error */
			vuint8_t UDRE_	    :1;		/* USART Data Register Empty */
			vuint8_t TXC_		:1;		/* USART Transmit Complete */
			vuint8_t RXC_		:1;		/* USART Receive Complete */
		}bits;
	}UCSRA_;	
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	vuint8_t UDR_;			/* USART I/O Data Register, Address Offset: 0x0C  */
			
}USART_Typedef_t;

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
/* ================ Peripheral Registers SPI ==================== */
/* ================================================================ */

typedef struct
{
	volatile union
	{
		vuint8_t SPCR_;		/* SPI Control Register, Address Offset: 0x0D  */
		struct
		{
			vuint8_t SPR0_	    :1;		/* SPI Clock Rate Select 0 */
			vuint8_t SPR1_		:1;		/* SPI Clock Rate Select 1 */
			vuint8_t CPHA_		:1;		/* Clock Phase */
			vuint8_t CPOL_		:1;		/* Clock Polarity */
			vuint8_t MSTR_		:1;		/* Master/Slave Select */
			vuint8_t DORD_	    :1;		/* Data Order */
			vuint8_t SPE_		:1;		/* SPI Enable */
			vuint8_t SPIE_		:1;		/* SPI Interrupt Enable */
		}bits;
	}SPCR_;
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	volatile union
	{
		vuint8_t SPSR_;		/* SPI Status Register, Address Offset: 0x0E  */
		struct
		{
			vuint8_t SPI2X_	    :1;		/* Double SPI Speed Bit */
			vuint8_t Reversed_	:5;		/* Reversed */
			vuint8_t WCOL_		:1;		/* Write Collision Flag */
			vuint8_t SPIF_		:1;		/* SPI Interrupt Flag */
		}bits;
	}SPSR_;
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	vuint8_t SPDR_;		/*  SPI Data Register is a read/write register, Address Offset: 0x0F  */
		
}SPI_Typedef_t;

/* ================================================================ */
/* ================ Peripheral Registers TIMER0 =================== */
/* ================================================================ */
typedef struct
{
	vuint8_t OCR0_;		/*  Output Compare Register, Address Offset: 0x23  */
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	vuint8_t TCNT0_;		/* Timer/Counter Register, Address Offset: 0x24  */
	
	/*--*--*--*--*--*--*--*--*--*--*--*--*--*/
	
	volatile union
	{
		vuint8_t TCCR0_;		/*  Timer/Counter Control Register, Address Offset: 0x25  */
		struct
		{
			vuint8_t CS0n_	    :3;		/* Clock Select [n = 2:0] */
			vuint8_t WGM01_		:1;		/* Waveform Generation Mode [n=0:1] */
			vuint8_t COM0n_		:2;		/* Compare Match Output Mode [n = 1:0] */
			vuint8_t WGM00_		:1;		/* Waveform Generation Mode */
			vuint8_t FOC0_		:1;		/* Force Output Compare */
		}bits;
	}TCCR0_;
	
}TIMER0_Typedef_t;

/*
 * Timer/Counter Interrupt Mask Register , Address Offset: 0x37
 */
#define TIMSK			(*(vuint8_t*)(TIMSK_Base + IO_MAPPING_OFFSET))

#define TOIE0			0	/* Timer/CounterTimer/Counter0 Overflow Interrupt Enable */
#define OCIE0			1	/* Timer/CounterTimer/Counter0 Output Compare Match Interrupt Enable */

/*
 * Timer/Counter Interrupt Flag Register , Address Offset: 0x36
 */
#define TIFR			(*(vuint8_t*)(TIFR_Base + IO_MAPPING_OFFSET))

#define TOV0			0	/* Timer/Counter0 Overflow Flag */
#define OCF0			1	/* Output Compare Flag 0 */

/* ================================================================ */
/* =================== Peripheral Instants  ======================= */
/* ================================================================ */

/*-*-*-*-*-*-* GPIO_Instants *-*-*-*-*-*-*/

#define GPIOA			((GPIO_Typedef_t*) (GPIOA_Base + IO_MAPPING_OFFSET))
#define GPIOB			((GPIO_Typedef_t*) (GPIOB_Base + IO_MAPPING_OFFSET))
#define GPIOC			((GPIO_Typedef_t*) (GPIOC_Base + IO_MAPPING_OFFSET))
#define GPIOD			((GPIO_Typedef_t*) (GPIOD_Base + IO_MAPPING_OFFSET))

/*-*-*-*-*-*-* USART_Instants *-*-*-*-*-*-*/
#define USART			((USART_Typedef_t*) (USART_Base + IO_MAPPING_OFFSET))

/*-*-*-*-*-*-* SPI_Instants *-*-*-*-*-*-*/
#define SPI				((SPI_Typedef_t*) (SPI_Base + IO_MAPPING_OFFSET))

/*-*-*-*-*-*-* TIMER0_Instants *-*-*-*-*-*-*/
#define TIMER0			((TIMER0_Typedef_t*) (TIMER0_Base + IO_MAPPING_OFFSET))


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