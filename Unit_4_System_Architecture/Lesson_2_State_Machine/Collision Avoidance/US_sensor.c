/*
 * US_sensor.c
 *
 * Created on : Jan 16, 2022
 *     Author : Mina Karam     
 */

#include "US_sensor.h"

// Global Variable
static int US_distance = 0;

// STATE Pointer to function
void (*US_state)();

void US_init()
{
	//init Ultrasonic driver
	Dprintf("US_init\n");
}

// STATE Functions
ST_STATE_define(US_busy)
{
	// State_Name
		US_Status = US_busy;

		// State_Action
		US_distance = ultrasonic_get_distance_random(45, 55, 1);
		Dprintf("US_busy State: distance = %d \n", US_distance);

		US_Set_distance(US_distance);
		US_state = ST_STATE(US_busy);

		// Event_Check
		// Automatic because have function
		// Ultrasonic_Get_Distance(CA_distance)
}

int ultrasonic_get_distance_random(int min, int max, int count)
{
	// this will generate random number in range between start & end in number of counter
	int i;
	for (i = 0; i < count; i++)
	{
		int rand_num = (rand() % (max - min + 1)) + min;
		return rand_num;
	}
	return 0;
}



