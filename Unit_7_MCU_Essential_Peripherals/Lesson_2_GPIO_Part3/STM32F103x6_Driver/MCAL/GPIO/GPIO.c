/*
 * GPIO.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Mina Karam
 */

#include "GPIO.h"

/**================================================================
* @Fn				- MCAL_GPIO_Init
* @brief			- Initializes the GPIOx PINy according to the specified parameters in PinConfig
* @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		- PinConfig pointer to a GPIO_PinConfig_t structure that contains
* 					  the configuration information for the specified GPIO PIN.
* @retval 			- None
* Note				- Stm32F103C6 MCU has GPIO A, B, C, D, E Modules
* 					  But LQFP48 Package jas only GPIO A, B, PART of C/D exported as external PINs from the Module
*/
void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{

}

/**================================================================
* @Fn				- MCAL_GPIO_DeInit
* @brief			- Reset all the GPIO Registers
* @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @retval 			- None
* Note				- None
*/
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{

}

/**================================================================
* @Fn				- MCAL_GPIO_ReadPin
* @brief			- Read Specific PIN
* @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		- PinNumber: Set Pin Number according to @ref GPIO_PINS_define
* @retval 			- The input pin value (two values based on @ref GPIO_PIN_state)
* Note				- None
*/
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{

}

/**================================================================
* @Fn				- MCAL_GPIO_ReadPort
* @brief			- Read Specific PORT
* @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @retval 			- The input port value
* Note				- None
*/
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{

}

/**================================================================
* @Fn				- MCAL_GPIO_WritePin
* @brief			- Write on Specific pin
* @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		- PinNumber: specific the port bit to read @ref GPIO_PINS_define
* @param [in] 		- Value: Pin value
* @retval 			- None
* Note				- None
*/
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value)
{

}

/**================================================================
* @Fn				- MCAL_GPIO_WritePort
* @brief			- Write on Specific PORT
* @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		- Value: Port value
* @retval 			- None
* Note				- None
*/
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value)
{

}

/**================================================================
* @Fn				- MCAL_GPIO_TogglePin
* @brief			- Toggle Specific pin
* @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		- PinNumber: specific the port bit to read @ref GPIO_PINS_define
* @retval 			- None
* Note				- None
*/
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{

}

/**================================================================
* @Fn				- MCAL_GPIO_LockPin
* @brief			- The locking mechanism allows the IO configuration to be frozen
* @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select GPIO peripheral
* @param [in] 		- PinNumber: specific the port bit to read @ref GPIO_RETURN_LOCK
* @retval 			- OK if pin configure is locked Or ERROR if pin is not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK)
* Note				- None
*/
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{

}

