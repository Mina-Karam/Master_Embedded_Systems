/*
 ======================================================================================================================
 Name        : EX2_C_Program_to_Check_Vowel_or_Consonant_Letter.c
 Author      : Mina Karam
 Created on	 : Jul 31, 2021
 Description : Unit 2 C-Progtamming >> Assignment 2 C-Basic >> EX2 C Program to check vowel or consonant letter
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main() 
{
    char c;
    int lowercase_vowel, uppercase_vowel;

    printf("Enter an alphabet: ");
    scanf("%c", &c);

    lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

    uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (lowercase_vowel || uppercase_vowel)
        printf("%c is a vowel.", c);
    else
        printf("%c is a consonant.", c);

    return 0;
}