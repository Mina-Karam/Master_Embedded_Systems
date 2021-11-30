/*
 ============================================================================
 Name        : C_Program_to_Store_Information_of_a_Student_Using_Structure.c
 Author      : Mina Karam
 Description : C Program to Store Information of a Student Using Structure
 ============================================================================
 */

#include <stdio.h>

struct S_StudentInformation
{
	char m_name[50];
	int m_RollNumber;
	float m_marks;
};

struct S_StudentInformation ReadStudentInformation();
void printStudentInfo (struct S_StudentInformation StudentInfo);

int main()
{
	struct S_StudentInformation StudentInfo;
	StudentInfo = ReadStudentInformation() ;
	printStudentInfo(StudentInfo);

	return 0;
}

struct S_StudentInformation ReadStudentInformation()
{
	struct S_StudentInformation StudentInfo;

	printf ("Enter the student information: \n");
	printf ("Enter the student name: ");
	fflush (stdin); fflush(stdout);
	scanf ("%s", StudentInfo.m_name );

	printf ("\nEnter the student's roll number: ");
	fflush (stdin); fflush(stdout);
	scanf ("%d", &StudentInfo.m_RollNumber );

	printf ("\nEnter the students marks: ");
	fflush (stdin); fflush(stdout);
	scanf ("%f", &StudentInfo.m_marks);

	return StudentInfo ;
}

void printStudentInfo (struct S_StudentInformation StudentInfo)
{
	// print the
	printf ("\nDisplaying the student's Information: \n");

	printf ("Student name: %s", StudentInfo.m_name);

	printf ("\nStudent's roll number: %d", StudentInfo.m_RollNumber);

	printf ("\nStudent's marks: %.2f", StudentInfo.m_marks);

}
