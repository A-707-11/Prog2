#include <stdio.h>
#include "SortLib.h"

void display(int arr[], int len)
{
	int i;
	
	for(i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int arr[], int len)
{
	int i, j, temp;
	
	for(i = 0; i < len - 1; i++)
	{
		for(j = i + 1; j < len; j++)
		{
			if(arr[j] < arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}	
	}
}

void selectionSort(int arr[], int len)
{
	int i, j, temp, smallest;
	
	for(i = 0; i < len; i++)
	{
		smallest = i;
		for(j = i + 1; j < len; j++)
		{
			if(arr[j] < arr[smallest])
			{
				smallest = j;
			}
		}
		temp = arr[smallest];
		arr[smallest] = arr[i];
		arr[i] = temp;
	}
	
}

void insertionSort(int arr[], int len)
{
    int i, j, key;
    
    for(i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key) // Changed the comparison
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

