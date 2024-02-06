//crlleva_exer9.c
//Cazhia Reese Lleva CMSC 21 UV-4L

//A C Program
#include<stdio.h>
#include <string.h>

struct name {
	char firstName[50];
	char lastName[30];
};


typedef struct student_record {
	struct name studentName;
	
	char student_number[20];

	int absences;
	
} Student;


void addStudent(Student *classroom, int i) {
	printf("Enter Student Name (First name Last Name): ");
	scanf("%s %s", classroom[i].studentName.firstName, classroom[i].studentName.lastName);

	printf("Enter Student Number: ");
	scanf("%s", classroom[i].student_number);

	printf("Enter Absences: ");
	scanf("%d", &classroom[i].absences);

	
}


void printAll(Student *classroom, int index) {
	for(int i=0; i < index; i++) {
		printf("Name: %s %s\n", classroom[i].studentName.firstName, classroom[i].studentName.lastName);
		printf("Student Number: %s \n", classroom[i].student_number);
		printf("Absences: %d\n", classroom[i].absences);
		printf("\n");		
	}
}


void addAbsence(Student *classroom, int index) {
	int compare_flag, i;
	char student_number[20];
	printf("Enter Student Number: ");
	scanf("%s", student_number);

	for (i = 0; i<index; i ++){
		compare_flag = strcmp(classroom[i].student_number, student_number);
		if (compare_flag == 0)
		{
			classroom[i].absences += 1;
			printf("Absence Recorded\n");			
			break;
		}
	}

	if(compare_flag!=0)
	{
		printf("Student does not exist in records.\n");
	}
}

void deleteStudent(Student *classroom, int *index){
	int compare_flag, i, found = 0, j;
	char student_number[20];
	printf("Enter Student Number: ");
	scanf("%s", student_number);
	for (i = 0; i< *index; i++){
		compare_flag = strcmp(classroom[i].student_number, student_number);
		if (compare_flag == 0)
		{
			for (j = 0; j< *index; j++)
			{
				classroom[i+j] = classroom[i+j+1];
			}			
			found = 1;
			*index = *index -=1;
			return;
		}		
	}

	if (found == 0)
	{
		printf("Student does not exist in records.\n");
	}
}

int main() {
	struct student_record classroom[10]; //Array of Structures
	int choice;
	int index = 0;
	

	while(1) {
		printf("[1] Add Student Record\n");
		printf("[2] Print All Student Record\n");
		printf("[3] Add Absence\n");
		printf("[4] Delete Student\n");
		printf("[0] Exit\n");

		printf("Enter choice: ");
		scanf("%d", &choice);

		printf("\n");

		if (choice == 1) {
			addStudent(classroom, index);
			index++;
			printf("Student record successfully added!\n");
		} else if (choice == 2) {
			printAll(classroom, index);
			
		} else if (choice == 3) {
			addAbsence(classroom, index);
		} else if (choice == 0) {
			break;
		} else if (choice == 4){
			deleteStudent(classroom, &index);
		}

		printf("\n");
	}
}