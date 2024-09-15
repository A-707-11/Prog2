#include <stdio.h>

int add(int a, int b);
int multiply(int a,int b);


int main ()
{
	int n;
	
	printf("[1] Add\t\t");
	printf("[2] Multiply\n\n");
	
	printf("Choose Operation: ");
	scanf("%d", &n);
	
	while(n != 0)
	{
		if(n < 1 || n > 2)
		{
			printf("\nInvalid Number\n");
			printf("Choose Again!: ");
			scanf("%d", &n);
		}
		else if(n == 1)
		{
			printf("\nSum: %d\n", add(5, 5));
			printf("\nChoose Operation: ");
			scanf("%d", &n);
		}
		else if (n == 2)
		{
			printf("\nProduct: %d\n", multiply(5, 5));
			printf("\nChoose Operation: ");
			scanf("%d", &n);
		}
		
	}
	return 0;
		
			
}

int add(int a, int b)
{
	return a+b;
}

int multiply(int a, int b)
{
	return a*b;
}
