/*
 * DC_motor.c
 *
 * Created on : Jan 16, 2022
 *     Author : Mina Karam     
 */

#include "state.h"
#include "DC_motor.h"

// Global Variable
static int DC_speed = 0;

// STATE Pointer to function
void (*DC_state)();

void DC_init()
{
	//init PWM driver
	Dprintf("DC_init\n");
}

void DC_Set_speed(int speed)
{
	DC_speed = speed;
	DC_state = ST_STATE(DC_busy);
	Dprintf("CA --------- Speed = %d -------> DC \n", DC_speed);
}

// STATE Functions
ST_STATE_define(DC_idle)
{
	// State_Name
	DC_Status = DC_idle;

	// State_Action
	// Call PWM to set speed = DC_speed
	Dprintf("CA_idle State: speed = %d\n", DC_speed);

	// Event_Check

}

ST_STATE_define(DC_busy)
{
	// State_Name
	DC_Status = DC_busy;

	// State_Action
	// Call PWM to set speed = DC_speed
	Dprintf("DC_busy State: speed = %d\n", DC_speed);
	DC_state = ST_STATE(DC_idle);

	// Event_Check

}



