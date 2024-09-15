#include <stdio.h>
#include <stdlib.h>

void Print();
void DisplayArr();

int main ()
{
	int *ptr;
	int A;
	char B[50];
	int i;
	int size;
	
	
	printf("Enter the value of A: ");
	scanf("%d", &A);
	
	ptr=&A;
	
	printf("A is = %d\n", *ptr);
	printf("The Address of A: %d\n\n", ptr);
	
	Print(&A);
	
	printf("Enter size: ");
	scanf("%d", &size);
	
	printf("Enter an Array: ");
	for(i=0;i<size;i++){
		fflush(stdin);
		scanf("%c", &B[i]);
	}
	
	
	DisplayArr(B,size);
	
	return 0;
	
}

void Print(int *B)
{
	printf("A is = %d\n", *B);
	printf("The Address of A: %d\n\n", B);
}

void DisplayArr(char *arr, int size)
{
	int i;
	
	
	for(i=0;i<size;i++)
	{
		printf("%c", arr[i]);
	}
	
}

