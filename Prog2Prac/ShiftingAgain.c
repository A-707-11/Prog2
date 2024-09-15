#include <stdio.h>

void initialize();
void display(int arr[], int len);
void shiftRight(int arr[], int len);
void shiftLeft(int arr[], int len);

int main(){
	
	
	int arr[10] = {2,4,3,7,34,6,22};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	display(arr,len);
	shiftRight(arr,len);
	display(arr,len);
	shiftLeft(arr,len);
	display(arr,len);
	shiftLeft(arr,len);
	display(arr,len);
	shiftRight(arr,len);
	display(arr,len);
	shiftRight(arr,len);
	display(arr,len);
	shiftRight(arr,len);
	display(arr,len);
	
}

void display(int arr[], int len)
{
	int i;
	
	for(i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
}

void shiftRight(int arr[],int len)
{
	int i;
	
	for(i = len - 1; i >= 0; i--)
	{
		arr[i] = arr[i - 1]; 	
	}
}

void shiftLeft(int arr[], int len)
{
	int i;
	
	for(i = 0; i < len - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
}
