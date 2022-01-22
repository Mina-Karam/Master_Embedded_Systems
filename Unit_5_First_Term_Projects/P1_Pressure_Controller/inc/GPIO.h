/*
 * Driver.h
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "Platform_Types.h"
#include "utill.h"

#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(volatile uint32_t *)(BASE_RCC + 0x18)

#define GPIOA_CRL *(volatile uint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile uint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

void GPIO_init (void);
void GPIO_delay(uint32_t nCount);

uint32_t GPIO_get_pressure_value(void);
void GPIO_set_alarm_actuator(uint32_t i);

#endif /* GPIO_H_ */
