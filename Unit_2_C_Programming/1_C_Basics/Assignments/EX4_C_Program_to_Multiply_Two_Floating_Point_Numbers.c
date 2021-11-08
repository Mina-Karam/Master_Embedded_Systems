/*
 ======================================================================================================================
 Name        : EX4_C_Program_to_Multiply_Two_Floating_Point_Numbers.c
 Author      : Mina Karam
 Created on	 : Jul 30, 2021
 Description : Unit 2 C-Progtamming >> Assignment 1 C-Basic >> EX4 C Program to Multiply two Floating Point
 	 	 	   Numbers using Ansi-style (c99)
 ======================================================================================================================
 */
#include <stdio.h>

int main( )
{
   float num1, num2, multi;

   printf("Enter two numbers: ");
   scanf("%f %f",&num1,&num2);

   multi = num1 * num2;

   printf("multi: %f",multi);

   return 0;
}

