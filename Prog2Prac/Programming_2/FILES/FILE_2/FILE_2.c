#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int age;
	char name[20];
	int id;
	char sex;
}STUDENT;

typedef struct node{
	STUDENT data;
	struct node* next;
}NODE;

void getData(STUDENT *p);
void insertFront(NODE **head,STUDENT p);
void display(NODE *head);

int main()
{
	NODE *head = NULL;
	STUDENT p1;
	
	getData(&p1);
	insertFront(&head,p1);
	display(head);
	
	FILE *fileptr = fopen("sample.txt","wb");

	fwrite(stud,sizeof(STUDENT),5,fileptr);
	
	fclose(fileptr);
	return 0;
}

void getData(STUDENT *p)
{
	printf("Enter age: ");
	scanf("%d", &p->age);
	fflush(stdin);
	printf("Enter name: ");
	gets(p->name);
	printf("Enter ID: ");
	scanf("%d", &p->id);
	fflush(stdin);
	printf("Enter sex: ");
	scanf("%c", &p->sex);
}

void insertFront(NODE **head,STUDENT p)
{
	NODE *temp = malloc(sizeof(NODE));
	
	if(temp != NULL)
	{
		temp->data = p;
		temp->next = *head;
		*head = temp;
	}

}

void display(NODE *head)
{
	while(head != NULL)
	{
		printf("\nAGE: %d\n", head->data.age);
		printf("NAME: %s\n", head->data.name);
		printf("ID: %d\n", head->data.id);
		printf("SEX: %c\n\n", head->data.sex);
		
		head = head->next;
	}
}
