/*
 * EX3_C_Program_to_Print_a_String_in_Reverse_Using_a_Pointer.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *
 * Description:
 */

#include <stdio.h>

int main()
{
	char str[10];
	char revstr[10];

	char *P_str= str;
	char *P_revstr = revstr;

	int i = -1;

	printf("Input a string : ");
//	fflush(stdin); fflush(stdout);
	scanf("%s", str);

	while(*P_str)
	{
		P_str++;
		i++;
	}

	while(i>=0)
	{
		P_str--;
		*P_revstr = *P_str;
		P_revstr++;
		--i;
	}

	*P_revstr = '\0';

	printf("Reverse of the string is : %s\n\n", P_revstr);

	return 0;
}
