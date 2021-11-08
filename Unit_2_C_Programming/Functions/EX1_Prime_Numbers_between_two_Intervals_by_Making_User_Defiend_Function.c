/*
 * EX1_Prime_Numbers_between_two_Intervals_by_Making_User_Defiend_Function.c
 *
 *  Created on: Nov 5, 2021
 *      Author: Mina Karam
 *
 *      Description: program that find and print the prime numbers between two intervals entered by the user.
 */

#include <stdio.h>

/* Declaring Functions(Functions Prototypes) */
void getPrimeNumbers(int firstNumber, int secondNumber);

/* Main Function */
int main()
{
	int firstNumber, secondNumber ; 							/* declare variables for the range. */

	printf("Enter two numbers(intervals) : "); 				/* asking the user to enter the range. */
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &firstNumber, &secondNumber); 				/* scan and store the range from the user. */

	getPrimeNumbers(firstNumber,secondNumber); 					/* call the function to find all prime numbers in range user entered. */

	return 0;
}

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Definition ----------------------------*/
/* ----------------------------------------------------------------------- */

void getPrimeNumbers(int firstNumber, int secondNumber)
{
	int i, arrayCounter = 0, j, k, flag = 0;
	int array[100]; /* Declaring an array to store the prime numbers in it  */

	/* check which number is bigger to compare it right */
	if(firstNumber > secondNumber) /* if ture we will swap it to get in first number the lower one*/
	{
		int temp;  /* Temporary variable to contain the first number */

		temp = firstNumber;
		firstNumber = secondNumber;
		secondNumber = temp;
	}

	/* check if the range is between 0 and 1. */
	if(firstNumber <= 1 && secondNumber == 1)  /* Back Here*/
	{
		printf("There is no prime numbers between %d and %d", firstNumber, secondNumber);
	}

	/* check if the range is between  0 or 1 and 2. */
	else if(firstNumber <= 1 && secondNumber == 2)  /* Back Here*/
	{
		printf("The prime numbers between %d and %d are: %d", firstNumber, secondNumber, secondNumber);
	}

	/**********************************************************/

	/* What is a prime number?
	 * 	 A prime number is a number greater than 1 with only two factors – themselves and 1.
	 * 	 A prime number cannot be divided by any other numbers without leaving a remainder.
	 *   An example of a prime number is 13. It can only be divided by 1 and 13.
	 *   Dividing a prime number by another number results in numbers left over e.g. 13 ÷ 6 = 2 remainder 1.
	 */

	/**********************************************************/

	/* get the prime number in the range */
	else
	{
		for (i = firstNumber+1; i < secondNumber; i++) /* looping through the range from first number + 1 to second number */
		{
			if(i == 2)
			{
				array[arrayCounter] = i;
				arrayCounter++;
			}
			else if ((i % 2) != 0 && i > 2) /* exclude all even number & bigger than 2 */
			{
				for(k = 3; k <= i ; k++) /* divide each number in the range on 3 till the number itself */
				{
					if(i % k == 0) /* each prime number is divided on itself */
					{
						flag = 1;
					}
				}
				if (flag == 1)
				{
					array[arrayCounter] = i;
					arrayCounter++;
				}
			}
		} /* end of for */

		/* After checking all number between range, print the array of prime number */

		printf("The Prime numbers between %d and %d are: ", firstNumber, secondNumber);

		for (j = 0; j < arrayCounter; j++)
		{
			printf("%d ", array[j]); /*print each single value in the array */
		}
	}

} /* end of the function*/
