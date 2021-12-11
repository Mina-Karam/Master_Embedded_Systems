/*
 * main.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description: Generate permutations of a given string
 *
 */

#include <stdio.h>

void changePosition (char *ch1, char *ch2);
void charPermutations (char *cht, int startNumber, int endNumber);

int main()
{
	char str[]= "abcd";
	printf("Pointer : Generate permutations of a given string :\n");
    printf("----------------------------------------------------\n");

	printf("The permutations of the string are : \n");
	charPermutations(str, 0, 4);

	return 0;
}

void changePosition (char *ch1, char *ch2)
{
	char temp;

	temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;

}

void charPermutations (char *cht, int startNumber, int endNumber)
{
	int i;
	if(startNumber == endNumber)
	{
		printf("%s ",cht);
	}
	else
	{
		for (i = startNumber; i < endNumber; i++)
		{
			changePosition((cht+startNumber), (cht+i));
			charPermutations(cht, startNumber+1, endNumber);
			changePosition((cht+startNumber), (cht+i));
		}
	}
}
/*
 * main.c
 *
 * Created on : Dec 10, 2021
 *     Author : Mina Karam
 *      
 * Description: Generate permutations of a given string
 *
 */

#include <stdio.h>

void changePosition (char *ch1, char *ch2);
void charPermutations (char *cht, int startNumber, int endNumber);

int main()
{
	char str[]= "abcd";
	printf("Pointer : Generate permutations of a given string :\n");
    printf("----------------------------------------------------\n");

	printf("The permutations of the string are : \n");
	charPermutations(str, 0, 4);

	return 0;
}

void changePosition (char *ch1, char *ch2)
{
	char temp;

	temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;

}

void charPermutations (char *cht, int startNumber, int endNumber)
{
	int i;
	if(startNumber == endNumber)
	{
		printf("%s ",cht);
	}
	else
	{
		for (i = startNumber; i < endNumber; i++)
		{
			changePosition((cht+startNumber), (cht+i));
			charPermutations(cht, startNumber+1, endNumber);
			changePosition((cht+startNumber), (cht+i));
		}
	}
}
