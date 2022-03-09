/*
 * 09_I2C_EEPROM.c
 *
 *  Created on: Mar 9, 2022
 *      Author: Mina-Karam
 */



/* ======================================= */
/* ============= Includes ================ */
/* ======================================= */

#include "I2C_Slave_EEPROM.h"

/* ========== Prototypes ========= */
static void Clock_Init(void);

/* =========== Main Program ========== */
void I2C_EEPROM(void)
{
	/* Initialization of clock */
	Clock_Init();

	/* Initialization of EEPROM */
	HAL_EEPROM_Init();

	/* =============== Test Case 1 =============== */

	uint8_t CH1_To_Write[7] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07};
	uint8_t CH2_To_Read[7] = {0};

	HAL_EEPROM_Write_NBytes(0xAF, CH1_To_Write, 7);
	HAL_EEPROM_Read_NBytes(0xAF, CH2_To_Read, 7);

	/* =============== Test Case 2 =============== */

	CH1_To_Write[0] = 0xA;
	CH1_To_Write[1] = 0xB;
	CH1_To_Write[2] = 0xC;
	CH1_To_Write[3] = 0xD;

	HAL_EEPROM_Write_NBytes(0xFFF, CH1_To_Write, 4);
	HAL_EEPROM_Read_NBytes(0xFFF, CH2_To_Read, 4);

	/* Loop For Ever */
	while(1){}
}

/* ======== clock Initialize definition ======= */
static void Clock_Init(void)
{
	/* Enable clock GPIOB */
	RCC_GPIOB_CLK_EN();

	/* Enable Clock For AFIO */
	RCC_AFIO_CLK_EN();
}


