#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

void showData();
void insertData();
void deteleData();
void insert_sortData();
void searchData();

int main()
{
	NODE *head = NULL;
	
	insertData(&head,8);
	insertData(&head,9);
	insertData(&head,20);
	insertData(&head,32);
	showData(&head);
	deteleData(&head,9);
	showData(&head);
	
	return 0;
}

void insertData(NODE **head, int data)
{
	NODE **trav = NULL;
	NODE *newNode = malloc(sizeof(NODE));
	
	for(trav = head; *trav != NULL; trav = &(*trav)->next){}
	
	if(newNode != NULL)
	{
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
	}
	
}

void deteleData(NODE **head, int data)
{
	NODE **trav = NULL;
	NODE *temp;
	
	for(trav = head; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next);
	
	if(*trav != NULL)
	{
		temp = *trav;
		*trav = (*trav)->next;
		free(temp)
	}
	
}

void showData(NODE **head)
{
	NODE **trav = NULL;
	
	printf("\n");
	for(trav = head; *trav != NULL; trav = &(*trav)->next)
	{
		printf("%d", (*trav)->data);
		if((*trav)->next != NULL)
		{
			printf("->");
		}
	}
	printf("\n");
}
