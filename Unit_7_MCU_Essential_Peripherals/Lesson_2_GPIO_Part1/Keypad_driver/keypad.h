/*
 * keypad.h
 *
 * Created: 2/8/2022 9:58:47 PM
 *  Author: Mina Karam
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_

#define F_CPU 1000000UL

#include "avr/io.h"
#include "util/delay.h"

// Keypad Information
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT PORTD
#define KEYPAD_PIN PIND
#define KEYPAD_DataDir DDRD

// Keypad Functions and global variables

void KEYPAD_INIT(void);
char KEYPAD_GET_KEY(void);

#endif /* KEYBAD_H_ */