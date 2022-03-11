/*
 * PWM.c
 *
 * Created: 3/11/2022 10:45:19 PM
 *  Author: Mina-Karam
 */ 

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */

#define F_CPU	8000000UL

#include "atmega32_GPIO_driver.h"
#include "atmega32_TIMER0_driver.h"

#include "PWM.h"

/* =========== Main Program ========== */
void PWM_Test(void)
{
		/* Configure PIND0 as Output */
		SET_BIT(DDRB, 3);
		
		/* Set timer configuration */
		TIMER0_Config_t TIMER0_Config;
		
		TIMER0_Config.Timer_Mode = TIMER0_MODE_FAST_PWM_INVERTING;
		TIMER0_Config.Clock_Source = TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8;
		TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_NONE;
		TIMER0_Config.P_IRQ_CallBack = NULL;
		
		MCAL_TIMER0_Init(&TIMER0_Config);
		
		MCAL_PWM_DutyCycle(100);

		
		while (1)
		{
			
		}
}
