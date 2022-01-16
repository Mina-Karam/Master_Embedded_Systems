/*
 * Collision_Avoidanc.c
 *
 * Created on : Jan 16, 2022
 *     Author : Mina Karam     
 */

#include "Collision_Avoidanc.h"

// Global Variable
static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;

// STATE Pointer to function
void (*CA_state)();

void US_Set_distance(int distance)
{
	CA_distance = distance;
	(CA_distance <= CA_threshold) ? (CA_state = ST_STATE(CA_waiting)) : (CA_state = ST_STATE(CA_driving));
	Dprintf("US --------- distance = %d -------> CA \n", CA_distance);

}

// STATE Functions
ST_STATE_define(CA_waiting)
{
	// State_Name
	CA_Status = CA_waiting;
	Dprintf("CA_	wating State: distance = %d, speed = %d\n", CA_distance, CA_speed);

	// State_Action
	CA_speed = 0;
	DC_Set_speed(CA_speed);

	// Event_Check
	// Automatic because have function
	// Ultrasonic_Get_Distance(CA_distance)
}

ST_STATE_define(CA_driving)
{
	// State_Name
	CA_Status = CA_driving;
	Dprintf("CA_driving State: distance = %d, speed = %d\n", CA_distance, CA_speed);

	// State_Action
	CA_speed = 30;
	DC_Set_speed(CA_speed);

	// Event_Check
	// Automatic because have function
	// Ultrasonic_Get_Distance(CA_distance)
}
