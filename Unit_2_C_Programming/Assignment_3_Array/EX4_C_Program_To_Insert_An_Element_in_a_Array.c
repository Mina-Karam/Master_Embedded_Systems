/*
 * EX4_C_Program_To_Insert_An_Element_in_a_Array.c
 *
 *  Created on: Oct 29, 2021
 *      Author: MinaK
 */

#include <stdio.h>

int main()
{
	int arr[100];
	int num_element, inserted_num, location;
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
	scanf("%d", &inserted_num);

	/* Assign location in the array */
	printf("Enter the location : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &location);

	/* Inserting process */
	for (i = num_element-1; i >0 ; i--)
	{
		arr[i+1] = arr [i];
		if (arr[i] == location)
		{
			arr[i] = inserted_num;
		}
	}

	/* Printing new array */
	for (i = 0; i < num_element+1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
