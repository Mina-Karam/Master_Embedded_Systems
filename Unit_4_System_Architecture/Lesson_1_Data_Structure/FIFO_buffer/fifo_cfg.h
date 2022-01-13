/*
 * fifo_cfg.h
 *
 * Created on : Jan 13, 2022
 *     Author : Mina Karam     
 */

#ifndef FIFO_CFG_H_
#define FIFO_CFG_H_

#include "stdio.h"
#include "stdint.h"

//User Configuration

//select the element type (uint8_t, uint16_t, uint32_t, uint64_t)
#define element_type uint8_t

//select the type of fifo (fifo_circular, fifo_no_circular)
#define fifo_circular

#endif /* FIFO_CFG_H_ */
