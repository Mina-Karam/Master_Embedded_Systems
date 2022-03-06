/*
 * S7_Segment.c
 *
 *  Created on: Feb 11, 2022
 *      Author: Mina Karam
 */


#include "S7_segment.h"

/* ========================================== */
/* ========== Functions Definitions ========= */
/* ========================================== */

void HAL_7_segment_init(void)
{
	// We are connecting 7 segment to Port B from PB9 to PB15
	// We will Initialize the 7 PINS as Output

	// PB9 is Output push-pull : Speed 10 MHz
	PinConfig.GPIO_PinNumber = GPIO_PIN_9;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

	// PB10 is Output push-pull : Speed 10 MHz
	PinConfig.GPIO_PinNumber = GPIO_PIN_10;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

	// PB11 is Output push-pull : Speed 10 MHz
	PinConfig.GPIO_PinNumber = GPIO_PIN_11;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

	// PB12 is Output push-pull : Speed 10 MHz
	PinConfig.GPIO_PinNumber = GPIO_PIN_12;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

	// PB13 is Output push-pull : Speed 10 MHz
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

	// PB14 is Output push-pull : Speed 10 MHz
	PinConfig.GPIO_PinNumber = GPIO_PIN_14;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

	// PB15 is Output push-pull : Speed 10 MHz
	PinConfig.GPIO_PinNumber = GPIO_PIN_15;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);
}
