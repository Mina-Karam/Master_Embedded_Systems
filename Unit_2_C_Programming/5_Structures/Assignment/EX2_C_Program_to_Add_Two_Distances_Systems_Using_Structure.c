/*
============================================================================
 Name        : C_Program_to_Add_Two_Distances_Systems_Using_Structure.c
 Author      : Mina Karam
 Created on  : Nov 30, 2021
 Description : C Program to Add Two Distances Systems Using Structure
 ============================================================================
 */

#include <stdio.h>

struct S_Distance
{
	int m_Feet;
	float m_Inch;
};

struct S_Distance ReadDistances();
struct S_Distance AddDistances (struct S_Distance First_Distance, struct S_Distance Second_Distance);
void PrintDistance (struct S_Distance Result);


int main()
{
	struct S_Distance First_Distance, Second_Distance, Result;

	printf ("Enter the 1st distance below in feet and inches: \n" );
	First_Distance = ReadDistances();

	printf ("\nEnter the 2nd distance below in feet and inches: \n" );
	Second_Distance = ReadDistances();

	Result = AddDistances(First_Distance, Second_Distance);

	PrintDistance(Result);
	return 0;
}

struct S_Distance ReadDistances()
{
	struct S_Distance Distance;

		printf ("\nEnter the distance in feet is: " );
		fflush (stdin); fflush(stdout);
		scanf ("%d", &Distance.m_Feet );

		printf ("\nEnter the distance in inches: " );
		fflush (stdin); fflush(stdout);
		scanf ("%f", &Distance.m_Inch );

		return Distance ;
}

struct S_Distance AddDistances (struct S_Distance First_Distance, struct S_Distance Second_Distance)
{
	struct S_Distance Result;

	Result.m_Feet = First_Distance.m_Feet + Second_Distance.m_Feet ;
	Result.m_Inch = First_Distance.m_Inch + Second_Distance.m_Inch;

	while(Result.m_Inch >= 12)
	{
		Result.m_Inch = Result.m_Inch - 12.0;
		++Result.m_Feet;
	}

	return Result ;
}

void PrintDistance (struct S_Distance Result)
{
	printf ("\nThe SUM of the distances is: %d',-%.1f\".", Result.m_Feet, Result.m_Inch);
}
