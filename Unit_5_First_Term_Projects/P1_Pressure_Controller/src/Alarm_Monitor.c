/*
 * Alarm_Monitor.c
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */

#include "Alarm_Monitor.h"
enum {
    ALARM_MON_ALARM_OFF,
    ALARM_MON_ALARM_ON,
    ALARM_MON_WAITING
}ALARM_MON_Status;

STATE_DEFINE(ALARM_MON_ALARM_OFF)
{
	// State Action
	ALARM_MON_Status = ALARM_MON_ALARM_OFF;

	// Stop alarm actuator
	ALARM_ACT_stop_alarm();

	// Check event and update state
	if(MP_high_pressure_detected() == TRUE)
	{
		ALARM_MON_state = STATE(ALARM_MON_ALARM_ON);
	}
}

STATE_DEFINE(ALARM_MON_ALARM_ON)
{
	// State Action
	ALARM_MON_Status = ALARM_MON_ALARM_ON;

	// Start alarm Actuator
	ALARM_ACT_start_alarm();

	// Check event and update state
	ALARM_MON_state = STATE(ALARM_MON_WAITING);
}

STATE_DEFINE(ALARM_MON_WAITING)
{
	// State Action
	ALARM_MON_Status = ALARM_MON_WAITING;

	GPIO_delay(500);

	// Check event and update state
	ALARM_MON_state = STATE(ALARM_MON_ALARM_OFF);
}

