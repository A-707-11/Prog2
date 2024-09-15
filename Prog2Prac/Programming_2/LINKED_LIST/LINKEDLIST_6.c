#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node* next;
}list;

void insertSorted(list **head);
int searchData(list ** head);
void deleteAllValues(list ** head);
void display(list *head);

int main()
{
	list *myList = NULL;
	int i;
	display(myList);
	
	for(i = 0; i < 10; i++)
	{
		insertSorted(&myList);
		display(myList);
	}
	
	if(searchData(&myList) == -1)
	{
		printf("Data Not Found");
	}
	else
	{
		printf("Data selected is at: %d", searchData(&myList));
	}
	
	deleteAllValues(&myList);
	display(myList);
}

void insertSorted(list **head)
{
	list* newNode = malloc(sizeof(list));
	list* current = *head;
	list* prev = NULL;
	char data;
	
	printf("Enter Data to Insert: ");
	scanf(" %c", &newNode->data);

	newNode->next = NULL;	
	
	if(current == NULL || newNode->data <= current->data)
	{
		newNode->next = *head;
		*head = newNode;	
	}
	else
	{
		while(current != NULL && newNode->data > current->data)
		{
			prev = current;
			current = current->next;
		}
		newNode->next = current;
		prev->next = newNode;
		
	}
		
}

int searchData(list **head)
{
 	int i = 1;
 	char data;
 	list **trav;
 	
 	printf("\nEnter Character to Search: ");
	scanf(" %c", &data);
 	
 	for(trav = head; *trav != NULL && (*trav)->data != data; trav = &(*trav)->next, i++){}
	
	if(*trav == NULL)
	{
		return -1;
	}
	else if ((*trav)->data == data)
	{
		return i;
	}
	
	
}

void deleteAllValues(list **head)
{
	list *current = *head;
	list *temp;
	list *prev = NULL;
	char data;
	
	printf("\nSelect Data to Remove: ");
	scanf(" %c", &data);	
		
	while(current != NULL)
	{
		if(current->data == data)
		{
			if(prev == NULL)
			{
				*head = current->next;
            	free(current);
            	
			}
			else
			{
				temp = current;
	            prev->next = current->next;
	            free(temp);
			}
			current = *head;	
		}
		else
		{
			prev = current;
			current = current->next;
			
		}	
	}
}

void display(list *head)
{
	printf("\n{");
	for(;head != NULL; head = head->next)
	{
		printf("%c", head->data);
		if(head->next != NULL)
		{
			printf("->");
		}
	}
	printf("}\n");
}
