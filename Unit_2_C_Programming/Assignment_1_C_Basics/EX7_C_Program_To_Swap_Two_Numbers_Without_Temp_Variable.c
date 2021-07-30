/*
 ======================================================================================================================
 Name        : EX7_C_Program_To_Swap_Two_Numbers_Without_Temp_Variable.c
 Author      : Mina Karam
 Created on	 : Jul 31, 2021
 Description : Unit 2 C-Progtamming >> Assignment 1 C-Basic >> EX7 Swap Two Numbers Without Temp Variable
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main()
{
    int x = 50, y = 9;
 
    // Code to swap 'x' and 'y'
    x = x + y; // x now becomes 59
    y = x - y; // y becomes 50
    x = x - y; // x becomes 9
 
    printf("After Swapping: x = %d, y = %d", x, y);
 
    return 0;
}
