#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} LIST;

void insertNode(LIST **head, int data);
void sortNode(LIST **head);

int main(void)
{
    LIST* head = NULL;
    insertNode(&head, 3);
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 5);
    insertNode(&head, 4);

    sortNode(&head);

    // Print the sorted list
    LIST* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}

void insertNode(LIST **head, int data)
{
    LIST* newNode = malloc(sizeof(LIST));

    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
    }
}

void sortNode(LIST **head)
{
    if (*head == NULL || (*head)->next == NULL) {
        // List is empty or has only one node
        return;
    }

    LIST* current = *head;
    LIST* index = NULL;
    int temp;

    while (current != NULL) 
	{
        index = current->next;

        while (index != NULL) 
		{
            if (current->data > index->data) 
			{
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}


