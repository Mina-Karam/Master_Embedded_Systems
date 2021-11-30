/*
 * EX3_C_Program_to_Add_Two_Complex_Numbers_by_Passing_Structure_to_a_Function.c
 *
 * Created on : Nov 30, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */

#include <stdio.h>

struct S_ComplexNumber
{
	float m_R;
	float m_I;
};

struct S_ComplexNumber ReadComplexNumber();
struct S_ComplexNumber AddTwoComplexNumbers(struct S_ComplexNumber FirstNumber, struct S_ComplexNumber SecoundNumber);
void PrintComplexNumber(struct S_ComplexNumber Result);


int main()
{
	struct S_ComplexNumber FirstComlpexNumber, SecoundComplexNumber, Result;

	printf("For 1st complex number");
	FirstComlpexNumber = ReadComplexNumber();

	printf("For 2st complex number");
	SecoundComplexNumber = ReadComplexNumber();

	Result = AddTwoComplexNumbers(FirstComlpexNumber, SecoundComplexNumber);

	PrintComplexNumber(Result);

	return 0;
}

struct S_ComplexNumber ReadComplexNumber()
{
	struct S_ComplexNumber Complex;

	printf("\nEnter real and imaginary respectively:");
	fflush(stdin); fflush(stdout);
	scanf("%f %f", &Complex.m_R, &Complex.m_I);

	return Complex;
}

struct S_ComplexNumber AddTwoComplexNumbers(struct S_ComplexNumber FirstNumber, struct S_ComplexNumber SecoundNumber)
{
	struct S_ComplexNumber Result;

	Result.m_R = FirstNumber.m_R + SecoundNumber.m_R;
	Result.m_I = FirstNumber.m_I + SecoundNumber.m_I;

	return Result;
}

void PrintComplexNumber(struct S_ComplexNumber Result)
{
	printf("Sum = %0.1f +%0.1fi ", Result.m_R, Result.m_I);
}
