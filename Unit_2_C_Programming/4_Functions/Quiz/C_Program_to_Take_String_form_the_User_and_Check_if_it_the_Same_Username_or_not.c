/*
 * C_Program_to_Take_String_form_the_User_and_Check_if_it_the_Same_Username_or_not.c
 *
 * Created on : Nov 8, 2021
 *     Author : Mina Karam
 *      
 * Description: A c program to take string from the user and compare it with the user-name which inputed by the user to give him a check that the use is correct.
 *
 */

#include <stdio.h>
#include <string.h>

/* Main Function */
int main()
{
	char arr1[100], arr2[100]; /* declaring the required arrays one for the string and the other for the user name */
	int result;	/* declaring result variable to contain the result of comparing presses */

	/* Asking the user to enter the string */
	printf("Enter a string : ");
	fflush(stdout);
	gets(arr1);

	/* Asking the user to enter his user-name */
	printf("Enter your username : ");
	fflush(stdout);
	gets(arr2);

	/* Comparing process using "stricmp" from string.h library */
	result = stricmp(arr1, arr2); /* Comparing with neglect the capital or small character */

	/* Checking and print the result of comparing process */
	if (result == 0)
		printf("Identical");
	else
		printf("Different");

	return 0;
}/* End of Main Function */
