/*
 * atmega32_TIMER0_Test.c
 *
 * Created: 3/11/2022 9:47:14 PM
 *  Author: Mina-Karam
 */ 

/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */

#define F_CPU	8000000UL

#include "atmega32_GPIO_driver.h"
#include "atmega32_TIMER0_driver.h"

#include "atmega32_TIMER0_Test.h"

void Timer_OverFlow_Interrupt_Handler(void);
void Timer_CompareMatch_Interrupt_Handler(void);

/* ========= Global variables ========== */
uint32_t Timer_Counter = 0;

/* =========== Main Program ========== */
void atmega32_TIMER0_Test(void)
{
		/* Configure PIND0 as Output */
		SET_BIT(DDRB, 0);
		
		/* Set compare value */
		MCAL_TIMER0_SetCompareValue(100);
		
		/* Set timer configuration */
		TIMER0_Config_t TIMER0_Config;
		
		TIMER0_Config.Timer_Mode = TIMER0_MODE_CTC;
		TIMER0_Config.Clock_Source = TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8;
		TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_TOIE0;
		TIMER0_Config.P_IRQ_CallBack = Timer_OverFlow_Interrupt_Handler;
		
		MCAL_TIMER0_Init(&TIMER0_Config);
		
		while (1){}
}

void Timer_CompareMatch_Interrupt_Handler(void)
{

}

void Timer_OverFlow_Interrupt_Handler(void)
{
	Timer_Counter++;
	if(Timer_Counter == 3921) /* 3921 ---> 1 sec*/
	{
		/* Toggle Led every one second */
		TOGGLE_BIT(PORTB, 0);
		
		/* Clear Counter */
		Timer_Counter = 0;
	}
}