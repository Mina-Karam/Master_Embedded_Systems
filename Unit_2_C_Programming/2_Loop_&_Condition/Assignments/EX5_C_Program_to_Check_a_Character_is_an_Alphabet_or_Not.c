/*
 ======================================================================================================================
 Name        : EX5_C_Program_to_Check_a_Character_is_an_Alphabet_or_Not.c
 Author      : Mina Karam
 Created on	 : Jul 31, 2021
 Description : Unit 2 C-Progtamming >> Assignment 2 C-Basic >> EX5 C Program to check a character is an alphabet or not
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main() 
{
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        printf("%c is an alphabet.", c);
    }
    else
    {
        printf("%c is not an alphabet.", c);
    }
    return 0;
}