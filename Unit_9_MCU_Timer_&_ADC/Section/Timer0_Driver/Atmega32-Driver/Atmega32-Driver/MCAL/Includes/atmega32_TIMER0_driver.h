/*
 * atmega32_TIMER0_driver.h
 *
 * Created: 3/11/2022 8:28:17 AM
 *  Author: Mina-Karam
 */ 


#ifndef ATMEGA32_TIMER0_DRIVER_H_
#define ATMEGA32_TIMER0_DRIVER_H_

/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "atmega32_device_header.h"
#include "avr/interrupt.h"

/* ================================================================ */
/* ============= User type definitions (structures) =============== */
/* ================================================================ */

typedef struct
{
	uint8		Timer_Mode;					// specifies Timer Mode (Normal mode or CTC)
											// This parameter must be set based on @ref TIMER0_MODE_DEFINE
	
	uint8		Clock_Source;				// specifies Timer Clock Source (External / Internal) and PreScaler with internal clock only
											// This parameter must be set based on @ref TIMER0_CLOCK_SOURCE_DEFINE
	
	uint8		IRQ_Enable;					// Enable or Disable IRQ
											// This parameter must be set based on @ref TIMER0_IRQ_ENABLE_DEFINE
	
	void (*P_IRQ_CallBack)(void);			//set the C Function which will be called once IRQ Happens
	
}TIMER0_Config_t;

/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

//@ref TIMER0_MODE_DEFINE
#define TIMER0_MODE_NORMAL									((uint8)(0))
#define TIMER0_MODE_CTC										((uint8)(1<<3))
#define TIMER0_MODE_FAST_PWM_INVERTING						((uint8)(0x78))
#define TIMER0_MODE_FAST_PWM_NONINVERTING					((uint8)(0x68))

//@ref TIMER0_CLOCK_SOURCE_DEFINE
#define TIMER0_CLOCK_SOURCE_INTERNAL_NO_PRESCALER			((uint8)(1<<0))
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8			((uint8)(1<<1))
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_64			((uint8)(0x03))
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_256			((uint8)(0x04))
#define TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_1024			((uint8)(0x05))
#define TIMER0_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE			((uint8)(0x06))
#define TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE			((uint8)(0x07))


//@ref TIMER0_IRQ_ENABLE_DEFINE
#define TIMER0_IRQ_ENABLE_NONE								((uint8)(0))
#define TIMER0_IRQ_ENABLE_TOIE0								((uint8)(1<<0))
#define TIMER0_IRQ_ENABLE_OCIE0								((uint8)(1<<1))

/* ================================================================ */
/* =========== APIs Supported by "MCAL TIMER0 DRIVER" ============= */
/* ================================================================ */

void MCAL_TIMER0_Init(TIMER0_Config_t *TIMER0_Config);
void MCAL_TIMER0_DeInit(void);

void MCAL_TIMER0_GetCompareValue(uint8* TicksNumber);
void MCAL_TIMER0_SetCompareValue(uint8 TicksNumber);

void MCAL_PWM_DutyCycle(uint8 Duty_Cycle);

#endif /* ATMEGA32_TIMER0_DRIVER_H_ */