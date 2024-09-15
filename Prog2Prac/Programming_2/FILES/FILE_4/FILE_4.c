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
	StudInfo a[MAX];
	int i;
	
	a[0] = (StudInfo) {"Garcia",23,"Canjulao",1001,'M'};
	a[1] = (StudInfo) {"Kia",20,"Carajay",1002,'F'};
	a[2] = (StudInfo) {"Eric",23,"Pajo",1003,'M'};
	a[3] = (StudInfo) {"John",32,"Basak",1004,'M'};
	a[4] = (StudInfo) {"Nina",41,"Pusok",1045,'F'};
	
	FILE *filePtr = fopen("test_4.txt","wb");
	
	if(filePtr == NULL)
	{
		printf("FAILED TO CREATE FILE...\n");
	}
	
	
	fwrite(&a,sizeof(StudInfo),5,filePtr);

	
	
	fclose(filePtr);
	return 0;
}

