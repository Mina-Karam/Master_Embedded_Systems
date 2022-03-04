/*
 * SPI-Master.c
 *
 * Created: 3/4/2022 7:33:50 PM
 * Author : Mina-Karam
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include "util/delay.h"

#define SS 4
#define MOSI 5
#define SCK 7

void SPI_MasterInit(void)
{
	/* Set MOSI, SCK and SS output, all others input */
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(uint8_t cmd, uint8_t data)
{
	/* Select Slave */
	PORTB &= ~(1 << SS);
	
	/* Start transmission, Write data to SPI data register */
	SPDR = cmd;
	
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	
	/* Start transmission, Write data to SPI data register */
	SPDR = data;
		
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	
	/* De-Select Slave */
	PORTB |= (1 << SS);	
}

int main(void)
{
	uint8_t counter = 0;
	uint8_t i = 0;
	
	SPI_MasterInit();
	
	/* Decode all Display 11111111 */
	SPI_MasterTransmit(0x09, 0xFF); 

	/* Set scan limit (digit 0 to digit 7) */
	SPI_MasterTransmit(0x0A, 0xFF);

	/* Max internsity */
	SPI_MasterTransmit(0x0B, 0xF7);
	
	/* Turn on Display */
	SPI_MasterTransmit(0x0C, 0x01);

	while (1)
	{
		/* Show Numbers (0,1,2,3,4,5,6,7,8,9,-,E,H,L,P)*/
		for (i = 1; i < 9; i++)
		{
			SPI_MasterTransmit(i,counter++);
			_delay_ms(300);
		}
		/* Show Number (0) (clear xD)*/
		for (i = 1; i < 9; i++)
		{
			SPI_MasterTransmit(i,0);
		}
	}	
}

