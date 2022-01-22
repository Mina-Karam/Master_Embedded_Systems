/*
 * Main_Program.h
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */

#ifndef MAIN_PROGRAM_H_
#define MAIN_PROGRAM_H_

#include "state.h"

// Declare State Functions of main program
STATE_DEFINE(MP_HIGH_PRESSURE);

// State Pointer to function
extern void (*MP_state)();

#endif /* MAIN_PROGRAM_H_ */
