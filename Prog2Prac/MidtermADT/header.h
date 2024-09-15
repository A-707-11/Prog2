#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#define INITIAL_SIZE 10

typedef struct {
	int data;
}Element;

typedef struct {
	Element* elements;
	int size;
	int capacity;
}DynamicArray;

void displayArray(DynamicArray arr);
void initDynamicArray(DynamicArray *arr);
void insertAtEnd(DynamicArray *arr, int elem);
void insertAtStart(DynamicArray *arr, int elem);
void deleteAtIndex(DynamicArray *arr, int index);
void updateAtIndex(DynamicArray *arr, int index, int elem);
void copyToArray(DynamicArray *source, DynamicArray *destination);
void expandArray(DynamicArray *arr);

#endif
