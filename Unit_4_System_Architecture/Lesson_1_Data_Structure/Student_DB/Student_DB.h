/*
 * Student_DB.h
 *
 * Created on : Jan 13, 2022
 *     Author : Mina Karam
 */

#ifndef STUDENT_DB_H_
#define STUDENT_DB_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"

#define NAME_LENGTH 30

#define DPRINTF(...) 		{fflush(stdout);fflush(stdin);\
							printf(__VA_ARGS__);\
							fflush(stdout);fflush(stdin);}

/*=========== TypeDefs ============*/
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

/*=========== APIs ============*/

// Fill the student data
void fill_the_record(struct SStudentNode *NewStudent);

// Add a student to the list
void list_add_student(void);

// Delete a student from the list
int list_delete_student(void);

// Print all students in the list
void list_view_students(void);

// Delete all students in the list
void list_delete_all(void);

// Get a Student node form the list
void list_get_node(int index);

// Get the list length using iteration (looping)
int list_students_count_iterative(void);

// Get the list length using recursion
int list_students_count_recursive(struct SStudentNode *list);

// Get a Student node form the end of list
void list_get_node_from_end(int index);

// Get the middle student even the number (odd or even)
void list_get_middle_student(void);

// Reverse the arrangement of the list
void list_reverse_students(void);

#endif /* STUDENT_DB_H_ */
