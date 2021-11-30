/*
 * EX4_C_Program_to_Store_Information_of_Students_Using_Structure.c
 *
 * Created on : Nov 30, 2021
 *     Author : Mina Karam
 *      
 * Description:
 */

#include <stdio.h>

struct S_StudentInformation
{
	char m_name [50] ;
	int m_rollNumber ;
	float m_marks ;
};

struct S_StudentInformation ReadStudentInformation ( );
void printStudentInfo (struct S_StudentInformation StudentInfo);

int main()
{
	struct S_StudentInformation StudentInfo ;
	struct S_StudentInformation StudentsData [10];
	int NumOfStudents = 10, i ;

	printf ("Enter the information of 10 Students:\n");

	for ( i=0; i<NumOfStudents; ++i)
	{
		printf ("\nEnter the information of student No.[%d]:\n", i+1);
		StudentInfo = ReadStudentInformation() ;
		StudentsData [i] = StudentInfo ;
	}

	printf ("\nDisplaying the information of the students:\n");

	for ( i=0; i<NumOfStudents; ++i)
	{
		printStudentInfo (StudentsData [i]);
	}

	return 0;
}

struct S_StudentInformation ReadStudentInformation( )
{
	struct S_StudentInformation StudentInfo;

	printf ("\nEnter the student name: ");
	fflush (stdin); fflush(stdout);
	scanf ("%s", StudentInfo.m_name );

	printf ("\nEnter the student's roll number: ");
	fflush (stdin); fflush(stdout);
	scanf ("%d", &StudentInfo.m_rollNumber );

	printf ("\nEnter the students marks: ");
	fflush (stdin); fflush(stdout);
	scanf ("%f", &StudentInfo.m_marks);

	return StudentInfo ;
}


void printStudentInfo (struct S_StudentInformation StudentInfo)
{
	printf ("\nStudent name: %s", StudentInfo.m_name );
	printf ("\nStudent's roll number: %d", StudentInfo.m_rollNumber);
	printf ("\nStudent's marks: %.2f", StudentInfo.m_marks);
}
