/*
 * C_Function_to_take_an_Integer_Number_and_Calculate_its_Square_Root.c
 *
 * Created on : Nov 17, 2021
 *     Author : Mina Karam
 *      
 * Description:	This C function takes an integer number from the user and calculate
 *      		it's square root, then the result will be displayed on the screen.
 */


#include <stdio.h>
#include <math.h>

int main()
{
    double num, root;

    printf("Enter any number to find square root: ");
    fflush(stdout); fflush(stdin);
    scanf("%lf", &num);

    root = sqrt(num);

    printf("Square root of %.0lf = %.3lf", num, root);

    return 0;
}
