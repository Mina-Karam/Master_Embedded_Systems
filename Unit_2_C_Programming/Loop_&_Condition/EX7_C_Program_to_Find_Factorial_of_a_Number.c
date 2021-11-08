/*
 ======================================================================================================================
 Name        : EX7_C_Program_to_Find_Factorial_of_a_Number.c
 Author      : Mina Karam
 Created on	 : Aug 2, 2021
 Description : Unit 2 C-Progtamming >> Assignment 2 C-Basic >> EX7 C Program to find factorial of a number
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main() 
{
    int n, i;
    unsigned long long fact = 1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Error! Factorial of a negative number doesn't exist.");
    }
    else 
    {
        for (i = 1; i <= n; ++i) 
        {
            fact *= i;
        }
        printf("Factorial of %d = %llu", n, fact);
    }
    return 0;
}