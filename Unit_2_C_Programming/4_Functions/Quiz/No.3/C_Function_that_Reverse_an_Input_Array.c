/*
 * C_Function_that_Reverse_an_Input_Array.c
 *
 * Created on : Nov 13, 2021
 *     Author : Mina Karam
 *      
 * Description: This c program reverse the elements of an array entered by the user.
 *
 */


#include <stdio.h>

/*---------------------------------------------*/
/*------------ Function Declaration -----------*/
/*---------------------------------------------*/

void inputArray(int arr[], int size); /* Function to take the element form the user */
void printArray(int arr[], int size); /* Function to print the element form the user */
void reverseArray(int arr[], int size);	/* Function to reverse the array elements */


/* Main Function */
int main()
{
	int arr[100], size; /* Declaring an array to store the elements and its size*/

	/* Ask user to enter the size of array and store it */
	printf ("Enter the size of array: ");
	fflush (stdout); fflush (stdin);
	scanf ("%d", &size);

	/* Read the elements of the array from the user */
	printf ("Enter %d element of array : ", size);
	fflush (stdout); fflush (stdin);
	inputArray(arr, size);

	/* Print the elements of the array */
	printf ("\nThe array elements before reverse are: ");
	printArray (arr, size);

	/* Reverse the elements of the array */
	reverseArray(arr, size);

	/* Print the reversed elements of the array */
	printf("\nThe array elements after reverse: ");
	printArray (arr, size);

	return 0;
}/* End of Main Function */

/*---------------------------------------------*/
/*------------- Function Definition -----------*/
/*---------------------------------------------*/

void inputArray(int arr[], int size)
{
	int i;
	/*Taking the element from the user and store it */
	for (i = 0; i < size; ++i)
	{
		scanf("%d",&arr[i]);
	}
}/* End of inputArray Function */

/*---------------------------------------------*/

void printArray(int arr[], int size)
{
	int i;
	/*printing the array */
	for (i = 0; i < size; ++i)
	{
		printf("%d ",arr[i]);
	}
}/* End of printArray Function */

/*---------------------------------------------*/

void reverseArray(int arr[], int size)
{
	int i,j, temp;
	for (i = 0, j = size-1; i <= j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
} /* End of reverseArray Function */

