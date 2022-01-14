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

#define NAME_LENGTH 30
#define DPRINTF(...) 		{fflush(stdout);fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);fflush(stdin);}

struct SStudentData
{
	int ID;
	char Name[NAME_LENGTH]; // +1
	float height;
};

struct SStudentNode
{
	struct SStudentData Student;
	struct SStudentNode *pNext;
};

struct SStudentNode *gpFirstStudent = NULL;

// Fill the student data
void fill_the_record(struct SStudentNode *NewStudent)
{
	char temp_text[NAME_LENGTH];

	DPRINTF("Enter Student ID: ");
	gets(temp_text);
	NewStudent->Student.ID = atoi(temp_text);

	DPRINTF("Enter Student Name: ");
	gets(NewStudent->Student.Name);

	DPRINTF("Enter Student Height: ");
	gets(temp_text);
	NewStudent->Student.height = atof(temp_text);
}

// Add a student to the list
void list_add_student(void)
{
	struct SStudentNode *pNewStudent ;
	struct SStudentNode *pLastStudent ;

	if (gpFirstStudent == NULL)// If the list is empty
	{
		// Create the first record
		pNewStudent = (struct SStudentNode*) malloc(sizeof(struct SStudentNode));

		// Assign the gpFirstStudent to it
		gpFirstStudent = pNewStudent;
	}
	else // If the list contain records
	{
		// Navigate until reach to the last record
		pLastStudent = gpFirstStudent;
		while(pLastStudent->pNext)
		{
			pLastStudent = pLastStudent->pNext;
		}

		// Create new record
		pNewStudent = (struct SStudentNode*) malloc(sizeof(struct SStudentNode));

		// Assign its next to it
		pLastStudent->pNext = pNewStudent;
	}

	// Fill the record
	fill_the_record(pNewStudent);

	// Assign its next to null
	pNewStudent->pNext = NULL;
}

int list_delete_student(void)
{
	char temp_text[NAME_LENGTH];
	unsigned int selected_id;

	// Get the selected ID from the user
	DPRINTF("\nEnter Student ID to be deleted: ");
	gets(temp_text);
	selected_id = atoi(temp_text);

	if(gpFirstStudent) // List have records
	{
		struct SStudentNode *pSelectedStudent = gpFirstStudent;
		struct SStudentNode *pPreviousStudent = NULL ;

		// Loop on all records starting from the gpFirstStudent
		while(pSelectedStudent)
		{
			// Compare the recorded ID with the selected ID
			if(pSelectedStudent->Student.ID == selected_id)
			{
				if(pPreviousStudent)
				{
					pPreviousStudent->pNext = pSelectedStudent->pNext;
				}
				else
				{
					gpFirstStudent = pSelectedStudent->pNext;
				}
				free(pSelectedStudent);
				DPRINTF("\nThe ID selected is deleted. \n");
				return 1; // find it
			}
			// Store the previous record pointer
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->pNext;

		}
	}
	DPRINTF("The ID selected not find. \n");
	return 0; // can't Find it
}


void list_view_students(void)
{
	struct SStudentNode *pCurrentStudent = gpFirstStudent;
	unsigned int counter = 0;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n List is empty. \n");
	}
	while(pCurrentStudent)
	{
		DPRINTF("\n Record Number %d",counter+1);
		DPRINTF("\n\t ID : %d",pCurrentStudent->Student.ID);
		DPRINTF("\n\t Name : %s",pCurrentStudent->Student.Name);
		DPRINTF("\n\t Height : %0.2f\n",pCurrentStudent->Student.height);
		pCurrentStudent = pCurrentStudent->pNext;
		counter++;
	}
}

void list_delete_all(void)
{
	struct SStudentNode *pCurrentStudent = gpFirstStudent;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n List is empty");
	}
	while(pCurrentStudent)
	{
		struct SStudentNode *pTempStudent = gpFirstStudent;
		pCurrentStudent = pCurrentStudent->pNext;
		free(pTempStudent);
	}
	gpFirstStudent = NULL;
}

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
