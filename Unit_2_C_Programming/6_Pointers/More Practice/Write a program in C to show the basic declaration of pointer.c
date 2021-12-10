/*
 * main.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */

#include <stdio.h>

int main()
{
	int m =10, n, o;
	int *z= &m;

	fflush(stdin); fflush(stdout);
	printf("z stores the address of m : %p \n", z);
	printf("*z stores the value of m : %d \n",*z);

	printf("&m in the address of m : %p \n",&m);

	printf("&n store the address of n : %p \n",&n);
	printf("&o store the address of o : %p \n",&o);
	printf("&z store the address of z : %p \n",&z);

	return 0;
}
