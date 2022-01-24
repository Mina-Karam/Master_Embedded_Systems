/*
 * Student_Sys.h
 *
 * Created on : Jan 22, 2022
 *     Author : Mina Karam     
 */

#ifndef STUDENT_SYS_H_
#define STUDENT_SYS_H_

#include "stdio.h"
#include "string.h"

#define NAME_LENGTH 20
#define COURSES_NUMBER 5

// Student Structures
struct student_info {
	char first_name[NAME_LENGTH];
	char last_name[NAME_LENGTH];
	int roll_number;
	float GPA;
	int course_id[COURSES_NUMBER];
};

// Data type of buffer item
typedef struct student_info Item;

// Type Definition
typedef struct {
	Item *base;
	Item *head;
	Item *tail;
	int length;
	int counter;
}FIFO_Buf_st;

typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NOT_FULL,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_NULL
}FIFO_Status_st;


// Student Queue Initialization
FIFO_Status_st students_sys_init(FIFO_Buf_st *students_queue, Item *item, int length);

// Enter student data form file
void add_student_from_file(FIFO_Buf_st *students_queue);

// Enter student data manually from console
void add_student_manualy(FIFO_Buf_st *students_queue);

// Get student date by its roll number
void find_student_by_roll(FIFO_Buf_st *students_queue);

// Get student date by its first name
void find_student_by_firstname(FIFO_Buf_st *students_queue);

// Print all students in the queue
void show_students_info(FIFO_Buf_st *students_queue);

// Enqueue item in the FIFO given a data item
FIFO_Status_st FIFO_enqueue(FIFO_Buf_st *fifo_buf, Item item);

// Is the FIFO full ?!
FIFO_Status_st FIFO_is_full(FIFO_Buf_st *fifo_buf);

// Is the FIFO empty ?!
FIFO_Status_st FIFO_is_empty(FIFO_Buf_st *fifo_buf);

#endif /* STUDENT_SYS_H_ */
