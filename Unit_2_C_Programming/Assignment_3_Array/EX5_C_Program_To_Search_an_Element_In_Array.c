/*
 * EX5_C_Program_To_Search_an_Element_In_Array.c
 *
 *  Created on: Oct 29, 2021
 *      Author: MinaK
 */

#include <stdio.h>

int main()
{
	int arr[100];
	int num_element, searched_num ;
	int i;

	/* Assign number of element */
	printf("Enter no of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num_element);

	/* Assign element values */
	for (i = 0; i < num_element; i++)
	{
		scanf("%d", &arr[i]);
	}

	/* Assign the inserted value */
	printf("Enter the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &searched_num);

	/* Finding the location of the input number*/
	for (i = 0; i < num_element; i++)
	{
		if(arr[i] == searched_num)
		{
			printf("Number found at the location = %d",i+1);
			break;
		}
	}

	return 0;
}
