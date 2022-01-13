/*
 * C_Function_to_Reverse_Words_in_String.c
 *
 * Created on : Nov 17, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], reverse[100];
    int len, i, index, wordStart, wordEnd;

    printf("Enter any string: ");
    fflush(stdout); fflush(stdin);
    gets(str);

    len = strlen(str);
    index = 0;

    wordStart = len - 1;
    wordEnd = len - 1;

    while(wordStart > 0)
    {
        if(str[wordStart] == ' ')
        {
            i = wordStart + 1;
            while(i <= wordEnd)
            {
                reverse[index] = str[i];

                i++;
                index++;
            }
            reverse[index++] = ' ';

            wordEnd = wordStart - 1;
        }

        wordStart--;
    }

    for(i=0; i<=wordEnd; i++)
    {
        reverse[index] = str[i];
        index++;
    }

    reverse[index] = '\0';

    printf("Original string \n%s\n\n", str);
    printf("Reverse ordered words \n%s", reverse);

    return 0;
}
