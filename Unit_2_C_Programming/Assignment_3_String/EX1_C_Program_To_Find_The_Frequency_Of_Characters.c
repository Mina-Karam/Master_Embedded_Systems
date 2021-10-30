/*
 * EX1_C_Program_To_Find_The_Frequency_Of_Characters.c
 *
 *  Created on: Oct 30, 2021
 *      Author: MinaK
 */

#include <stdio.h>

int main()
{
	char text[100], char_to_find, counter = 0;
	int i;

	/* Assigning the string */
	printf("Enter a string : ");
	fflush(stdin); fflush(stdout);
	gets(text);

	/* Assigning the char to find it */
	printf("Enter a character to find frequency : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&char_to_find);

	/* getting the freq of the char which inputed */
	for (i = 0; i < sizeof(text); i++)
	{
		if(text[i] == char_to_find)
		{
			counter++;
		}
	}

	/* printing the counter of the char */
	printf("Frequency of e = %d", counter);

	return 0;
}
