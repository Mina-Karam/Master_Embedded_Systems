/*
 * EX4_C_Program_to_Calculate_the_Power_of_a_Number_Using_Recursion.c
 *
 * Created on : Nov 5, 2021
 *     Author : Mina Karam
 *      
 * Description: This program calculates the power of a number using recursion. The number will be entered by the user
 *    				 and then the power will be calculated and printed on the screen
 */

# include <stdio.h>
# include <string.h>


/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Declaration ---------------------------*/
/* ----------------------------------------------------------------------- */

int power(int number, int toPower) ;

/* Main Function */
int main ()
{
	int number, toPower ;					/* declaring the required variables */

	printf ("Enter base number: ");			/* read and store the base number from the user */
	fflush(stdin);	fflush(stdout);
	scanf ("%d", &number);

	printf ("Enter power number(Positive integer: ");			/* read and store the power from user */
	fflush(stdin);	fflush(stdout);
	scanf ("%d", &toPower);

	printf ("%d^%d = %d", number, toPower, power(number, toPower));	/* print the result using function recursion */

	return 0;
} /* End of Main Function */

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Definition ----------------------------*/
/* ----------------------------------------------------------------------- */

int power(int number, int toPower)
{
	if (toPower == 0)
		return 1;				/* case power of zero */
	else if (toPower == 1)
		return number;			/* case of power one */
	else
		return (number * power(number, toPower-1));		/* power calculation */
}		/* End of power function */


