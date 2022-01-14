/*
 * main.c
 *
 * Created on : Jan 13, 2022
 *     Author : Mina Karam     
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"

#include "Student_DB.h"

#define DPRINTF(...) 		{fflush(stdout);fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);fflush(stdin);}


int main(void)
{
	char temp_text[NAME_LENGTH];

	while(1)
	{
		DPRINTF(" ============================= ");
		DPRINTF("\n Choose on of the following options \n");
		DPRINTF("\n\t 1: Add Student");
		DPRINTF("\n\t 2: Delete Student");
		DPRINTF("\n\t 3: View Students");
		DPRINTF("\n\t 4: Delete All");
		DPRINTF("\n\n Enter option number: ");

		gets(temp_text);
		DPRINTF("\n ============================= \n");
		switch(atoi(temp_text))
		{
			case 1:
				list_add_student();
				break;

			case 2:
				list_delete_student();
				break;

			case 3:
				list_view_students();
				break;

			case 4:
				list_delete_all();
				break;

			default:
				DPRINTF("\n Wrong Option ");
				break;
		}
	}
	return 0;
}
