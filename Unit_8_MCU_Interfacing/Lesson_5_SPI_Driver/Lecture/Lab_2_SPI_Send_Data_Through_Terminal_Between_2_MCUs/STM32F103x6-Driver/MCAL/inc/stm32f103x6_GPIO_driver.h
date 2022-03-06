/*
 * GPIO.h
 *
 *  Created on: Feb 9, 2022
 *      Author: Mina Karam
 */

#ifndef GPIO_STM32F103X6_GPIO_DRIVER_H_
#define GPIO_STM32F103X6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "STM32F103x6.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct
{
	uint16_t GPIO_PinNumber;	// Specifies the GPIO pins to be configured
								// This parameters must be a value of @ref GPIO_Pin_Define

	uint8_t	 GPIO_Mode;			// Specifies the operating mode for the selected pins.
								// This parameter must be set based on @ref GPIO_Mode_define

	uint8_t	 GPIO_Speed;	// Specifies the speed for the selected pins.
								// This parameter must be set based on @ref GPIO_SPEED_define
}GPIO_PinConfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINS_define
#define GPIO_PIN_0						((uint16_t)0x0001) /* Pin 0 selected */
#define GPIO_PIN_1						((uint16_t)0x0002) /* Pin 1 selected */
#define GPIO_PIN_2						((uint16_t)0x0004) /* Pin 2 selected */
#define GPIO_PIN_3						((uint16_t)0x0008) /* Pin 3 selected */
#define GPIO_PIN_4						((uint16_t)0x0010) /* Pin 4 selected */
#define GPIO_PIN_5						((uint16_t)0x0020) /* Pin 5 selected */
#define GPIO_PIN_6						((uint16_t)0x0040) /* Pin 6 selected */
#define GPIO_PIN_7						((uint16_t)0x0080) /* Pin 7 selected */
#define GPIO_PIN_8						((uint16_t)0x0100) /* Pin 8 selected */
#define GPIO_PIN_9						((uint16_t)0x0200) /* Pin 9 selected */
#define GPIO_PIN_10						((uint16_t)0x0400) /* Pin 10 selected */
#define GPIO_PIN_11						((uint16_t)0x0800) /* Pin 11 selected */
#define GPIO_PIN_12						((uint16_t)0x1000) /* Pin 12 selected */
#define GPIO_PIN_13						((uint16_t)0x2000) /* Pin 13 selected */
#define GPIO_PIN_14						((uint16_t)0x4000) /* Pin 14 selected */
#define GPIO_PIN_15						((uint16_t)0x8000) /* Pin 15 selected */
#define GPIO_PIN_16						((uint16_t)0xFFFF) /* All pins selected */

#define GPIO_PIN_MASK					0x0000FFFFu /* PIN mask for assert test */

//@ref GPIO_Mode_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input
#define GPIO_MODE_INPUT_ANALOG				0x00000000u /* Analog mode */
#define GPIO_MODE_INPUT_FLO				0x00000001u /* Floating input */
#define GPIO_MODE_INPUT_PU				0x00000002u /* Input with pull-up */
#define GPIO_MODE_INPUT_PD				0x00000003u /* Input with pull-down */
#define GPIO_MODE_OUTPUT_PP				0x00000004u /* General purpose output push-pull */
#define GPIO_MODE_OUTPUT_OD				0x00000005u /* General purpose output Open-drain */
#define GPIO_MODE_OUTPUT_AF_PP			0x00000006u /* Alternate function output Push-pull */
#define GPIO_MODE_OUTPUT_AF_OD			0x00000007u /* Alternate function output Open-drain */
#define GPIO_MODE_INPUT_AF				0x00000008u /* Alternate function input */

//@ref GPIO_SPEED_define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.
#define GPIO_SPEED_10M					0x00000001u /* Output mode, max speed 10 MHz. */
#define GPIO_SPEED_2M					0x00000002u /* Output mode, max speed 2 MHz. */
#define GPIO_SPEED_50M					0x00000003u /* Output mode, max speed 50 MHz. */

//@ref GPIO_PIN_state
#define GPIO_PIN_SET  					1
#define GPIO_PIN_RESET  				0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_Enabled 		1
#define GPIO_RETURN_LOCK_ERROR	 		0

/*
 * ===============================================
 * 	APIs Supported by "MCAL GPIO DRIVER"
 * ===============================================
 */

void MCAL_GPIO_Init (GPIO_Typedef_t *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_Typedef_t *GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_Typedef_t *GPIOx);

void MCAL_GPIO_WritePin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_Typedef_t *GPIOx, uint16_t Value);

void MCAL_GPIO_TogglePin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_Typedef_t *GPIOx, uint16_t PinNumber);

#endif /* GPIO_STM32F103X6_GPIO_DRIVER_H_ */
