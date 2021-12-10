/*
 * main.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */

#include <stdio.h>

int main()
{
	int m =29;
	int *ab = &m;

	printf("Address of pointer ab : %p \n", ab);
	printf("Value of pointer ab : %d \n", *ab);

	m = 34;

	printf("Address of pointer ab : %p \n", ab);
	printf("Value of pointer ab : %d \n", *ab);

	*ab = 7;

	printf("Address of pointer ab : %p \n", ab);
	printf("Value of pointer ab : %d \n", *ab);

	return 0;
}
