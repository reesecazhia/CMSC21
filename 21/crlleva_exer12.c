//crlleva_exer12.c
//Cazhia Reese Lleva CMSC 21 UV-4L
//Nov 30, 2023

//This is a different approach to the implementation of crlleva_exer10.c

//A C Program that implements a singly linked list. It runs as a student information system that records the name, student number, and absences of a student.

//A user can update the current absences of an existing student in the record and also delete an existing student.

//Data is automatically loaded depending on the previous runs of the program. When the user chooses to exit the program, the current state of the linked list is automatically saved in a txt file.
#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct name {
	char firstName[50];
	char lastName[30];
}; //end of name structure


typedef struct student_record {
	struct name studentName;	
	char student_number[20];
	int absences;
	struct student_record *next;
	
} Student; //end of student_record structure


char * toupperStr(char *s)
{
    
    int i, n = strlen(s);
    for (i=0; i<n; i++)
    {
        for (i = 0; i<n; i++)
            s[i] =toupper(s[i]);
        
    }
    return(s);
}
//Adds a student into the linked list and their corresponding information.
void addStudent(Student **hptr) {
	Student *new = NULL;
	new = (Student *)(malloc(sizeof(Student)));

	printf("Enter Student Name (First name Last Name): ");
	scanf("%s %s", new->studentName.firstName, new->studentName.lastName);
	toupperStr(new->studentName.firstName);
	toupperStr(new->studentName.lastName);

	printf("Enter Student Number: ");
	scanf("%s", new->student_number);

	printf("Enter Absences: ");
	scanf("%d", &new->absences);

	new->next=NULL;
	if ((*hptr)==NULL || ((*hptr)!= NULL && strcmp((*hptr)->studentName.lastName,new->studentName.lastName)>0))
	{
		new->next=(*hptr);
		(*hptr) = new;
	}else
	{
		Student *temp = *hptr;
		while(temp->next!=NULL && strcmp(temp->next->studentName.lastName,new->studentName.lastName)<=0)
		{
			temp = temp->next;
		}

		new->next = temp->next;
		temp->next = new;
	}

	printf("Student record successfully added!\n");
	
} //end of addStudent()

//Prints the current linked list while the program is running
void printAll(Student *temp) {

	if(temp == NULL){
		printf("Student Record Empty.\n");
	}else
	{
		while(temp != NULL)
		{
			printf("Name: %s %s\n", temp->studentName.firstName, temp->studentName.lastName);
			printf("Student Number: %s \n", temp->student_number);
			printf("Absences: %d\n", temp->absences);
			printf("\n");	
			temp = temp->next;	
		}
	}
}//end of printAll()

//If a student exists in the current record, when the user inputs their student number, the number of absences for that student is incremented.
void addAbsence(Student *hptr) 
{
	int compare_flag, i=0;
	char student_number[20];
	printf("Enter Student Number: ");
	scanf("%s", student_number);

	for (Student *temp = hptr; temp!=NULL; temp = temp->next)
	{
		compare_flag = strcmp(temp->student_number, student_number);
		if (compare_flag == 0)
		{
			temp->absences += 1;
			printf("Absence recorded.\n");	
			i=1;		
		}
	}

	if(i==0)
	{
		printf("Student does not exist in records.\n");
	}
} //end of addAbsence

//If a student exists on record, the user can choose to delete them. 
//Update index accept it as parameter
void deleteStudent(Student **hptr, int *index)
{
	char student_number[20];
	printf("Enter Student Number: ");
	scanf("%s", student_number);

	Student *temp = (*hptr), *ptr=NULL;


	if ((*hptr)==NULL)
	{
		printf("Record empty. Add a student first!");
	}else
	{		
		if ((strcmp((*hptr)->student_number, student_number))==0)
		{
			*hptr = temp->next;
			*index-=1;
			printf("Student record successfully deleted.\n");
			free(temp);
		}else
		{
			while(temp->next != NULL && (strcmp(temp->next->student_number, student_number))!=0)
			{
				temp = temp->next;
			}

			if (temp -> next != NULL)
			{
				ptr = temp->next;
				temp->next = ptr ->next;
				*index -= 1;
				printf("Student record successfully deleted.\n");
				free(ptr);
			}else{
				printf("Student not found.\n");
			}
		}
		
	}


}// end of deleteStudent()

//When the user chooses to exit, the current data in the system is saved in a textfile
void saveFile(Student *temp, int size)
{

	FILE *fp = fopen("classroom.txt", "w");
	fprintf(fp, "%d\n", size); 
			
	if(temp == NULL){
		printf("No data to be saved.\n");
	}else
	{
		while(temp != NULL)
		{
			fprintf(fp,"%s %s\n", temp->studentName.firstName, temp->studentName.lastName);
			fprintf(fp,"%s \n", temp->student_number);
			fprintf(fp,"%d\n", temp->absences);	
			temp = temp->next;	
		}
		printf("Successfully saved data!\n");
	}
	fclose(fp);
	
} //end of saveFile()

//If a file associated to the system exists, it automatically loads that file at the start of the program.
void loadFile(Student **hptr, int *size)
{
	FILE *fp = fopen("classroom.txt", "r");
	Student *new = NULL;
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
				new = (Student *)(malloc(sizeof(Student)));	
				fscanf(fp, "%s %s \n", new->studentName.firstName, new->studentName.lastName);		
				fscanf(fp, "%s \n", new->student_number);
				fscanf(fp, "%d \n", &new->absences);
				new->next=NULL;

				if ((*hptr)==NULL || ((*hptr)!= NULL && strcmp((*hptr)->studentName.lastName,new->studentName.lastName)>0))
				{
					new->next=(*hptr);
					(*hptr) = new;

				}else
				{
					Student *temp = *hptr;
					while(temp->next!=NULL && strcmp(temp->next->studentName.lastName,new->studentName.lastName)<=0)
					{
						temp = temp->next;
					}
					new->next = temp->next;
					temp->next = new;
				}	
			}
			printf("Successfully loaded data!\n");
		}		
		fclose(fp);
	}

} //end of loadFile

//Frees all the nodes of the linked list
void deleteAll(Student **hptr) {
	while((*hptr) != NULL) {
		Student *temp = (*hptr);
		(*hptr) = (*hptr)->next;
		free(temp);
	}
}



int main() {
	Student *head = NULL; 
	int choice;
	int index = 0;
	
	//call loadFile function
	loadFile(&head, &index);
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
			addStudent(&head);
			index++;			
			}
		} else if (choice == 2) {
			printAll(head);
			
		} else if (choice == 3) {
			addAbsence(head);
		} else if (choice == 0) {

			break;
		} else if (choice == 4){
			deleteStudent(&head, &index);
		}

		printf("\n");
	}

	saveFile(head, index);
	deleteAll(&head);
}