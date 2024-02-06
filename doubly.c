#include<stdio.h>
#include<stdlib.h>



typedef struct NODE_tag
{
	struct NODE_tag *prev;
	int num;
	struct NODE_tag *next;
}NODE;


void insertNode(NODE **head)
{
	NODE *new= NULL;
	new = (NODE *)malloc(sizeof(NODE));

	printf("enter data: ");
	scanf("%d", &new->num);

	new->next = NULL;
	new->prev = NULL;

	if((*head)==NULL)
	{
		(*head) = new;
	}else if((*head)->num>new->num)
	{
		new->next=(*head);
		(*head)->prev = new;
		(*head)=new;
	}else{
		NODE *temp = (*head);

		while(temp->next != NULL && temp->next->num < new->num)
		{
			temp = temp->next;
		}

		if(temp->next != NULL)
		{
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
		}else{
			new->next = temp->next;
			new->prev = temp;
			temp->next = new;
		}
	}
}

void printList(NODE *temp){
	NODE *tail = NULL;

	while(temp != NULL)
	{
		if(temp->next == NULL){
			tail=temp;
		}

		printf("%d", temp->num);
		temp=temp->next;
	}

	printf("\nBackwards\n");

	while(tail != NULL){
		printf("%d", tail->num);
		tail = tail->prev;
	}

	printf("\n");
}

void deleteNode(NODE **head)
{
	int num;
	NODE *temp = (*head);
	printf("Delete: ");
	scanf("%d", &num);

	if((*head)==NULL)
	{
		printf("Nothing here\n");
	}else{
		if(num == (*head)->num)
		{
			(*head)=(*head)->next;
			(*head)->prev=NULL;
			free(temp);
		}else{
			while(temp->next != NULL && temp->num != num)
			{
				temp = temp->next;
			}

			if(temp->next == NULL && temp->num == num)
			{
				temp->prev->next=NULL;
				free(temp);
			}else if(temp->num == num)
			{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
			}else{
				printf("Not here");
			}
		}
	}

}

void deleteAll(NODE **head){
	while((*head)!= NULL){
		NODE *temp = (*head);
		(*head)=(*head)->next;
		free(temp);
	}
}

int main(){
	NODE *head=NULL;
	int choice;
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

			
				// printf("Sorry. The system can't handle more students.\n");
			
			insertNode(&head);
				
			
		} else if (choice == 2) {
			printList(head);
			
		} else if (choice == 0) {
			deleteAll(&head);
			break;
		} else if (choice == 4){
			deleteNode(&head);
		}

		printf("\n");
	}
}
