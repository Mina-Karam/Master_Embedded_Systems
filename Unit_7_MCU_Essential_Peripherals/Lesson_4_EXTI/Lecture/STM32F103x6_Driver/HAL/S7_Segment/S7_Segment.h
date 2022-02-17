/*
 * S7_Segment.h
 *
 *  Created on: Feb 11, 2022
 *      Author: Mina Karam
 */

#ifndef S7_SEGMENT_S7_SEGMENT_H_
#define S7_SEGMENT_S7_SEGMENT_H_

#include <stm32f103x6_GPIO_driver.h>
#include "STM32F103x6.h"

/* ============= Global Variable ================= */
GPIO_PinConfig_t PinConfig;

/* ===== 7 Segments Macros Definitions ===== */
#define ZERO 	0x01
#define ONE 	0x79
#define TWO 	0x24
#define THREE 	0x30
#define FOUR 	0x4C
#define FIVE 	0x12
#define SIX 	0x02
#define SEVEN 	0x19
#define EIGHT 	0x00
#define NINE 	0x10

/* ============= Functions Prototypes ============ */
void HAL_7_segment_init(void);

#endif /* S7_SEGMENT_S7_SEGMENT_H_ */
