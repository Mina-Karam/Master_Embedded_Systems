/*
 * EX4_C_Program_to_Print_the_Elements_of_an_Array_in_reverse_order.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */


#include <stdio.h>

int main()
{

	int n, i = 0, arr[15];
	int *P_arr = arr;

	printf("Enter the number of element : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);

	printf("input %d number of element\n", n);

	for(i = 0 ; i < n; i++)
	{
		printf("element - %d : ",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d",P_arr++);
	}

	P_arr = &arr[n-1];

	printf("\n");
	for(i = n ; i > 0; i--)
	{
		printf("element - %d : %d \n",i, *P_arr--);
	}

	return 0;
}
