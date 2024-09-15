#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NodeType;

void insertFront();
void display();
void deleteMid(NodeType** list, int data);

int main()
{
	NodeType *myList = NULL;
	
	insertFront(&myList, 29);
	insertFront(&myList, 54);
	insertFront(&myList, 20);
	insertFront(&myList, 32);
	display(myList);
	
	deleteMid(&myList,32);
	display(myList);
	
}

void display(NodeType *list)
{
	printf("{");
	while(list != NULL)
	{
		printf("%d", list->data);
		if(list->next != NULL)
		{
			printf("->");
		}
		list = list->next;
	}
	printf("}\n");
}

void insertFront(NodeType** list, int data)
{
	NodeType *newNode = malloc(sizeof(NodeType));
	
	if(newNode != NULL)
	{
		newNode->data = data;
		newNode->next = *list;
		*list = newNode;
	}
	
}

void deleteMid(NodeType** list, int data)
{
	NodeType *current = *list;
	NodeType *prev = NULL;
	NodeType *temp;
	
	while(current != NULL)
	{
		if(current->data == data)
		{
			if(prev == NULL)
			{
				current = current->next;
				*list = current;
				temp = current;
			}
			else
			{
				temp = current;
				prev->next = current->next;	
			}	
		}
		prev = current;
		current = current->next;
	}
	free(current);
}

