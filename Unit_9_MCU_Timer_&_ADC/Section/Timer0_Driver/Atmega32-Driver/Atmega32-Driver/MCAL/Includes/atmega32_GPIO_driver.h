/*
 * atmega32_GPIO_driver.h
 *
 * Created: 3/2/2022 11:15:54 PM
 *  Author: Mina-Karam
 */ 


#ifndef ATMEGA32_GPIO_DRIVER_H_
#define ATMEGA32_GPIO_DRIVER_H_


/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "atmega32_device_header.h"

/* ================================================================ */
/* ========== User type definitions (structures) ================== */
/* ================================================================ */

typedef struct{

	uint8 GPIO_PinNumber;				//specifies the GPIO PIN to be configured
										//this parameter can be a value of @ref GPIO_PIN_NUMBERS

	uint8 GPIO_PinMode;					//specifies the Mode for selected pin.
										//this parameter can be a value of @ref GPIO_PIN_MODES
}GPIO_PinConfig_t;

/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

/*
 * @ref GPIO_PIN_NUMBERS
 */
#define GPIO_PIN_0					0
#define GPIO_PIN_1					1
#define GPIO_PIN_2					2
#define GPIO_PIN_3					3
#define GPIO_PIN_4					4
#define GPIO_PIN_5					5
#define GPIO_PIN_6					6
#define GPIO_PIN_7					7

#define GPIO_PORT					8

/*
 * @ref GPIO_PIN_MODES
 */
#define GPIO_MODE_INPUT_HiZ			0	//0: HI-Z input (reset state)
#define GPIO_MODE_INPUT_PU			1	//1: Input with pull-up
#define GPIO_MODE_OUTPUT_PP			2	//2: General purpose output push-pull


/*
 * @ref GPIO_PIN_STATE
 */
#define GPIO_PIN_HIGH					0b1
#define GPIO_PIN_LOW					0b0

#define GPIO_PIN_SET					1
#define GPIO_PIN_RESET					0

/* ================================================================ */
/* ============== APIs Supported by "MCAL GPIO DRIVER" ============ */
/* ================================================================ */

/*
 * Init and De-Init
 */
void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx,GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_Typedef_t *GPIOx);

/*
 * Data read and write
 */
uint8 MCAL_GPIO_ReadPin(GPIO_Typedef_t *GPIOx,uint8 PinNumber);
uint8 MCAL_GPIO_ReadPort(GPIO_Typedef_t *GPIOx);
void MCAL_GPIO_WritePin(GPIO_Typedef_t *GPIOx,uint8 PinNumber,uint8 Value);
void MCAL_GPIO_WritePort(GPIO_Typedef_t *GPIOx,uint8 Value);
void MCAL_GPIO_TogglePin(GPIO_Typedef_t *GPIOx,uint8 PinNumber);

#endif /* ATMEGA32_GPIO_DRIVER_H_ */