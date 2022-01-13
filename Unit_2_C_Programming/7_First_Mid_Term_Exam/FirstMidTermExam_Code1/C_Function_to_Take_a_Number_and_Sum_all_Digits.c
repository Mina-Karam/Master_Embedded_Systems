/*
 * C_Function_to_Take_a_Number_and_Sum_all_Digits.c
 *
 * Created on : Nov 17, 2021
 *     Author : Mina Karam
 *      
 * Description:	This C program takes a number and sum its all digits.
 */

#include<stdio.h>

int main()
{
    int n, remainder, sum = 0;

    printf("Enter a number: ");
    fflush(stdout);	fflush(stdin);
    scanf("%d", &n);

    while(n != 0)
    {
        remainder = n % 10;
        sum += remainder;
        n = n / 10;
    }

    printf("sum = %d", sum);

    return 0;
}
