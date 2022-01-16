/*
 * US_sensor.h
 *
 * Created on : Jan 16, 2022
 *     Author : Mina Karam     
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "state.h"
#include "US_sensor.h"

// Define Status
enum {
	US_busy
}US_Status;

// Declare Status Functions US
ST_STATE_define(US_busy);

// STATE Pointer to Function
extern void (*US_state)();

void US_init();
int ultrasonic_get_distance_random(int start, int end, int count);


#endif /* US_SENSOR_H_ */
