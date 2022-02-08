/*
 * lcd.c
 *
 * Created: 2/8/2022 7:53:45 PM
 *  Author: Mina Karam
 */ 

#include "lcd.h"

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
		LCD_WRITE_COMMAND(0x02); // As datasheet
		LCD_WRITE_COMMAND(LCD_CMD_FUNCTION_4BIT_2LINES);
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
		LCD_ISBUSY();
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
		LCD_CTRL &= ~ ((1<<RW_PIN)|(1<<RS_PIN));
		LCD_KICK();
		LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
		LCD_CTRL &= ~ ((1<<RW_PIN)|(1<<RS_PIN));
		LCD_KICK();
	#endif
}

void LCD_WRITE_CHAR(unsigned char character)
{
	#ifdef EIGHT_BIT_MODE
		LCD_ISBUSY();
		LCD_CTRL |= (1<<RS_PIN); // Turn RS ON for data mode
		LCD_PORT = (((character) << DATA_SHIFT));
		LCD_CTRL |= (1<<RS_PIN); // Turn RS ON for data mode
		LCD_CTRL &= ~(1<<RW_PIN); // Turn RW OFF for write mode
		LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
		LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
		LCD_CTRL |= (1<<RS_PIN); // Turn RS ON for data mode
		LCD_CTRL &= ~(1<<RW_PIN); // Turn RW OFF for write mode
		LCD_KICK();
		LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
		LCD_CTRL |= (1<<RS_PIN); // Turn RS ON for data mode
		LCD_CTRL &= ~(1<<RW_PIN); // Turn RW OFF for write mode
		LCD_KICK();
	#endif
}

void LCD_WRITE_STRING(char* string)
{
	int count = 0; // To count how much char on the line (it should be 16 char only)
	
	while (*string > 0)
	{
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) // Go to the second line
		{
			LCD_GOTOXY(1,0); // Line 1 position 0
		}
		else if (count == 32 || count == 33) // Clear screen and show again
		{
			LCD_CLEAR_SCREEN();
			LCD_GOTOXY(0,0); // Line 0 Position 0
			count = 0;
		}
	}
}

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

void LCD_GOTOXY(unsigned char line, unsigned char position)
{
	if (line == 0)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	else if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}
