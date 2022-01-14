/*
 * Student_DB.c
 *
 * Created on : Jan 13, 2022
 *     Author : Mina Karam
 */

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"

#include "Student_DB.h"

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

		// Check for invalid allocation
		if(pNewStudent == NULL)
		{
			printf("Error: Can't create new student\n");
			return;
		}

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

// Delete a student from the list
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
	DPRINTF("\n\tThe ID selected not find. \n");
	return 0; // can't Find it
}

// Print all students in the list
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

// Delete all students in the list
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

// Get a Student node form the list
void list_get_node(int index)
{
	// Check if the list is empty
	if(gpFirstStudent == NULL || index < 0)
	{
		DPRINTF("\nThe List is Empty.\n");
	}

	struct SStudentNode *pTemp = gpFirstStudent;
	unsigned int counter = 0;

	// Check if the first recored is null
	while(pTemp)
	{
		if(counter == index)
		{
			DPRINTF("\n Record Index %d",index);
			DPRINTF("\n\t ID : %d",pTemp->Student.ID);
			DPRINTF("\n\t Name : %s",pTemp->Student.Name);
			DPRINTF("\n\t Height : %0.2f\n",pTemp->Student.height);
		}
		pTemp = pTemp->pNext;
		counter++;
	}
}

// Get the list length using iteration (looping)
int list_students_count_iterative(void)
{
	// Check if the list is empty
	if(gpFirstStudent == NULL )
	{
		DPRINTF("\nThe List is Empty.\n");
		return 0;
	}

	struct SStudentNode *pTemp = gpFirstStudent;
	unsigned int counter = 0;

	// Looping in list
	while(pTemp)
	{
		if(pTemp->pNext == NULL)
		{
			break;
		}
		pTemp = pTemp->pNext;
		counter++;
	}
	return counter;
}
