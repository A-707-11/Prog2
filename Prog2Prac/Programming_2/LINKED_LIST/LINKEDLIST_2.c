#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NodeType;

void display(NodeType *head);
void insertFirst(NodeType **head, int data);
void insertMid(NodeType *head, int pos, int data);
void deleteMid(NodeType *head, int pos);
NodeType* getOdd(NodeType *head);

int main(){
	
	NodeType *head = NULL;
	
	display(head);
	
	//INSERT FIRST
	insertFirst(&head,24);
	insertFirst(&head,69);
	insertFirst(&head,88);
	insertFirst(&head,68);
	insertFirst(&head,38);
	insertFirst(&head,54);
	display(head);
	
	//INSERT MID
	insertMid(head,4,65);
	display(head);
	
	//DELETE MID
	deleteMid(head,4);
	display(head);
	
	return 0;
}

void display(NodeType *head)
{
	printf("{");
	while (head != NULL)
	{
		printf("%d", head->data);
		if(head->next != NULL)
		{
			printf("->");
		}
		head = head->next;
	}
	printf("}\n");
}

void insertFirst(NodeType **head, int data)
{
	NodeType* newNode = malloc(sizeof(NodeType));
	
	if(newNode != NULL)
	{
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		printf("Allocation Failed!\n");
	}
}

void insertMid(NodeType *head, int pos, int data)
{
	NodeType *current = head;
	NodeType *prev = head;
	
	NodeType* newNode = malloc(sizeof(NodeType));
	newNode->data = data;
	
	while(pos != 1)
	{
		prev = current;
		current = current->next;
		pos--;
	}
	newNode->next = prev->next;
	prev->next = newNode;
}

void deleteMid(NodeType *head, int pos)
{
	NodeType *current = head;
	NodeType *prev = NULL;
	
	while(pos != 1)
	{
		prev = current;
		current = current->next;
		pos--;
	}
	prev->next = current->next;
}
