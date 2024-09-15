#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int size);
void Scan(int **v, int size); // added a pointer to pointer parameter
void swap(int *x, int *y);

int main() {

    int n;
    int i;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // pass the address of the pointer to the Scan function
    Scan(&arr, n);

    BubbleSort(arr, n);

    // free the memory allocated using malloc
    free(arr);

    return 0;
}

void BubbleSort(int arr[], int size) {
    int i, j;
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    // print the sorted array
    printf("Sorted array: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Scan(int **v, int size) {
    int i;

    // allocate memory using malloc
    *v = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the array: \n");
    for(i = 0; i < size; i++) {
        scanf("%d", (*v) + i);
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

