/*
 * main.c
 *
 * Created on : Jan 21, 2022
 *     Author : Mina Karam     
 */

#include "Student_Sys.h"

#define STUDENTS_NUMBER 50


int main(void)
{
	uint32_t select_option;
	FIFO_Buf_st students_queue;
	struct student_info students_buffer[STUDENTS_NUMBER];

	// Solving I/O form console Problem
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	students_sys_init(&students_queue, students_buffer, STUDENTS_NUMBER);
	printf("Welcome to the Student Management System\n");

	while(1)
	{
		printf(" =============================\n");
		printf("\n Choose on of the following options \n");
		printf("\n\t 1: Add Student Manually");
		printf("\n\t 2: Add Student From Text File");
		printf("\n\t 3: Find Student by Roll Number");
		printf("\n\t 4: View Students");
		printf("\n\t 5: Exit");
		printf("\n\n Enter option number: ");

		scanf("%d",&select_option);
		printf(" ============================= ");
		switch(select_option)
		{
			case 1: add_student_manualy(&students_queue);break;
			case 2: add_student_from_file(&students_queue);break;
			case 3: find_student_by_roll(&students_queue);break;
			case 4: show_students_info(&students_queue);break;
			case 5: return 0;
			default: printf("\n Wrong Option: Try Again \n\n");break;
		}
	}
	return 0;
}
