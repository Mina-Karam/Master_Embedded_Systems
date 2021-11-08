/*
 * EX3_C_Program_to_Reverse_a_Sentence_Using_Recursion.c
 *
 * Created on : Nov 5, 2021
 *     Author : Mina Karam
 *      
 * Description: This program prints a sentences entered by the user in a reverse order using recursion.
 */

#include <stdio.h>

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Declaration ---------------------------*/
/* ----------------------------------------------------------------------- */
void reverseSentence();

/* Main Function */
int main()
{

	/* Asking the user to enter any sentence as reversed */
	printf ("Enter a sentence: ");
	fflush(stdin);	fflush(stdout);
	reverseSentence(); /* calling the function to reverse the sentence */

	return 0;
} /* End of Main Function */

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Definition ----------------------------*/
/* ----------------------------------------------------------------------- */

void reverseSentence()
{
	char c;
	scanf("%c", &c);
	if (c != '\n') /* to stop the recursion if getting null*/
	{
		reverseSentence(); /* calling again */
		printf("%c", c);
	}
}
