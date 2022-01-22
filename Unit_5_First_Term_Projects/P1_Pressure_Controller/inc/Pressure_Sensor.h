/*
 * Pressure_Sensor.h
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

// Declare State Functions of Pressure Sensor
STATE_DEFINE(PS_INIT);
STATE_DEFINE(PS_READING);
STATE_DEFINE(PS_WAITIMG);

// State Pointer to function
extern void (*PS_state)();

#endif /* PRESSURE_SENSOR_H_ */
