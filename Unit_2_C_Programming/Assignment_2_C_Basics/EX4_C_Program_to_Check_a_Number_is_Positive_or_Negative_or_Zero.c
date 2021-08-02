/*
 ======================================================================================================================
 Name        : EX4_C_Program_to_Check_a_Number_is_Positive_or_Negative_or_Zero.c
 Author      : Mina Karam
 Created on	 : Aug 2, 2021
 Description : Unit 2 C-Progtamming >> Assignment 2 C-Basic >> EX4 C Program to check a number is positive or negative or zero
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main() 
{
    float num;

    printf("Enter a number: ");
    scanf("%f", &num);

    if (num <= 0) 
    {
        if (num == 0)
        {
            printf("You entered 0.");
        }
        else
        {
            printf("You entered a negative number.");
        }  
    } 
    else
    {
        printf("You entered a positive number.");
    }
    return 0;
}