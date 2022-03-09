/*
 * I2C_Slave_EEPROM.c
 *
 *  Created on: Mar 9, 2022
 *      Author: Mina-Karam
 */

#include "I2C_Slave_EEPROM.h"

void HAL_EEPROM_Init(void)
{
	/* I2C Initialize */
	/*
	 *	PB6: I2C1_SCL
	 *	PB7: I2C1_SDA
	 */

	I2C_Config_t I2C_Config;

	/* I2C Controller as Master */
	I2C_Config.General_Call = I2C_GENERAL_CALL_ENABLE;
	I2C_Config.Mode = I2C_MODE_I2C_MODE;
	I2C_Config.Stretch_Mode = I2C_STRETCH_MODE_ENABLE;
	I2C_Config.Master_Mode = I2C_MASTER_MODE_SM;
	I2C_Config.Clock_Speed = I2C_CLOCK_SPEED_100KHZ;
	I2C_Config.ACK_Control = I2C_ACK_CONTROL_ENABLE;
	I2C_Config.P_Slave_CallBack = NULL;

	MCAL_I2C_Init(I2C1, &I2C_Config);
	MCAL_I2C_GPIO_Set_Pins(I2C1);

}

uint8_t HAL_EEPROM_Write_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length)
{
	int i = 0;

	uint8_t Buffer[256];

	Buffer[0] = (uint8_t)(Memory_Address >> 8);		/* High Address */
	Buffer[1] = (uint8_t)(Memory_Address);			/* Low Address  */

	for(i = 2; i < (Data_Length+2); i++)
	{
		Buffer[i]= Byte[i-2];
	}

	MCAL_I2C_MASTER_TX(I2C1, EEPROM_Slave_Address, Buffer, (Data_Length+2), With_STOP, START);

	return 0;
}

uint8_t HAL_EEPROM_Read_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length)
{
	uint8_t Buffer[2];

	Buffer[0] = (uint8_t)(Memory_Address >> 8);		/* High Address */
	Buffer[1] = (uint8_t)(Memory_Address);			/* Low Address  */

	MCAL_I2C_MASTER_TX(I2C1, EEPROM_Slave_Address, Buffer, 2, Without_STOP, START);
	MCAL_I2C_MASTER_RX(I2C1, EEPROM_Slave_Address, Byte, Data_Length, With_STOP, Repeated_START);
	return 0;
}
