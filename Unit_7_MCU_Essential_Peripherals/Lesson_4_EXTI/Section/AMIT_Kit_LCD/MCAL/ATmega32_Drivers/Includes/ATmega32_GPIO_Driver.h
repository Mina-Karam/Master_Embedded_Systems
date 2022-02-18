/*
 * ATmega32_GPIO_Driver.h
 *
 * Created: 2/17/2022 3:41:51 AM
 *  Author: Mina Karam
 */ 


#ifndef ATMEGA32_GPIO_DRIVER_H_
#define ATMEGA32_GPIO_DRIVER_H_


/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */

#include "ATmega32_Device_Header.h"

/* ================================================================ */
/* =============== User type definitions (structures) ============= */
/* ================================================================ */

typedef struct{
	uint8_t GPIO_PinNumber;             // Specifies The GPIO Pin To Be Configured
										// This Parameter Can Be a Value of @ref GPIO_PIN_define / GPIO_PORT_define

	uint8_t GPIO_PinMode;               // Specifies The Mode For Selected Pin
										// This Parameter Can Be a value of @ref GPIO_MODE_define
}GPIO_PinConfig_t;


/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

#define GPIO_PIN_0		0
#define GPIO_PIN_1		1
#define GPIO_PIN_2		2
#define GPIO_PIN_3		3
#define GPIO_PIN_4		4
#define GPIO_PIN_5		5
#define GPIO_PIN_6		6
#define GPIO_PIN_7		7

#define GPIO_PORT		8

/*
 *@ref GPIO_MODE_define
 */
#define GPIO_MODE_INPUT_Hiz			0	//0: HI-Z input (reset state)
#define GPIO_MODE_INPUT_PU			1	//1: Input with pull-up
#define GPIO_MODE_OUTPUT_PP			2	//2: General purpose output push-pull

/*
 *@ref GPIO_PIN_STATE_define
 */
#define GPIO_HIGH					1
#define GPIO_LOW					0


/* ================================================================ */
/* ============== APIs Supported by "MCAL GPIO DRIVER" ============ */
/* ================================================================ */

/* =======================================================================
 *@Fn:                  - MCAL_GPIO_Init
 *@param[in]            - GPIO_Typedef_t * GPIOx, GPIO_PinConfig_t * cfg
 *@retval               - None
 *@Brief                - This Function Initializes the GPIO For a Specific Port and Configure its Pins 
 */
void MCAL_GPIO_Init (GPIO_Typedef_t * GPIOx, GPIO_PinConfig_t * cfg);

/* =======================================================================
 *@Fn:                  - MCAL_GPIO_DeInit
 *@param[in]            - GPIO_Typedef_t * GPIOx, GPIO_PinConfig_t * cfg
 *@retval               - None
 *@Brief                - This Function DeInitializes the GPIO For a Specific Port and Reset its Pins 
 */
void MCAL_GPIO_DeInit (GPIO_Typedef_t * GPIOx);

/* =======================================================================
 *@Fn:                  - MCAL_GPIO_ReadPin
 *@param[in]            - GPIO_Typedef_t * GPIOx, uint8_t PinNumber
 *@retval               - uint8_t
 *@Brief                - This Function Reads the value of a pin and returns it 
 */
 uint8_t MCAL_GPIO_ReadPin (GPIO_Typedef_t * GPIOx, uint8_t PinNumber);

 /* =======================================================================
 *@Fn:                  - MCAL_GPIO_ReadPort
 *@param[in]            - GPIO_Typedef_t * GPIOx
 *@retval               - uint8_t
 *@Brief                - This Function reads the value of a port and returns it 
 */
uint8_t MCAL_GPIO_ReadPort (GPIO_Typedef_t * GPIOx);

/* =======================================================================
 *@Fn:                  - MCAL_GPIO_WritePin
 *@param[in]            - GPIO_Typedef_t * GPIOx, uint8_t PinNumber, uint8_t data
 *@retval               - None
 *@Brief                - This Function writes a value to a pin
 */
void MCAL_GPIO_WritePin (GPIO_Typedef_t * GPIOx, uint8_t PinNumber, uint8_t data);

/* =======================================================================
 *@Fn:                  - MCAL_GPIO_WritePort
 *@param[in]            - GPIO_Typedef_t * GPIOx, uint8_t data
 *@retval               - None
 *@Brief                - This Function writes a value to a port 
 */
void MCAL_GPIO_WritePort (GPIO_Typedef_t * GPIOx, uint8_t data);

/* =======================================================================
 *@Fn:                  - MCAL_GPIO_TogglePin
 *@param[in]            - GPIO_Typedef_t * GPIOx, uint8_t PinNumber
 *@retval               - None
 *@Brief                - This Function toggles a pin 
 */
void MCAL_GPIO_TogglePin (GPIO_Typedef_t * GPIOx, uint8_t PinNumber);


#endif /* ATMEGA32_GPIO_DRIVER_H_ */