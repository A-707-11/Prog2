#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int studID;
	char studName[30];
	int age;
	char sex;
}Student;

Student newStudent(int id, char name[], int age, char sex);
void display(Student s);

int main()
{
	FILE *fp;
	Student s;
	Student list[5];
	int count = 0;
	int i;
	
	
	fp = fopen("sample.txt","rb");
	
	while(fread(&s,sizeof(Student),1,fp) == 1)
	{
		list[count++] = s;
	}
	
	for(i = 0; i < count; ++i)
	{
		display(list[i]);
	}
	
	fclose(fp);
	
	return 0;
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










