/*
 * C_Program_to_Demonstrate_How_to_Handle_the_Pointers_in_the_Program.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */

#include <stdio.h>

int main()
{
	int m = 29 ;
	int *ab = &m;

	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n",m);

	*ab = 29;

	printf("\nAddress of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n",*ab);

	m = 34;

	printf("\nAddress of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n",*ab);

	*ab = 7;

	printf("\nAddress of pointer m : 0x%p\n", &m);
	printf("Content of pointer m : %d\n",m);


	return 0;
}
