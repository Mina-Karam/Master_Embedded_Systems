/*
 ======================================================================================================================
 Name        : EX6_C_Program_to_Swap_Two_Numbers.c
 Author      : Mina Karam
 Created on	 : Jul 30, 2021
 Description : Unit 2 C-Progtamming >> Assignment 1 C-Basic >> EX6 C Program to Swap Two Numbers
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main()
{
	float num1, num2, temp;

	printf("Enter value of a: ");
	scanf("%f",&num1);
	printf("Enter value of b: ");
	scanf("%f",&num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("\nAfter swapping, value of a = %.2f\n", num1);
	printf("After swapping, value of b = %.2f", num2);

	return 0;
}
