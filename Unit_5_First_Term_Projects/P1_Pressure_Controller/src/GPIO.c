/*
 * Driver.c
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */


#include "GPIO.h"

void GPIO_delay(uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}

uint32_t GPIO_get_pressure_value(void)
{
	return (GPIOA_IDR & 0xFF);
}

void GPIO_set_alarm_actuator(uint32_t i)
{
	if (i == 1)
	{
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0)
	{
		CLR_BIT(GPIOA_ODR,13);
	}
}

void GPIO_init (void)
{
	SET_BIT(APB2ENR, 2);

	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
