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
//	Student list[5];
//	
//	list[0] = newStudent(1001, "Cecile", 18, 'M'); 
//	list[1] = newStudent(1005, "Paul", 20, 'M');
//	list[2] = newStudent(1006, "Marie", 18, 'F');
//	list[3] = newStudent(1010, "Ela", 23, 'F');
//	list[4] = newStudent(1021, "Alice", 17, 'M');
	
	insertStudent(&head, newStudent(1001, "Cecile", 18, 'M'));
	
	fp = fopen("sample.txt","wb");
	
	fwrite(&head,sizeof(Student),5,fp);
	
	
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
	printf("%5d | %20s | %5d | %c\n ", s.studID, s.studName, s.age, s.sex);
}

