/*
 * atmega32_TIMER0_driver.c
 *
 * Created: 3/11/2022 8:28:05 AM
 *  Author: Mina-Karam
 */ 

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "atmega32_TIMER0_driver.h"

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

void (*GP_IRQ_CallBack)(void) = NULL;

TIMER0_Config_t G_TIMER0_Config;

/* ================================================================ */
/* ======================= Generic Macros ========================= */
/* ================================================================ */

/* ================================================================ */
/* ======================== Public APIs =========================== */
/* ================================================================ */

/* ================================================================
 * @Fn 				- MCAL_TIMER0_Init
 * @brief 			- Initializes TIMER0 according to the specified parameters in Timer_Cfg
 * @param [in] 		- TIMER0_Config : a pointer to TIMER_CONFIG_t structure that contains the configuration information for the specified TIMER Module
 * @retval 			- None
 * Note 			- Supported for TIMER0 ONLY
 *
 */
void MCAL_TIMER0_Init(TIMER0_Config_t *TIMER0_Config)
{
	
	G_TIMER0_Config = *TIMER0_Config;
	
	/* Select Timer Mode */
	TCCR0 |= TIMER0_Config->Timer_Mode;
	if(TIMER0_Config->Timer_Mode == TIMER0_MODE_FAST_PWM_INVERTING || TIMER0_Config->Timer_Mode == TIMER0_MODE_FAST_PWM_NONINVERTING)
	{
		/* Configure OC0 (PINB3) as Output */
		DDRB |= (1<<3);
	}
	
	/* Select Clock Source */
	TCCR0 |= TIMER0_Config->Clock_Source;
	if(TIMER0_Config->Clock_Source == TIMER0_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE || TIMER0_Config->Clock_Source == TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE)
	{
		/* Configure T0 (PINB0) as Input */
		DDRB &= ~(1<<0);
	}
	
	/* Enable Or Disable IRQ */
	TIMSK |= TIMER0_Config->IRQ_Enable;
	if(TIMER0_Config->IRQ_Enable != TIMER0_IRQ_ENABLE_NONE)
	{
		/* Enable Global Interrupt */
		Enable_G_Interrupt();
	}
	else
	{
		/* Disable Global Interrupt */
		Disable_G_Interrupt();
	}
	
	/* Call back function address */
	GP_IRQ_CallBack = TIMER0_Config->P_IRQ_CallBack;
}

/* ================================================================
 * @Fn 				- MCAL_TIMER0_DeInit
 * @brief 			- DeInitialze Timer0 Operation By Disable Timer Clock
 * @retval 			- None
 * Note 			- Supported for TIMER0 ONLY
 */
void MCAL_TIMER0_DeInit(void)
{
	TCCR0 &= ~((1<<0)|(1<<1)|(1<<2));
}

/* ================================================================
 * @Fn 				- MCAL_TIMER0_GetCompareValue
 * @brief 			- Set OCR Register compare Value in Compare Match Mode(CTC)
 * @param [in] 		- TicksNumber : Value to Set in OCR(compare value must not exceed 255)
 * @retval 			- None
 * Note 			- Supported for Compare Match Mode(CTC) only & compare value must not exceed 255
 */
void MCAL_TIMER0_SetCompareValue(uint8 TicksNumber)
{
	OCR0 = TicksNumber;
}

/* ================================================================
 * @Fn 				- MCAL_TIMER0_GetCompareValue
 * @brief 			- Get Timer counter value
 * @param [in] 		- TicksNumber : value of counter value from counter register (TCNT0)
 * @retval 			- None
 * Note 			- None
 *
 */
void MCAL_TIMER0_GetCompareValue(uint8* TicksNumber)
{
	*TicksNumber = TCNT0;
}

/* ================================================================
 * @Fn 				- MCAL_PWM_DutyCycle
 * @brief 			- Set PWM duty cycle in Fast PWM Mode
 * @param [in] 		- Duty_Cycle : Value of PWM duty cycle (from 0 to 255)
 * @retval 			- None
 * Note 			- Supported for Fast PWM Mode only & count value must not exceed 255
 */
void MCAL_PWM_DutyCycle(uint8 Duty_Cycle)
{
	if(G_TIMER0_Config.Timer_Mode == TIMER0_MODE_FAST_PWM_NONINVERTING)
	{
		OCR0 = Duty_Cycle;
	}
	else if(G_TIMER0_Config.Timer_Mode == TIMER0_MODE_FAST_PWM_INVERTING)
	{
		OCR0 = (uint8)(255 - Duty_Cycle);
	}
}

/* ================================================================ */
/* ================ ISR Functions Definations ===================== */
/* ================================================================ */

/* OVERFLOW ISR */
ISR(TIMER0_OVF_vect)
{
	GP_IRQ_CallBack();
}

/* COMPARE MATCH ISR */
ISR(TIMER0_COMP_vect)
{
	GP_IRQ_CallBack();
}
