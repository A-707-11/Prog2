#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char fname[20];
	char lname[20];
	char mi;
}NAME;

typedef struct node{
	NAME data;
	struct node* next;
}NODE;

void insertSort(NODE **head, NAME p);
void display(NODE *head);

int main()
{
	NODE *head = NULL;
	NAME person1 = {"ARJOY","ESTIOLA",'M'};
	NAME person2 = {"JOHN","DOE",'Q'};
	NAME person3 = {"BARRY","ALLEN",'A'};
	NAME person4 = {"SIMON","MASON",'P'};
	
	insertSort(&head,person1);
	insertSort(&head,person2);
	insertSort(&head,person3);
	insertSort(&head,person4);
	
	display(head);
}

void insertSort(NODE **head, NAME person)
{
	NODE *newNode = malloc(sizeof(NODE));
	NODE *current = *head;
	
	if(newNode != NULL)
	{
		newNode->data = person;
			
		if(current == NULL || strcmp(current->data.lname,newNode->data.lname) > 0)
		{
			newNode->next = *head;
			*head = newNode;
		}
		else
		{
			while(current->next != NULL && strcmp(current->next->data.lname,newNode->data.lname) < 0)
			{
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
		}
	}
}

void display(NODE *head)
{
	while(head != NULL)
	{
		printf("%s, %s %c\n", head->data.lname, head->data.fname, head->data.mi);
		head = head->next;
	}
}

