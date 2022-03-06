/*
 * Keypad.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Mina Karam
 */

#include "keypad.h"

uint32_t keypad_R[] = {R0, R1, R2, R3}; // Rows of the keypad
uint32_t keypad_C[] = {C0, C1, C2, C3}; // Columns of the keypad

/* ========================================== */
/* ========== Functions Definitions ========= */
/* ========================================== */

void HAL_KEYPAD_INIT(void)
{
	// ALL ROWS and COLUMNS are OUTPUT

	GPIO_PinConfig_t PinConfig;

	PinConfig.GPIO_PinNumber = R0;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R1;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R2;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = R3;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C0;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C1;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C2;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = C3;
	PinConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);
}

// Function to get the key pressed on the Keypad
// And return it as char to send it to LCD
char HAL_KEYPAD_GET_KEY(void)
{
	int i, j; // Two counters for Two loops

	// First loop : It determines the current column
	for (i = 0; i < 4; i++)
	{
		/* === All Column PINS are SET to 1, Once a PIN is pressed it will RESET === */
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[3], GPIO_PIN_SET);

		// This line of code CHECKS for the PIN pressed
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[i], GPIO_PIN_RESET);

		// Second loop : It determines the current row
		// within the current column
		for (j = 0; j < 4; j++)
		{
			// Read PIN Pressed
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_R[j]) == 0)
			{
				while (MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_R[j]) == 0);// Wait for the key to be released (Single pressed)

				switch (i)
				{
				case 0:
					if (j == 0) return '7';
					else if(j == 1) return '4';
					else if(j == 2) return '1';
					else if(j == 3) return '?';
					break;

				case 1:
					if (j == 0) return '8';
					else if(j == 1) return '5';
					else if(j == 2) return '2';
					else if(j == 3) return '0';
					break;

				case 2:
					if (j == 0) return '9';
					else if(j == 1) return '6';
					else if(j == 2) return '3';
					else if(j == 3) return '=';
					break;

				case 3:
					if (j == 0) return '/';
					else if(j == 1) return '*';
					else if(j == 2) return '-';
					else if(j == 3) return '+';
					break;
				}
			}
		}
	}
	return 'A'; // Return 'A' if no key is pressed
}
