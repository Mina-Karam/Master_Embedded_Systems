/*
 * C_Function_to_Sum_Numbers_From_1_To_100_Without_Loop.c
 *
 * Created on : Nov 17, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */




#include <stdio.h>

int i = 0;
int sum = 0;

int main()
{
	if (i <= 100)
	{
		sum += i;
		i++;
		main();
	}

	if (i==101)
	{
		printf("\nSum of Numbers from 0 to 100 is: %d ", sum);
		i= 102;
	}

	return 0;
}
