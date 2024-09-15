#include <stdio.h>

typedef struct
{
	int* data; // pointer to dynamic array 
	int size; //amount of current data
	int capacity; // maximum of elements the list can hold
} ArrayList;

ArrayList* createArrayList(int capacity)
{
	ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
	list->size = 0;
	list->capacity = capacity;
	list->data = (int*)malloc(capacity*sizeof(int));
	
	return list;
}

void addElement(ArralyList* list, int element)
{
	
}

int main()
{
	
}

