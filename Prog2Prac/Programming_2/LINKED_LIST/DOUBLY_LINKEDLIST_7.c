#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

// Function to create a new circular doubly linked list containing even numbers
Node* createEvenList(Node* head) {
    Node* evenHead = NULL;
    Node* current = head;

    if (head == NULL) {
        printf("Empty list.\n");
        return NULL;
    }

    do {
        if (current->data % 2 == 0) {
            insertEnd(&evenHead, current->data);
        }
        current = current->next;
    } while (current != head);

    return evenHead;
}

// Function to display the circular doubly linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to free the memory allocated for the circular doubly linked list
void freeList(Node** head) {
    if (*head == NULL) {
        return;
    }

    Node* current = *head;
    Node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}

// Driver code
int main() {
    Node* head = NULL;
    Node* evenList;

    // Example usage
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);

    printf("Original List: ");
    displayList(head);

    evenList = createEvenList(head);

    printf("Even List: ");
    displayList(evenList);

    freeList(&head);
    freeList(&evenList);

    return 0;
}

