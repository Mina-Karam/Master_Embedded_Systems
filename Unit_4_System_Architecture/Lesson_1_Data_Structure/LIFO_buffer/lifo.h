/*
 * lifo.h
 *
 * Created on : Jan 11, 2022
 *     Author : Mina Karam
 *      
 * Description:
 */

#ifndef LIFO_H_
#define LIFO_H_

//Data type of buffer
typedef unsigned char uint8_t ;
typedef unsigned int  uint32_t ;

//Type Definition
typedef struct {
	uint32_t  length ;
	uint32_t  count ;
	uint32_t* base ;
	uint32_t* head ;
}LIFO_Buf_st;

typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL
}LIFO_Status_st;

//APIs

//Initialize LIFO Given an array buffer and a buffer length
LIFO_Status_st LIFO_init(LIFO_Buf_st *lifo_buf, uint32_t *item_buf, uint32_t buf_len);

//Push item in the LIFO given a data item
LIFO_Status_st LIFO_push(LIFO_Buf_st *lifo_buf, uint32_t item);

//Pop item from the LIFO given the address of the item holder
LIFO_Status_st LIFO_pop(LIFO_Buf_st *lifo_buf, uint32_t *item);

//Return the top of the LIFO without erasing it given item holder
LIFO_Status_st LIFO_top(LIFO_Buf_st *lifo_buf, uint32_t *item);

//Print the LIFO buffer content
LIFO_Status_st LIFO_print(LIFO_Buf_st *lifo_buf);

//IS the LIFO full ?
LIFO_Status_st LIFO_is_full(LIFO_Buf_st *lifo_buf);

//IS the LIFO empty ?
LIFO_Status_st LIFO_is_empty(LIFO_Buf_st *lifo_buf);

//Erase all data items inside the LIFO (Reset a LIFO buffer)
LIFO_Status_st LIFO_make_empty(LIFO_Buf_st *lifo_buf);

#endif /* LIFO_H_ */
