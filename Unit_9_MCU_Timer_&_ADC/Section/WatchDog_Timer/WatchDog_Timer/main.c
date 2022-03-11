/*
 * WatchDog_Timer.c
 *
 * Created: 3/11/2022 5:51:50 AM
 * Author : Mina-Karam
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT, BIT)			PORT |= (1<< BIT)
#define RESET_BIT(PORT, BIT)		PORT &= ~(1<<BIT)
#define TOG_BIT(PORT, BIT)			PORT ^= (1<<BIT)
#define GET_BIT(PORT, BIT)			PORT & (1<<BIT)

#define LED_DDR		DDRD
#define LED_PORT	PORTD
#define LED_PIN		0


void WDT_OFF(void)
{
	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}

void WDT_ON(void)
{
	WDTCR = (1 << WDP1)|(1 << WDP1)|(1 << WDE);
	RESET_BIT(WDTCR, WDP0);
}

int main(void)
{
	SET_BIT(LED_DDR, LED_PIN);
	
	while (1)
	{
		WDT_ON();
		
		_delay_ms(1000);
		
		TOG_BIT(LED_PORT, LED_PIN);
		
		WDT_OFF();
	}
}

