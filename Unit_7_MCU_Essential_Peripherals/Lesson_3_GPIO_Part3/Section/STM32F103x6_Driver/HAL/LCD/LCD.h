/*
 * LCD.h
 *
 *  Created on: Feb 10, 2022
 *      Author: Mina Karam
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#define F_CPU 1000000UL

/* ======= Includes ======= */
#include "stm32f103x6.h"
#include "GPIO.h"

/* ======= LCD Port Connections =========== */
#define LCD_CTRL GPIOA // LCD CTRL Ports connected to PORTA Pins

/* ======= LCD Control Pins ========== */
#define RS_SWITCH GPIO_PIN_8
#define RW_SWITCH GPIO_PIN_9
#define EN_SWITCH GPIO_PIN_10

/* ======= LCD MODE ========== */
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

#define DATA_shift 4 // 0:8 bit date mode | 4:4 bit data mode

/* ============= LCD Options ================== */
#define LCD_REGISTER_SELECT_PIN						(0)
#define LCD_READ_WRITE_PIN							(1)
#define LCD_ENABLE_PIN								(2)
#define LCD_REGISTER_SELECT_ENABLE					(1)
#define LCD_REGISTER_SELECT_DISABLE					(0)
#define READ_FROM_LCD								(1)
#define WRITE_TO_LCD								(0)
#define LCD_ENABLE									(1)
#define LCD_DISABLE									(0)
#define LCD_FIRST_LINE								(0)
#define LCD_SECOND_LINE								(1)

/* ============= LCD Commands ================== */
#define LCD_CMD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_CMD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_CMD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_CMD_MOVE_DISP_LEFT   						(0x18)
#define LCD_CMD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_CMD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_CMD_DISP_OFF   								(0x08)
#define LCD_CMD_DISP_ON_CURSOR   						(0x0E)
#define LCD_CMD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_CMD_DISP_ON_BLINK   						(0x0D)
#define LCD_CMD_DISP_ON   								(0x0C)
#define LCD_CMD_ENTRY_DEC   							(0x04)
#define LCD_CMD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_CMD_ENTRY_INC_   							(0x06)
#define LCD_CMD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_CMD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_CMD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CMD_CLEAR_SCREEN							(0x01)
#define LCD_CMD_ENTRY_MODE								(0x06)

/* ============= Functions Prototypes ============ */
void HAL_LCD_INIT(void);
void HAL_LCD_WRITE_COMMAND(uint8_t command);
void HAL_LCD_WRITE_CHAR(uint8_t character);
void HAL_LCD_WRITE_STRING(char* string);
void HAL_LCD_ISBUSY(void);
void HAL_LCD_KICK(void);
void HAL_LCD_CLEAR_SCREEN(void);
void HAL_LCD_GOTO_XY(uint8_t line, uint8_t position);
void HAL_LCD_KICK(void);
//void HAL_LCD_custom_characters(void);


/* ============= Global Variable ================= */
GPIO_PinConfig_t PinConfig ;

#endif /* LCD_LCD_H_ */
