//FIND JOHN
#include <stdio.h>

int main()
{
	char name[3][6];
	char key[] = "john";
	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		printf("please enter name: ");
		scanf("%s", name[i]);
		fflush(stdin);
	}
	
	for (i = 0; i < 3; i++)
	{
		printf("Name %d: %s\n", i + 1, name[i]);
	}
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; name[i][j] != '\0' ; j++)
		{
			printf("%c", name[i][j]);
		}
		printf(" ");
	}
}
