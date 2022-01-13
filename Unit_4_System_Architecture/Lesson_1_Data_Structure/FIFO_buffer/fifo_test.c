/*
 * fifo_test.c
 *
 * Created on : Jan 13, 2022
 *     Author : Mina Karam
 */

#include "stdio.h"
#include "stdint.h"
#include "fifo.h"

#define FIFO_BUF_LENGTH 5

#define FIFO_testing(FIFO_function, pass_condition, pass_count, fail_count)		\
		if((FIFO_function) == (pass_condition))									\
		{																		\
			(pass_count)++;														\
			printf("Test passed\n");											\
		}																		\
		else																	\
		{																		\
			(fail_count)++;														\
			printf("Test failed\n");											\
		}


int main(void)
{
	element_type test_buf[FIFO_BUF_LENGTH], temp;
	FIFO_Buf_st fifo_test;

	uint32_t i, passed = 0, failed = 0;

	// Initialization
	printf("Testing Initialization:\n");
	FIFO_testing(FIFO_init(&fifo_test, test_buf, FIFO_BUF_LENGTH), FIFO_NO_ERROR, passed, failed);

	// Enqueue
	printf("\nTesting Enqueue with 7 elements given the FIFO length is 5 only:\n");
	for(i = 0; i < FIFO_BUF_LENGTH; i++)
	{
		FIFO_testing(FIFO_enqueue(&fifo_test, i), FIFO_NO_ERROR, passed, failed);
	}

	for(i = 0; i < 2; i++)
	{
		FIFO_testing(FIFO_enqueue(&fifo_test, i), FIFO_FULL, passed, failed);
	}

	// Printing
	printf("\nVerifying enqueue with printing:\n");
	FIFO_testing(FIFO_print(&fifo_test), FIFO_NO_ERROR, passed, failed);

	// Is full?
	printf("\nTesting capacity: FIFO is full\n");
	FIFO_testing(FIFO_is_full(&fifo_test), FIFO_FULL, passed, failed);

	// Dequeue
	printf("\nTesting Dequeue:\n");
	for(i = 0; i < FIFO_BUF_LENGTH - 2; i++)
	{
		FIFO_testing(FIFO_dequeue(&fifo_test, &temp), FIFO_NO_ERROR, passed, failed);
	}

	// Printing
	printf("\nVerifying dequeue with printing:\n");
	FIFO_testing(FIFO_print(&fifo_test), FIFO_NO_ERROR, passed, failed);

	// Is empty?
	printf("\nTesting capacity: FIFO is not empty\n");
	FIFO_testing(FIFO_is_empty(&fifo_test), FIFO_NOT_EMPTY, passed, failed);

	// Make empty
	printf("\nMaking FIFO empty:\n");
	FIFO_testing(FIFO_make_empty(&fifo_test), FIFO_NO_ERROR, passed, failed);

	// Is empty?
	printf("\nTesting capacity: FIFO is empty\n");
	FIFO_testing(FIFO_is_empty(&fifo_test), FIFO_EMPTY, passed, failed);


	printf("\nTest Report:\n");
	printf("Total Cases  : %2d\n", passed + failed);
	printf("Total Passed : %2d\n", passed);
	printf("Total Failed : %d\n", failed);




	return 0;
}
