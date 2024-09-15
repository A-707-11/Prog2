#include <stdio.h>
#include <stdlib.h>
#include "SortLib.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int arr[] = {5,3,2,6,7,4};
	int len = sizeof(arr)/sizeof(int);
	
	display(arr,len);
	
//	printf("Bubble Sort: \n");
//	bubbleSort(arr,len);
//	display(arr,len);

//	printf("Selection Sort: \n");
//	selectionSort(arr,len);
//	display(arr,len);
	
	printf("Insertion Sort: \n");
	insertionSort(arr,len);
	display(arr,len);
	
	
	return 0;
}
