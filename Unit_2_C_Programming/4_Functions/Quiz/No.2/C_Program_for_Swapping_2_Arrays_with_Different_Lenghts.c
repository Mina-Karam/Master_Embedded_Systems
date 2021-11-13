/*
 * C_Program_for_Swapping_2_Arrays_with_Different_Lenghts.c
 *
 * Created on : Nov 13, 2021
 *     Author : Mina Karam
 *      
 * Description: A C program to take 2 array with different sizes and swapping it. The main idea of the program
 * 				is to  prints both arrays before and after swapping to prove the effect of
 * 				the program's functionality.
 *
 */

#include <stdio.h>

/* Pre-processing part */

#define MAX_SIZE 100

/*-----------------------------------------------------*/
/*----------------Function Deceleration----------------*/
/*-----------------------------------------------------*/

void inputArray(int arr[], int size);	/* Function to input the array elements */
void printArray(int arr[], int size);	/* Function to print the array elements */
void swapArray(int firstArr[], int secondArr[]);	/* Function to swap the elements of the array */


/* Main Function */
int main()
{
	int firstArr[MAX_SIZE];
	int secoundArr[MAX_SIZE];
	int sizeOfFirstArray, sizeOfSecondArray;

	/* Asking the user to input the size of the first array and store it*/
	printf("Enter size of First array (max 100) : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&sizeOfFirstArray);

	/* Asking the user to input the size of the second array and store it*/
	printf("Enter size of Second array (max 100) : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&sizeOfSecondArray);

	/* Asking the user to input the elements of the first array */
	printf("Enter %d elements in first array: ",sizeOfFirstArray);
	fflush(stdout); fflush(stdin);
	inputArray(firstArr, sizeOfFirstArray);

	/* Asking the user to input the elements of the second array */
	printf("Enter %d elements in second array: ",sizeOfSecondArray);
	fflush(stdout); fflush(stdin);
	inputArray(secoundArr, sizeOfSecondArray);


	/* Printing both arrays before swapping*/
	printf("\nFirst array before swapping: ");
	fflush(stdout);
	printArray(firstArr, sizeOfFirstArray);

	printf("\nSecond array before swapping: ");
	fflush(stdout);
	printArray(secoundArr, sizeOfSecondArray);

	/* swapping process */
	swapArray(firstArr, secoundArr);

	/* Printing both arrays before swapping*/
	printf("\n\nFirst array after swapping: ");
	fflush(stdout);
	printArray(firstArr, sizeOfFirstArray);

	printf("\nSecond array after swapping: ");
	fflush(stdout);
	printArray(secoundArr, sizeOfSecondArray);


	return 0;
}/* End of Main Function*/

/*-----------------------------------------------------*/
/*----------------Function Definitions-----------------*/
/*-----------------------------------------------------*/

void inputArray(int arr[], int size)
{
	int i;
	/* Taking the element one by one form the user */
	for (i = 0; i < size; ++i)
	{
		scanf("%d", &arr[i]);
	}
}

/*-----------------------------------------------------*/

void printArray(int arr[], int size)
{
	int i;
	/* Print the element of array one by one */
	for (i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}

/*-------------------------------------------*/

void swapArray(int firstArr[], int secondArr[])
{
	int i;
	int tempArr[MAX_SIZE];
	for (i = 0; i < MAX_SIZE; ++i)
	{
		/* Write any swapping techniques */
		tempArr[i] = firstArr[i];
		firstArr[i] = secondArr[i];
		secondArr[i] = tempArr[i];

	}
}
