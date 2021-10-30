/*
 * EX2_C_Program_To_Find_The_Length_of_a_String.c
 *
 *  Created on: Oct 30, 2021
 *      Author: MinaK
 */


#include <stdio.h>

int main()
{
	char text[100], length = 0;
	int i;

	/* Assigning the string */
	printf("Enter a string : ");
	fflush(stdin); fflush(stdout);
	gets(text);

	/* Calculating length */
	for (i = 0; text[i] != '\0' ; i++)
	{
		length++;
	}

	/* printing the length */
	printf("Length of string : %d", length);

	return 0;
}
