/*
 ======================================================================================================================
 Name        : EX3_C_Program_to_Find_The_Largest_Number.c
 Author      : Mina Karam
 Created on	 : Jul 31, 2021
 Description : Unit 2 C-Progtamming >> Assignment 2 C-Basic >> EX3 C Program to find the largest number
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main() 
{
    double num1, num2, num3;

    printf("Enter three different numbers: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    // if num1 is greater than both num2 and num3, num1 is the largest
    if (num1 >= num2 && num1 >= num3)
        printf("%.2f is the largest number.", num1);

    // if num2 is greater than both num1 and num3, num2 is the largest
    if (num2 >= num1 && num2 >= num3)
        printf("%.2f is the largest number.", num2);

    // if num3 is greater than both num1 and num2, num3 is the largest  
    if (num3 >= num1 && num3 >= num2)
        printf("%.2f is the largest number.", num3);

    return 0;
}