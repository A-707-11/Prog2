#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef char String[20];

typedef struct {
	String fname;
	int age;
	String brngy;
	int numID;
	char gender;
}StudInfo;

int main()
{
	StudInfo s;
	StudInfo a[MAX];
	int i, count = 0;
	
	FILE *filePtr = fopen("test_4.txt","rb");
	
	if(filePtr == NULL)
	{
		printf("FAILED TO READ FILE...\n");
	}
	
	while(fread(&s,sizeof(StudInfo),1,filePtr) == 1)
	{
		a[count++] = s;
	}
	
	for(i = 0; i < MAX; i++)
	{
		printf("%10s | %d | %10s | %d | %c\n", a[i].fname, a[i].age, a[i].brngy, a[i].numID, a[i].gender);
	}
	
	fclose(filePtr);
	return 0;
}
