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
	int select_option;
	FIFO_Buf_st students_queue;
	struct student_info students_buffer[STUDENTS_NUMBER];

	// Solving I/O form console Problem
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	students_sys_init(&students_queue, students_buffer, STUDENTS_NUMBER);
	printf("Welcome to the Student Management System\n");
	printf("\nDo you want to recover last database ?!\n");
	printf("\t1: Yes\n\t2: No\n");
	printf("Enter your option: ");
	scanf("%d",&select_option);

	switch (select_option)
	{
		case 1:	add_student_from_update_file(&students_queue);break;
		case 2: break;
		default:break;
	}



	while(1)
	{
		printf(" =============================\n");
		printf("\n Choose on of the following options \n");
		printf("\n\t 1: Add Student Manually");
		printf("\n\t 2: Add Student From Text File");
		printf("\n\t 3: Find Student by Roll Number");
		printf("\n\t 4: Find Student by First Name");
		printf("\n\t 5: Find Student by Course ID");
		printf("\n\t 6: Print Students Number");
		printf("\n\t 7: Delete Student by Roll Number");
		printf("\n\t 8: Update Student by Roll Number");
		printf("\n\t 9: View Students");
		printf("\n\t 10: Exit");
		printf("\n\n Enter option number: ");

		scanf("%d",&select_option);
		printf(" ============================= \n");
		switch(select_option)
		{
			case 1: add_student_manualy(&students_queue);break;
			case 2: add_student_from_file(&students_queue);break;
			case 3: find_student_by_roll(&students_queue);break;
			case 4: find_student_by_firstname(&students_queue);break;
			case 5: find_student_by_course(&students_queue);break;
			case 6: print_students_count(&students_queue);break;
			case 7: delete_student_by_roll(&students_queue);break;
			case 8: update_student_by_roll(&students_queue);break;
			case 9: show_students_info(&students_queue);break;
			case 10: update_student_file(&students_queue); return 0;
			default: printf("\n Wrong Option: Try Again \n\n");break;
		}
	}
	return 0;
}
