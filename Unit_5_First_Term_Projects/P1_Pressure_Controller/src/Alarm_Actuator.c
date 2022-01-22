/*
 * Alarm_Actuator.c
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */

#include "Alarm_Actuator.h"

// Define Status
enum {
	ALARM_ACT_INIT,
	ALARM_ACT_WAITING,
	ALARM_ACT_ON,
	ALARM_ACT_OFF,
}ALARM_ACT_Status;

STATE_DEFINE(ALARM_ACT_INIT)
{
	// Initialize the alarm actuator
	// Call the alarm actuator driver functions
	// State Action
	ALARM_ACT_Status = ALARM_ACT_INIT;

	// Check event and update state
	ALARM_ACT_state = STATE(ALARM_ACT_WAITING);
}

STATE_DEFINE(ALARM_ACT_WAITING)
{
	// State Action
	ALARM_ACT_Status = ALARM_ACT_WAITING;
}

STATE_DEFINE(ALARM_ACT_ON)
{
	// State Action
	ALARM_ACT_Status = ALARM_ACT_ON;

	// Start Alarm Actuator
	GPIO_set_alarm_actuator(TRUE);

	// Check event and update state
	ALARM_ACT_state = STATE(ALARM_ACT_WAITING);
}

STATE_DEFINE(ALARM_ACT_OFF)
{
	// State Action
	ALARM_ACT_Status = ALARM_ACT_OFF;

	// Start Alarm Actuator
	GPIO_set_alarm_actuator(FALSE);

	// Check event and update state
	ALARM_ACT_state = STATE(ALARM_ACT_WAITING);
}

void ALARM_ACT_start_alarm(void)
{
	// Update State
	ALARM_ACT_state = STATE(ALARM_ACT_ON);
}

void ALARM_ACT_stop_alarm(void)
{
	// Update State
	ALARM_ACT_state = STATE(ALARM_ACT_OFF);
}
