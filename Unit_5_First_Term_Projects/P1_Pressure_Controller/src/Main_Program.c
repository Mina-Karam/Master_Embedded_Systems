/*
 * Main_Program.c
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */


#include "Main_Program.h"

// Define Status
enum {
	MP_HIGH_PRESSURE
}MP_Status;

static uint32_t MP_pressure_value;
static uint32_t MP_pressure_threshold = 20;

STATE_DEFINE(MP_HIGH_PRESSURE)
{
	// State Action
	MP_Status = MP_HIGH_PRESSURE;

	// Read pressure value from pressure sensor
	MP_pressure_value = PS_get_pressure_value();

	// Check event and update state
	MP_state = STATE(MP_HIGH_PRESSURE);
}

// Main Program =====> Alarm Monitor
uint32_t MP_high_pressure_detected(void)
{
	return (MP_pressure_value > MP_pressure_threshold);
}
