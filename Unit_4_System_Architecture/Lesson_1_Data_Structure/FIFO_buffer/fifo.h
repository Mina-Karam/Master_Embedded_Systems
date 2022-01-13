/*
 * fifo.h
 *
 * Created on : Jan 13, 2022
 *     Author : Mina Karam     
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"
#include "fifo_cfg.h"

// Type Definition
typedef struct {
	element_type *base;
	element_type *head;
	element_type *tail;
	uint32_t length;
	uint32_t counter;
}FIFO_Buf_st;

typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}FIFO_Status_st;

// Initialize FIFO given an array buffer, item and a buffer length
FIFO_Status_st FIFO_init(FIFO_Buf_st *fifo_buf, element_type *item, uint32_t length);

// Enqueue item in the FIFO given a data item
FIFO_Status_st FIFO_enqueue(FIFO_Buf_st *fifo_buf, element_type item);

// Dequeue item from the FIFO given the address of the item holder
FIFO_Status_st FIFO_dequeue(FIFO_Buf_st *fifo_buf, element_type *item);

// Print the FIFO buffer content
FIFO_Status_st FIFO_print(FIFO_Buf_st *fifo_buf);

// Is the FIFO full ?!
FIFO_Status_st FIFO_is_full(FIFO_Buf_st *fifo_buf);

// Is the FIFO empty ?!
FIFO_Status_st FIFO_is_empty(FIFO_Buf_st *fifo_buf);

// Erase all data items inside the FIFO (Reset a FIFO buffer)
FIFO_Status_st FIFO_make_empty(FIFO_Buf_st *fifo_buf);

#endif /* FIFO_H_ */
