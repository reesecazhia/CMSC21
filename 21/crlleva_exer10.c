//crlleva_exer10.c
//Cazhia Reese Lleva CMSC 21 UV-4L
//Nov 16, 2023

//A C Program that implements a structure array. It runs as a student information system that records the name, student number, and absences of a student.

//A user can update the current absences of an existing student in the record and also delete an existing student.

//Data is automatically loaded depending on the previous runs of the program. When the user chooses to exit the program, the current state of the structure is automatically saved.
#include<stdio.h>
#include <string.h>

struct name {
	char firstName[50];
	char lastName[30];
}; //end of name structure


typedef struct student_record {
	struct name studentName;
	
	char student_number[20];

	int absences;
	
} Student; //end of student_record structure

//Adds a student into the array and their corresponding information.
void addStudent(Student *classroom, int i) {
	printf("Enter Student Name (First name Last Name): ");
	scanf("%s %s", classroom[i].studentName.firstName, classroom[i].studentName.lastName);

	printf("Enter Student Number: ");
	scanf("%s", classroom[i].student_number);

	printf("Enter Absences: ");
	scanf("%d", &classroom[i].absences);

	
} //end of addStudent()

//Prints the current array while the program is running
void printAll(Student *classroom, int index) {

	if(index == 0){
		printf("No data to display.\n");
	}else
	{
		for(int i=0; i < index; i++) 
		{
			printf("Name: %s %s\n", classroom[i].studentName.firstName, classroom[i].studentName.lastName);
			printf("Student Number: %s \n", classroom[i].student_number);
			printf("Absences: %d\n", classroom[i].absences);
			printf("\n");		
		}
	}
}//end of printAll()

//If a student exists in the current record, when the user inputs their student number, the number of absences for that student is incremented.
void addAbsence(Student *classroom, int index) 
{
	int compare_flag, i;
	char student_number[20];
	printf("Enter Student Number: ");
	scanf("%s", student_number);

	for (i = 0; i<index; i ++)
	{
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
} //end of addAbsence

//If a student exists on record, the user can choose to delete them. 
void deleteStudent(Student *classroom, int *index)
{
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
			printf("Student deleted.\n");
			return;
		}		
	}

	if (found == 0)
	{
		printf("Student does not exist in records.\n");
	}
}// end of deleteStudent()

//When the user chooses to exit, the current data in the system is saved in a textfile
void saveFile(Student *classroom, int size)
{

	FILE *fp = fopen("classroom.txt", "w");
	fprintf(fp, "%d\n", size); 
	
	if(size == 0){
		printf("No data to be saved.\n");
	}else
	{	
		for(int i=0; i < size; i++) {
			fprintf(fp, "%s %s\n", classroom[i].studentName.firstName, classroom[i].studentName.lastName);
			fprintf(fp, "%s \n", classroom[i].student_number);
			fprintf(fp, "%d\n", classroom[i].absences);		
		}
		printf("Successfully saved data!\n");

		fclose(fp);
	}
} //end of saveFile()

//If a file associated to the system exists, it automatically loads that file at the start of the program.
void loadFile(Student *classroom, int *size)
{
	FILE *fp = fopen("classroom.txt", "r");
	
	if (fp == NULL)
	{
		printf("File does not exist. \n");
		return;
	}else{
		fscanf(fp, "%d\n", size);

		if(*size == 0){
			printf("No data to load.\n");
		}else
		{
			for(int i=0; i < (*size); i++) 
			{
				fscanf(fp, "%s %s\n", classroom[i].studentName.firstName, classroom[i].studentName.lastName);
				fscanf(fp, "%s \n", classroom[i].student_number);
				fscanf(fp, "%d\n", &classroom[i].absences);		
			}

			printf("Successfully loaded data!\n");

		}
		
		fclose(fp);
	}

} //end of loadFile

int main() {
	Student classroom[10]; //Array of Structures
	int choice;
	int index = 0;
	
	//call loadFile function
	loadFile(classroom, &index);
	while(1) {

		//Main Menu
		printf("[1] Add Student Record\n");
		printf("[2] Print All Student Record\n");
		printf("[3] Add Absence\n");
		printf("[4] Delete Student\n");
		printf("[0] Exit\n");

		printf("Enter choice: ");
		scanf("%d", &choice);

		printf("\n");

		//Call function depending on user choice
		if (choice == 1) {

			if (index>=10)
			{
				printf("Sorry. The system can't handle more students.\n");
			}else
			{
			addStudent(classroom, index);
			index++;
			printf("Student record successfully added!\n");
			}
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

	saveFile(classroom, index);
}