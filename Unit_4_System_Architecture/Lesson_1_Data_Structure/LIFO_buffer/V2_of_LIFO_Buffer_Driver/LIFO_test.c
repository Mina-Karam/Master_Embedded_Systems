/*
 * lifo_test.c
 *
 * Created on : Jan 11, 2022
 *     Author : Mina Karam
 */

#include "lifo.h"
#include "stdio.h"

#define LIFO_buf_length 5

#define LIFO_testing(LIFO_function, pass_condition, pass_count, fail_count)		\
		if((LIFO_function) == (pass_condition))									\
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
	LIFO_Buf_st LIFO_test;

	element_type test_buf[LIFO_buf_length];

	element_type i, temp = 0, passed = 0, failed = 0;

	//Initialization
	printf("Testing Initialization:\n");
	LIFO_testing(LIFO_init(&LIFO_test, test_buf, LIFO_buf_length), LIFO_NO_ERROR, passed, failed);

	//pushing
	printf("Testing pushing:\n");
	for (i = 0; i < LIFO_buf_length; i++)
	{
		LIFO_testing(LIFO_push(&LIFO_test, temp),  LIFO_NO_ERROR, passed, failed);
	}

	//Printing
	printf("\nVerifying pushing with printing:\n");
	LIFO_testing(LIFO_print(&LIFO_test), LIFO_NO_ERROR, passed, failed);

	//Is full ?!
	printf("\nTesting capacity: LIFO is full\n");
	LIFO_testing(LIFO_is_full(&LIFO_test), LIFO_FULL, passed, failed);

	//Popping
	printf("\nTesting Popping:\n");
	for(i = 0; i < LIFO_buf_length; i++)
	{
		LIFO_testing(LIFO_top(&LIFO_test, &temp), LIFO_NO_ERROR, passed, failed);
	}

	// Top
	printf("\nTesting top item: 1\n");
	LIFO_testing(LIFO_top(&LIFO_test, &temp), LIFO_NO_ERROR, passed, failed);

	// Printing
	printf("\nVerifying popping with printing:\n");
	LIFO_testing(LIFO_print(&LIFO_test), LIFO_NO_ERROR, passed, failed);

	//Is empty ?!
	printf("\nTesting capacity: LIFO is not empty\n");
	LIFO_testing(LIFO_is_empty(&LIFO_test), LIFO_NOT_EMPTY, passed, failed);

	//Make empty
	printf("\nMaking LIFO empty:\n");
	LIFO_testing(LIFO_make_empty(&LIFO_test), LIFO_NO_ERROR, passed, failed);

	//Is empty ?!
	printf("\nTesting capacity: LIFO is empty\n");
	LIFO_testing(LIFO_is_empty(&LIFO_test), LIFO_EMPTY, passed, failed);


	printf("\nTest Report:\n");
	printf("Total Cases  : %2d\n", passed + failed);
	printf("Total Passed : %2d\n", passed);
	printf("Total Failed : %d\n", failed);
	return 0;
}
