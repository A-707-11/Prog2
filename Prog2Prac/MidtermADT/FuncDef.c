#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void displayArray(DynamicArray arr)
{
	int i;
	
	for(i = 0; i < arr.size; i++)
	{
		printf("%d ", arr.elements[i].data);
	}
	printf("\n");
}

void initDynamicArray(DynamicArray *arr)
{
	arr->elements = (Element*)malloc(INITIAL_SIZE * sizeof(Element));
	arr->size = 0;
	arr->capacity = INITIAL_SIZE;
}

void insertAtEnd(DynamicArray *arr, int elem)
{
	if(arr->size != arr->capacity )
	{
		arr->elements[arr->size].data = elem;
		arr->size++;
	}
	else
	printf("Array is already full");
}

void insertAtStart(DynamicArray *arr, int elem)
{
	int i;
	
	if(arr->size != arr->capacity )
	{
		for(i = arr->size; i > 0; i--)
		{
			arr->elements[i] = arr->elements[i - 1];
		}
		arr->elements[0].data = elem;
		arr->size++;
	}
	else
	printf("Array is already full");
}

void deleteAtIndex(DynamicArray *arr, int index)
{
	int i;
	
	if(arr->size == 0)
	{
		printf("Array is empty. There is nothing to delete");
	}
	else
	for(i = index; i < arr->size; i++)
	{
		arr->elements[i] = arr->elements[i + 1]; 
	}
	arr->size--;
}

void updateAtIndex(DynamicArray *arr, int index, int elem)
{
	arr->elements[index].data = elem;
}

void copyToArray(DynamicArray *source, DynamicArray *destination)
{
	int i;

    destination->elements = (Element*)realloc(destination->elements, destination->capacity * sizeof(int));
	
	for(i = 0; i < source->size; i++)
	{
		destination->elements[i] = source->elements[i];
	}
	destination->size = source->size;
	
}

void expandArray(DynamicArray *arr)
{
	arr->capacity += 10;
	arr->elements = realloc(arr->elements,arr->capacity * sizeof(Element));
}
