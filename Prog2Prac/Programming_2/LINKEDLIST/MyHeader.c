#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"

void insertFront(NodePtr *list, int item)
{
	NodePtr temp = malloc(sizeof(NodeType));
	
	if(temp != NULL)
	{
		temp->data = item;
		temp->next = *list;
		*list = temp;
	}
}

void display(NodePtr list)
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
int getSum(NodePtr list)
{
	int sum = 0;
	while(list != NULL)
	{
		sum += list->data;
		list = list->next;
	}
	return sum;
}
float getAverage(NodePtr list)
{
	float sum = 0; 
	int count = 0;
	
	while(list != NULL)
	{
		count++;
		sum += list->data;
		list = list->next;
	}
	
	return sum/count;
	
}
int countFactors(NodePtr list, int value)
{
	int count = 0;
	while(list != NULL)
	{
		if((list->data % value) == 0)
		{
			count++;
		}
		list = list->next;
	}
	return count;
}

void doubleOddNumbers(NodePtr list)
{
	while(list != NULL)
	{
		if((list->data % 2) != 0)
		{
			list->data *= 2;
		}
		list = list->next;
	}
}

NodePtr getAllEven(NodePtr list)
{
	NodePtr newHead = NULL;
	NodePtr current = list;
	NodePtr prev = NULL;

	
	while(current != NULL)
	{
		if((current->data % 2) == 0)
		{
			if(prev == NULL)
			{
				list = current->next;
			}
			else
			{
				prev->next = current->next;
			}
				current->next = newHead;
				newHead = current;
				current = list;
		}
		else
		{
			prev = current;
			current = current->next;
		}
		
	}
	return newHead;
}

void deleteFront(NodePtr *list)
{
	*list = (*list)->next;
}

void deleteEnd(NodePtr *list)
{
	NodePtr current = *list;
	NodePtr prev = NULL;
	while(current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
}

NodePtr lowerThan(NodePtr list, int data)
{
	NodePtr temp = NULL;
	NodePtr current = list;
	NodePtr prev = NULL;
	
	while(current != NULL)
	{
		if(current->data < data)
		{
			if(prev == NULL)
			{
				list = current->next;
			}
			else
			{
				prev->next = current->next;	
			}
			current->next = temp;
			temp = current;
			current = list;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	return temp;
}

