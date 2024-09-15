#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the list structure
typedef struct {
    int array[MAX_SIZE];
    int length;
} ArrayList;

// Initialize a new empty list
void initList(ArrayList *list) {
    list->length = 0;
}

// Insert an element at the end of the list
int insert(ArrayList *list, int value) {
    if (list->length < MAX_SIZE) {
        list->array[list->length] = value;
        list->length++;
        return 1; // Success
    } else {
        return 0; // Failure, list is full
    }
}

// Delete an element at a specific index
int delete(ArrayList *list, int index) {
	
	int i;
    if (index >= 0 && index < list->length) {
        for (i = index; i < list->length - 1; i++) {
            list->array[i] = list->array[i + 1];
        }
        list->length--;
        return 1; // Success
    } else {
        return 0; // Failure, invalid index
    }
}

// Get an element at a specific index
int get(ArrayList *list, int index) {
    if (index >= 0 && index < list->length) {
        return list->array[index];
    } else {
        // You can handle this error case differently, such as returning a special value or printing an error message.
        return -1; // Error: Invalid index
    }
}

int main() {
    ArrayList list;
    initList(&list);

    insert(&list, 5);
    insert(&list, 10);
    insert(&list, 15);

    printf("List elements: %d, %d, %d\n", get(&list, 0), get(&list, 1), get(&list, 2));

    delete(&list, 1); // Delete the element at index 1

    printf("List elements after deletion: %d, %d\n", get(&list, 0), get(&list, 1));

    return 0;
}

