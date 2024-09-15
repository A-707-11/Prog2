#include <stdio.h>
#include <stdlib.h>
#include "header.h"



int main(int argc, char *argv[]) {
	
	DynamicArray arr;
	DynamicArray arr2;
	
	
	initDynamicArray(&arr);
	printf("Struct Element Size: %d", sizeof(Element));
	
	 displayArray(arr);
	 insertAtEnd(&arr,5);
	displayArray(arr);
	insertAtStart(&arr, 10);
	insertAtStart(&arr, 20);
	insertAtStart(&arr, 45);
	displayArray(arr);
	deleteAtIndex(&arr, 0);
	displayArray(arr);
	updateAtIndex(&arr,0,255);
	displayArray(arr);
	copyToArray(&arr, &arr2);
	displayArray(arr2);
	 
	
	return 0;
}
