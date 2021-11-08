/*
 ======================================================================================================================
 Name        : EX5_C_Program_to_Find_ASCII_Value_of_a_Character.c
 Author      : Mina Karam
 Created on	 : Jul 30, 2021
 Description : Unit 2 C-Progtamming >> Assignment 1 C-Basic >> EX5 C Program to Find ASCII Value of a Character
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main()
{
   char c;

   printf("Enter a character: ");
   scanf("%c",&c);

   printf("ASCII value of %c = %d",c,c);

   return 0;
}

