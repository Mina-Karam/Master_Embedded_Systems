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

// Fill the student data
void fill_the_record(struct SStudentNode *NewStudent);

// Add a student to the list
void list_add_student(void);


int list_delete_student(void);

void list_view_students(void);

void list_delete_all(void);



#endif /* STUDENT_DB_H_ */
