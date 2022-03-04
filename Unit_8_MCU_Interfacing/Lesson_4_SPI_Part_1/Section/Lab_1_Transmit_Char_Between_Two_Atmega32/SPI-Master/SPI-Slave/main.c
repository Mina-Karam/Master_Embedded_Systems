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
#define MISO 6
#define SCK 7

void SPI_SlaveInit(void)
{
	/* Set MISO output */
	DDRB |= (1<<MISO);
	
	/* Set MOSI, SCK and SS input */
	DDRB &= ~(1<<MOSI) & ~(1<<SCK) & ~(1<<SS);

	/* Enable SPI, Slave */
	SPCR |= (1<<SPE);
}

uint8_t SPI_SlaveRecieve(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));
	
	/* Return Data Register */
	return SPDR;
}

int main(void)
{
	DDRA = 0xFF;
	
	SPI_SlaveInit();
	while (1)
	{
		PORTA = SPI_SlaveRecieve();
	}
	
}
