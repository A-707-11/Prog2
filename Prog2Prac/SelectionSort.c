#include <stdio.h>

void select_sort(int arr[], int size);
void swap(int *a, int *b);

int main ()
{ 
	int sample[10] = {6,4,43,5,64,7,34};
	int i;
	
	for(i=0;i<=6;i++)
	{
		printf("%d,", sample[i]);
	}
	
	
	select_sort(&sample[0],6);
	
}

void select_sort(int arr[], int size)
{
	int smallest = 0;
	int i;
	
	for(i=0;i<=size;i++)
	{
		if(arr[smallest + i]<arr[smallest+i+1])
		{
			smallest = arr[smallest+i];
			swap(&arr[smallest+i+1],&smallest);
				printf("%d,", arr[i]);
		}
	
	}
	
	
}

void swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
