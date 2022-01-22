/*
 * Pressure_Sensor.c
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */


#include "Pressure_Sensor.h"

// Define Status
enum {
	PS_INIT,
	PS_READING,
	PS_WAITIMG
}PS_Status;

static uint32_t PS_pressure_value ;

STATE_DEFINE(PS_INIT)
{
	// Initialize the pressure sensor
	// Call the pressure sensor driver functions
	// State Action
	PS_Status = PS_INIT;

	// Check event and update state
	PS_state = STATE(PS_READING);
}

STATE_DEFINE(PS_READING)
{
	// State Action
	PS_Status = PS_READING;

	// Read form pressure sensor
	PS_pressure_value = GPIO_get_pressure_value();

	// Check event and update state
	PS_state = STATE(PS_WAITIMG);
}

STATE_DEFINE(PS_WAITIMG)
{
	// State Action
	PS_Status = PS_WAITIMG;

	// Wait for data
	GPIO_delay(1000);

	// Check event and update state
	PS_state = STATE(PS_READING);
}

// Interface with main program
// (Set pressure in main program)
uint32_t PS_get_pressure_value(void)
{
	return PS_pressure_value;
}


