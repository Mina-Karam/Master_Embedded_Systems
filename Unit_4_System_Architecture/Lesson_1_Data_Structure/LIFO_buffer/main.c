/*
 * LIFO_test.c
 *
 * Created on : Jan 11, 2022
 *     Author : Mina Karam
 */

#include "lifo.h"
#include "stdio.h"

#define LIFO_buf_length 5

LIFO_Buf_st LIFO_uart;

uint32_t uart_buf[LIFO_buf_length];

int main(void)
{
	uint32_t i, temp;

	LIFO_init(&LIFO_uart, uart_buf, LIFO_buf_length);

	printf("=========== LIFO Writing ========\n");
	for (i = 1; i < LIFO_buf_length+2; i++)
	{
		if(LIFO_push(&LIFO_uart, i) == LIFO_NO_ERROR)
		{
			printf("Writing %d in LIFO_uart passed\n",i);
		}
		else
		{
			printf("Writing %d in LIFO_uart failed\n",i);
		}
	}


	printf("\n=========== LIFO Reading ========\n");
	for (i = 0; i < LIFO_buf_length; i++)
	{
		if(LIFO_pop(&LIFO_uart, &temp) == LIFO_NO_ERROR)
		{
			printf("Reading %d in LIFO_uart passed\n",temp);
		}
		else
		{
			printf("Reading %d in LIFO_uart failed\n",temp);
		}
	}

	return 0;
}
