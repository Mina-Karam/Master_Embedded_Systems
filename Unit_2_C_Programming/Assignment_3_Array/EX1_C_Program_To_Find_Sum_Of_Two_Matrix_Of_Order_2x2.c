/*
 * EX1_C_Program_To_Find_Sum_Of_Two_Matrix_Of_Order_2x2.c
 *
 *  Created on: Oct 29, 2021
 *      Author: MinaK
 */

#include <stdio.h>

int main()
{
	float a [2][2];
	float b [2][2];
	int i,j;

	/* Enter values of matrix a */
	printf("Enter the element of 1st matrix\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("Enter a%d%d : ", i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &a[i][j]);
		}
	}

	/* Enter values of matrix b */
	printf("Enter the element of 2st matrix\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("Enter b%d%d : ", i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &b[i][j]);
		}
	}

	/*Calculation of sum of matrix*/
	printf("\nSum Of Matrix\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			a[i][j] += b[i][j];
			printf("%0.1f ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

