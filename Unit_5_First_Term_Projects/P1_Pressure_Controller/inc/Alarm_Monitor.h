/*
 * Alarm_Monitor.h
 *
 * Created on : Jan 19, 2022
 *     Author : Mina Karam     
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

// Declare State Functions of Alarm Monitor
STATE_DEFINE(ALARM_MON_ALARM_OFF);
STATE_DEFINE(ALARM_MON_ALARM_ON);
STATE_DEFINE(ALARM_MON_WAITING);

// State Pointer to function
extern void (*ALARM_MON_state)();

#endif /* ALARM_MONITOR_H_ */
