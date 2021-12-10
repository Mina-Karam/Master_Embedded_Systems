/*
 * C_Program_to_Print_All_Alphabets_Using_a_pointer.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
	char alphabets[27];
	int i;
	char *Ptr ;
	printf("\n\n Pointer : Print all the alphabets:\n");
	printf("----------------------------------------\n");

	Ptr = alphabets ;

	for (i = 0; i < 26; ++i)
	{
		*Ptr = i +'A';
		Ptr++;
	}

	Ptr = alphabets;

	printf(" The Alphabets are : \n");

	for (i = 0; i < 26; ++i)
	{
		printf(" %c ", *Ptr);
		Ptr++;
	}

	return 0;
}

