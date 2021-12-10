/*
 * main.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description: Pointer : Demonstrate the use of & and * operator
 *
 */

#include <stdio.h>

int main()
{
	int m = 300;
	float fx = 300.600006;
	char cht = 'z';

	int *P_m = &m;
	float *P_fx = &fx;
	char *P_cht = &cht;

	printf ( " m = %d \n",m);
	printf ( " fx = %f \n",fx);
	printf ( " cht = %c \n",cht);

	printf("\n Using & operator :\n");
	printf("-----------------------\n");

	printf("Address of m : %p \n", &m);
	printf("Address of fx : %p \n", &fx);
	printf("Address of cht : %p \n", &cht);

	printf("\n Using & and * operator :\n");
	printf("-----------------------------\n");

	printf("Value at address of m : %d \n", *(&m));
	printf("Value at address of fx : %f \n", *(&fx));
	printf("Value at address of cht : %c \n", *(&cht));

	printf("\n Using only pointer variable :\n");
	printf("----------------------------------\n");

	printf("address of m : %p \n", P_m);
	printf("address of fx : %p \n", P_fx);
	printf("address of cht : %p \n", P_cht);

	printf("\n Using only pointer operator :\n");
	printf("----------------------------------\n");

	printf("Value of address of m : %d",*P_m);
	printf("Value of address of fx : %f",*P_fx);
	printf("Value of address of cht : %c",*P_cht);




	return 0;
}
