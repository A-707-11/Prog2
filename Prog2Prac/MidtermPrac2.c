#include <stdio.h>
#include <string.h>

void selectionSort(char arr[], int size);
void BubbleSort(char arr[], int size);
void swap(char *a, char *b);

int main() {
    char str[] = "Hello World";
    int n = strlen(str);
    
    printf("Original string: %s\n", str);
    
    selectionSort(str, n);
    
    printf("Sorted string: %s\n", str);
    
    return 0;
}

void selectionSort(char arr[], int size) 
{
    int i, j, min;
    
    for (i = 0; i < size-1; i++) {
        min = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
       
            swap(&arr[i], &arr[min]);
        
    }
}

void BubbleSort(char arr[], int size)
{
	
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

