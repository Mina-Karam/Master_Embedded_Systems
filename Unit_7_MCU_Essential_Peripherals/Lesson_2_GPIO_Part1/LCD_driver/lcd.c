/*
 * lcd.c
 *
 * Created: 2/8/2022 7:53:45 PM
 *  Author: Mina Karam
 */ 

#include "lcd.h"

void LCD_CLEAR_SCREEN(void)
{
	LCD_WRITE_COMMAND(LCD_CMD_CLEAR_SCREEN);
}

void LCD_KICK(void)
{
	LCD_CTRL &= ~(1<<E_PIN);
	_delay_ms(50);
	LCD_CTRL |=(1<<E_PIN);	
}

void LCD_ISBUSY(void)
{
	DataDir_LCD_PORT = 0x00; //	Input Mode
	LCD_CTRL |= (1<<RW_PIN); // Read mode // ON
	LCD_CTRL &= ~(1<<RS_PIN);// Read Mode // OFF
	LCD_KICK();
	DataDir_LCD_PORT = 0xFF;
	LCD_CTRL &= ~(1<<RW_PIN);
}

void LCD_INIT(void)
{
	_delay_ms(20);
	LCD_ISBUSY();
	DataDir_LCD_CTRL |= ((1<<E_PIN)|(1<<RW_PIN)|(1<<RS_PIN)); // Set as output
	LCD_CTRL &= ~((1<<E_PIN)|(1<<RW_PIN)|(1<<RS_PIN)); // Clear
	DataDir_LCD_PORT = 0xFF; // Set Port as Output
	_delay_ms(15);
	LCD_CLEAR_SCREEN();
	
	#ifdef EIGHT_BIT_MODE
		LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	
	#endif
	
	LCD_WRITE_COMMAND(LCD_CMD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_CMD_DISP_ON_CURSOR_BLINK);
	
}

void LCD_WRITE_COMMAND(unsigned char command)
{
	#ifdef EIGHT_BIT_MODE
		LCD_ISBUSY();
		LCD_PORT = command;
		LCD_CTRL &= ~(1<<RW_PIN)|(1<<RS_PIN); // Clear
		LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
	
	#endif
}

void LCD_WRITE_CHAR(unsigned char character)
{
	#ifdef EIGHT_BIT_MODE
		LCD_ISBUSY();
		LCD_CTRL |= (1<<RS_PIN); // Turn RS ON for data mode
		LCD_PORT = character;
		LCD_CTRL |= (1<<RS_PIN); // Turn RS ON for data mode
		LCD_CTRL &= ~(1<<RW_PIN); // Turn RW OFF for write mode
		LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
	
	#endif
	
}

void LCD_WRITE_STRING(char* string)
{
	
}
