/*
 * C_Function_To_Return_Unique_Number_in_array_With_One_Loop.c
 *
 * Created on : Nov 17, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */

#include <stdio.h>

int main()
{
    int arr[10], freq[10];
    int size, i, j, count;

    printf("Enter size of array: ");
    fflush(stdout); fflush(stdin);
    scanf("%d", &size);

    printf("Enter elements in array: ");
    fflush(stdout); fflush(stdin);
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }

    for(i=0; i<size; i++)
    {
        count = 1;
        for(j=i+1; j<size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                freq[j] = 0;
            }
        }

        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }

    printf("\nUnique elements in the array are: ");
    for(i=0; i<size; i++)
    {
        if(freq[i] == 1)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
