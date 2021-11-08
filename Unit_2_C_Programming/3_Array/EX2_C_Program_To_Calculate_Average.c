/*
 * EX2_C_Program_To_Calculate_Average.c
 *
 *  Created on: Oct 29, 2021
 *      Author: MinaK
 */


#include <stdio.h>

int main()
{
	float arr[100];
	int max = 0;
	int i ;
	float average = 0;

	printf("Enter the number of data : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &max);

	for (i = 0; i < max; i++)
	{
		printf("%d. Enter number : ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f", &arr[i]);
	}

	for (i = 0; i < max; i++)
	{
		average += arr[i];
	}

	average /= max ;
	printf("Average = %0.2f", average);

	return 0;
}
