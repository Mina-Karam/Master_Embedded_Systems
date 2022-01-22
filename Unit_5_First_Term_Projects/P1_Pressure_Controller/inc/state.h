/*
 * state.h
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */

#ifndef STATE_H_
#define STATE_H_

#include "GPIO.h"

// State function declaration
#define STATE_DEFINE(_statFUN_) void ST_##_statFUN_()

// State function declaration
#define STATE(_statFUN_) ST_##_statFUN_

//States Connections
// Pressure Sensor =====> Main Program
uint32_t PS_get_pressure_value(void);

// Alarm Actuator =====> Alarm Monitor
void ALARM_ACT_start_alarm(void);

// Alarm Actuator =====> Alarm Monitor
void ALARM_ACT_stop_alarm(void);

// Main Program =====> Alarm Monitor
uint32_t MP_high_pressure_detected(void);

#endif /* STATE_H_ */
