#include <stdio.h>
#include <stdlib.h>
#include "MyString.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char arr1[] = "hello ";
	char arr2[10] = "world";
	
	printf("String1: %s\n", arr1);
	printf("String2: %s\n\n", arr2);
	printf("String Length: %d (string1)\n\n", getLength(arr1));
	printf("String Length: %d (string2)\n\n", getLength(arr1));
	concatenateString(arr1, arr2);
	printf("Concatenated String: ");
	displayString(arr1);
	printf("\n");
	printf("Comparison 1: %d\n\n", compareString(arr1, arr2));
	printf("String1 :%s\n", arr1);
	copyString(arr2, arr1);
	printf("||Copy String1 to String2||\n");
	printf("String2 :%s\n", arr2);
	printf("\n");
	printf("Comparison 2: %d\n\n", compareString(arr1, arr2));
	
	
	
	
	
	
	
	return 0;
}
