#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}NodeType;

void insertFront(NodeType **header, int item);
void insertLast(NodeType ** header, int data);
void deleteData(NodeType **header, int data);
int main ()
{
	NodeType *head = NULL;
	
	NodeType *node1 = malloc(sizeof(NodeType));
	
	head = node1;
	
	node1->data = 10;
	node1->link = NULL;
	insertLast(&head, 30);
	insertFront(&head, 30);
	insertFront(&head, 20);
	insertFront(&head, 20);
	insertFront(&head, 20);
	deleteData(&head, 20);
	deleteData(&head, 20);
	
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->link;
	}
}
void insertFront(NodeType **header, int data)
{
	NodeType *node2 = malloc(sizeof(NodeType));
	
	node2->data = data;
	node2->link = *header;
	*header = node2;
	
}
void insertLast(NodeType **header, int data)
{
	NodeType *temp = *header;
	NodeType *newNode = malloc(sizeof(NodeType));
	newNode->data = data;
	newNode->link = NULL;
	
	if(*header == NULL)
	{
		*header = newNode;
	}
	else
	{
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = newNode;
	}
	
}
void deleteData(NodeType **header, int data)
{
	NodeType *current = *header;
	NodeType *prev = NULL;
	int key = data;
	
	while (current != NULL)
	{
		if(current->data == key)
		{
			if(prev == NULL)
			{
				*header = current->link;
			}
			else
			{
				prev->link = current->link;
			}
			free(current);
			return;
		}
		prev = current;
		current = current->link;	
	}
	
}
