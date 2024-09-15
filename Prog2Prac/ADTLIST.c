#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

// Define a structure for your elements
struct Element {
    int data;
};

// Define the structure for the dynamic array
struct DynamicArray {
    struct Element* elements;
    int size;
    int capacity;
};

// Function to initialize a dynamic array
void initDynamicArray(struct DynamicArray* arr) {
    arr->elements = (struct Element*)malloc(INITIAL_SIZE * sizeof(struct Element));
    arr->size = 0;
    arr->capacity = INITIAL_SIZE;
}

// Function to insert an element at the end
void insertAtEnd(struct DynamicArray* arr, struct Element element) {
    if (arr->size == arr->capacity) {
        // Expand the array by 10 if needed
        arr->capacity += 10;
        arr->elements = (struct Element*)realloc(arr->elements, arr->capacity * sizeof(struct Element));
    }
    arr->elements[arr->size] = element;
    arr->size++;
}

// Function to insert an element at the start
void insertAtStart(struct DynamicArray* arr, struct Element element) {
	
	int i;
	
    if (arr->size == arr->capacity) {
        // Expand the array by 10 if needed
        arr->capacity += 10;
        arr->elements = (struct Element*)realloc(arr->elements, arr->capacity * sizeof(struct Element));
    }
    
    // Shift all elements to the right
    for (i = arr->size; i > 0; i--) {
        arr->elements[i] = arr->elements[i - 1];
    }
    arr->elements[0] = element;
    arr->size++;
}

// Function to delete an element based on the location
void deleteAtIndex(struct DynamicArray* arr, int index) {
	
	int i;
	
    if (index >= 0 && index < arr->size) {
        for (i = index; i < arr->size - 1; i++) {
            arr->elements[i] = arr->elements[i + 1];
        }
        arr->size--;
    }
}

// Function to update an element based on the location
void updateAtIndex(struct DynamicArray* arr, int index, struct Element element) {
    if (index >= 0 && index < arr->size) {
        arr->elements[index] = element;
    }
}

// Function to copy the array to another array
void copyToArray(struct DynamicArray* source, struct DynamicArray* destination) {
	
	int i;
	
    // Ensure the destination array is large enough
    if (destination->capacity < source->size) {
        destination->capacity = source->size;
        destination->elements = (struct Element*)realloc(destination->elements, destination->capacity * sizeof(struct Element));
    }

    for (i = 0; i < source->size; i++) {
        destination->elements[i] = source->elements[i];
    }

    destination->size = source->size;
}

// Function to expand the array by 10
void expandArray(struct DynamicArray* arr) {
    arr->capacity += 10;
    arr->elements = (struct Element*)realloc(arr->elements, arr->capacity * sizeof(struct Element));
}

int main() {
	
	int i;
    struct DynamicArray arr;
    initDynamicArray(&arr);

    // Insert elements at the end and start
    struct Element element1 = {1};
    struct Element element2 = {2};
    struct Element element3 = {3};
    insertAtEnd(&arr, element1);
    insertAtStart(&arr, element2);
    insertAtEnd(&arr, element3);

    // Display the array
    for (i = 0; i < arr.size; i++) {
        printf("%d ", arr.elements[i].data);
    }
    printf("\n");

    // Delete an element at index 1
    deleteAtIndex(&arr, 1);

    // Display the updated array
    for (i = 0; i < arr.size; i++) {
        printf("%d ", arr.elements[i].data);
    }
    printf("\n");

    // Update an element at index 0
    struct Element newElement = {4};
    updateAtIndex(&arr, 0, newElement);

    // Display the updated array
    for (i = 0; i < arr.size; i++) {
        printf("%d ", arr.elements[i].data);
    }
    printf("\n");

    // Create another array and copy the original array to it
    struct DynamicArray copyArr;
    initDynamicArray(&copyArr);
    copyToArray(&arr, &copyArr);

    // Display the copied array
    for (i = 0; i < copyArr.size; i++) {
        printf("%d ", copyArr.elements[i].data);
    }
    printf("\n");

    // Expand the array by 10
    expandArray(&arr);

    // Clean up memory
    free(arr.elements);
    free(copyArr.elements);

    return 0;
}

