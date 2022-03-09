/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Mar 9, 2022
 *      Author: Mina-Karam
 */

#ifndef EEPROM_I2C_SLAVE_EEPROM_H_
#define EEPROM_I2C_SLAVE_EEPROM_H_

#include "stm32f103x6_I2C_driver.h"

/*
 * EEPROM is an I2C Slave
 *
 * Idle Mode ================> The device is in high-Impedane state and waits for data.
 * Master Transmitter Mode ==> The device transmits data to a slave receiver.
 * Master Receiver Mode =====> The device receives data form a slave transmitter.
 */

#define EEPROM_Slave_Address 		0x2A

/* ============ APIs ============ */

void HAL_EEPROM_Init(void);

uint8_t HAL_EEPROM_Write_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length);
uint8_t HAL_EEPROM_Read_NBytes(uint32_t Memory_Address, uint8_t *Byte, uint32_t Data_Length);

#endif /* EEPROM_I2C_SLAVE_EEPROM_H_ */
