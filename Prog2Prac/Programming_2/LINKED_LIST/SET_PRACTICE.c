#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node{
	int data;
	struct node* link;
}*SET;

SET Union(SET *A, SET *B);
void insertSorted(SET *X, int data);
void display(SET X);

int main()
{
	//INITILIZATION OF TWO LIST
	SET mySetA = NULL;
	SET mySetB = NULL;
	
	//SET A
	insertSorted(&mySetA,10);
	insertSorted(&mySetA,5);
	insertSorted(&mySetA,13);
	display(mySetA);
	
	//SET B
	insertSorted(&mySetB,10);
	insertSorted(&mySetB,5);
	insertSorted(&mySetB,13);
	display(mySetB);
	
	//UNION
	SET mySetC = Union(&mySetA,&mySetB);
	display(mySetC);
	
}

SET Union(SET *A, SET *B) {
    SET temp = NULL;
    SET C = NULL;
    SET* travA = A;
    SET* travB = B;

    for (; *travA != NULL && *travB != NULL; travA = &(*travA)->link, travB = &(*travB)->link) 
	{
        if ((*travA)->data < (*travB)->data) {
            temp = *travA;
            *travA = (*travA)->link;
        } else if ((*travA)->data > (*travB)->data) {
            temp = *travB;
            *travB = (*travB)->link;
        } else { 
            temp = *travA;
            *travA = (*travA)->link;
            *travB = (*travB)->link;
        }

        temp->link = C;
        C = temp;
    }

    while (*travA != NULL) 
	{
        temp = *travA;
        *travA = (*travA)->link;
        temp->link = C;
        C = temp;
    }

    while (*travB != NULL) 
	{
        temp = *travB;
        *travB = (*travB)->link;
        temp->link = C;
        C = temp;
    }

    return C;
}

void insertSorted(SET *X, int data)
{
	SET* trav = X;
	SET newNode = (SET)malloc(sizeof(struct node));
	
	if(newNode != NULL)
	{
		newNode->data = data;
		newNode->link = NULL;

		if(*trav == NULL || newNode->data <= (*trav)->data)
		{
			newNode->link = *trav;
			*trav = newNode;	
		}
		else
		{
			for(; (*trav)->link != NULL && (newNode->data > (*trav)->link->data); trav = &(*trav)->link){}
		
			newNode->link = (*trav)->link;
			(*trav)->link = newNode;
		}
		
	}
	
}

void display(SET X)
{
	SET trav = X;
	
	for(;trav != NULL; trav = trav->link)
	{
		printf("%d ", trav->data);
	}
	printf("\n");
}
