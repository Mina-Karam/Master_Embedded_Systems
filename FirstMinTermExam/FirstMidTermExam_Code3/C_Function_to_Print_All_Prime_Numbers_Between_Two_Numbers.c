/*
 * C_Function_to_Print_All_Prime_Numbers_Between_Two_Numbers.c
 *
 * Created on : Nov 17, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */

#include <stdio.h>

int main ()
{
   int num1, num2, i, j, flag;

   printf("Enter two numbers: ");
   fflush(stdout); fflush(stdin);
   scanf("%d %d", &num1, &num2);

   printf("Prime numbers between %d and %d are:\n", num1, num2);

   for (i = num1 + 1; i < num2; ++i)
   {
      flag = 0;
      for (j = 2; j <= i/2; ++j)
      {
         if (i % j == 0)
         {
            flag = 1;
            break;
         }
      }
      if (flag == 0)
          printf("%d ", i);
   }
   return 0;
}
