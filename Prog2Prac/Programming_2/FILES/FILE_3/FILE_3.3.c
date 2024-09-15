#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int studID;
	char studName[30];
	int age;
	char sex;
}Student;

typedef struct node{
	Student data;
	struct node* next;
}NODE;

Student newStudent(int id, char name[], int age, char sex);
void insertStudent(NODE **head, Student data);
void display(Student s);

int main()
{
	FILE *fp;
	NODE *head = NULL;
	NODE *current;
	Student data;
	
	
	fp = fopen("sample.txt","rb");
	if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

	

	while(fread(&data,sizeof(Student),1,fp) == 1)
	{
		insertStudent(&head,data);	
	}

	
	current = head;
	while(current != NULL)
	{
		display(current->data);
		current = current->next;
	}

	
	
	fclose(fp);
	
	return 0;
}

void insertStudent(NODE **head, Student data)
{
	NODE *temp = malloc(sizeof(NODE));
	
	if(temp != NULL)
	{
		temp->data = data;
		temp->next = *head;
		*head = temp;
	}
	
}

Student newStudent(int id, char name[], int age, char sex)
{
	Student s;
	
	s.studID = id;
	strcpy(s.studName, name);
	s.age = age;
	s.sex = sex;
	
	return s;
}

void display(Student s)
{
	printf("%5d | %20s | %5d | %c\n", s.studID, s.studName, s.age, s.sex);
}
