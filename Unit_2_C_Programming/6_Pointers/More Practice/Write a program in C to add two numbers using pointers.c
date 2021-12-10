/*
 * main.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description: Pointer : Add two numbers
 *
 */

#include <stdio.h>

int n1, n2, sum;
int *P_n1 , *P_n2, *P_sum;


void get_sum(int *PF_n1,int *PF_n2)
{
	P_sum = &sum;
	*P_sum = *PF_n1 + *PF_n2;
}

int main()
{

	P_n1 = &n1;
	P_n2 = &n2;

	printf("Input the first number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n1);

	printf("Input the Second number : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n2);

	get_sum(P_n1,P_n2);

	printf("\nThe sum of %d + %d = %d", *P_n1, *P_n2, *P_sum);
	return 0;
}
