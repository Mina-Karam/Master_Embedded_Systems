/*
 ======================================================================================================================
 Name        : EX1_C_Program_to_Check_a_Number_Is_Even.c
 Author      : Mina Karam
 Created on	 : Jul 31, 2021
 Description : Unit 2 C-Progtamming >> Assignment 2 C-Basic >> EX1 C Program to check a number is even
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>
int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if(num % 2 == 0)
        printf("%d is even.", num);
    else
        printf("%d is odd.", num);
    
    return 0;
}