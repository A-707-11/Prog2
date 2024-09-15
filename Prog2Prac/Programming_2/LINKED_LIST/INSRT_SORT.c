#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

void insertNode(NODE **head, int data);
void insertSortList(NODE **head, int data);
void bubbleSort(NODE *head);
void display(NODE *head);

int main(void)
{
	NODE *head = NULL;
	
	insertNode(&head,6);
	insertNode(&head,3);
	insertNode(&head,4);
	insertNode(&head,14);
//	insertNode(&head,12);
	display(head);
	
	insertSortList(&head,26);
	insertSortList(&head,14);
	display(head);
	
	bubbleSort(head);
	display(head);
	
	
	return 0;
}

//NodePtr removeEven(NodePtr *list)
//{
//    NodePtr removeData = NULL;
//    NodePtr *trav;
//    NodePtr temp;
//    
//    for(trav = list; *trav != NULL;)
//	 {
//		 if(((*trav)->data % 2) == 0)
//		{
//		    temp = *trav;
//		    *trav = (*trav)->next;
//		    temp->next = removeData;
//		    removeData = temp;
//		}
//		else
//		{
//		    trav = &(*trav)->next;
//	 	}
//	 }    
//    return removeData;
//}

void insertNode(NODE **head, int data)
{
	NODE *newNode = malloc(sizeof(NODE));
	
	if(newNode != NULL)
	{
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
	}
}

void bubbleSort(NODE *head)
{
	NODE *current = head;
	NODE *trav = NULL;
	int temp;
	
	while(current != NULL)
	{	
		trav = current->next;
		while(trav != NULL)
		{
			if(trav->data < current->data)
			{
				temp = trav->data;
				trav->data = current->data;
				current->data = temp;
			}
			trav = trav->next;
		}
		current = current->next;
	}
}

void insertSortList(NODE **head, int data)
{
	NODE *current = *head;
	NODE *newNode = malloc(sizeof(NODE));
	newNode->data = data;
	
	if(current == NULL || current->data > newNode->data)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		while(current->next != NULL && current->next->data < newNode->data)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	
}

void display(NODE *head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		
		head = head->next;
	}
	printf("\n");
}
