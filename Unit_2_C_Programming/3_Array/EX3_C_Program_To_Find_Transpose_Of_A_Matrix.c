/*
 * EX3_C_Program_To_Find_Transpose_Of_A_Matrix.c
 *
 *  Created on: Oct 29, 2021
 *      Author: MinaK
 */

#include <stdio.h>

int main()
{
	int matrix[100][100];
	int t_matrix[100][100];

	int row, column;

	int i, j;

	/* Assign rows and columns */
	printf("Enter rows and column of matrix : ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &row, &column);

	/* Assign matrix values */
	printf("Enter element of the matrix : \n");
	for (i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("Enter element %d%d : ", i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d", &matrix[i][j]);
		}
	}

	/* printing matrix */
	printf("Entered matrix:\n");
	for (i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	/* calculating transpose */
	for (i = 0; i < row; i++)
	{
		for(j = 0; j < column; j++)
		{
			t_matrix[j][i] = matrix[i][j];
		}
	}

	/* printing transpose matrix */
	printf("Transpose of Matrix:\n");
	for (i = 0; i < column; i++)
	{
		for(j = 0; j < row; j++)
		{
			printf("%d ", t_matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
