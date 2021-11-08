/*
 ======================================================================================================================
 Name        : EX8_C_Program_to_Make_a_Simple_Calculator_Using_Switch_Case.c
 Author      : Mina Karam
 Created on	 : Aug 2, 2021
 Description : Unit 2 C-Progtamming >> Assignment 2 C-Basic >> EX8 C Program to make a simple calculator using switch...case
 	 	 	   using Ansi-style (c99)
 ======================================================================================================================
 */

#include <stdio.h>

int main() 
{
  char op;
  float first, second;

  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &op);

  printf("Enter two operands: ");
  scanf("%f %f", &first, &second);

  switch (op) 
  {
    case '+':
      printf("%.1f + %.1f = %.1f", first, second, first + second);
      break;
    case '-':
      printf("%.1f - %.1f = %.1f", first, second, first - second);
      break;
    case '*':
      printf("%.1f * %.1f = %.1f", first, second, first * second);
      break;
    case '/':
      printf("%.1f / %.1f = %.1f", first, second, first / second);
      break;

    default:
      printf("Error! operator is not correct");
  }
  return 0;
}