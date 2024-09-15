#include <stdio.h>
#include <stdlib.h>

typedef char String[30];

typedef struct node{
    int data;
    struct node *next;
}NodeType, *NodePtr;

void insertFront(NodePtr *list, int item);
void deleteItem(NodePtr *list, int item);
void displayList(NodePtr list);
NodePtr removeEven(NodePtr *list);

int main()
{
    String menu[4] = {"Add Item","Remove Item","Display Even","Display List"};
    int choice = 0, i, item;
    NodePtr myList = NULL;
    
    do {
        system("CLS");
        for(i = 0; i < 4; ++i)
        {
            printf("[%d] %s\n", i+1, menu[i]);
        }
        printf("Enter your choice <0 to EXIT>: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 0:
                printf("Thank you.\n");
            case 1:
                printf("ADD ELEMENT\n");
                printf("Enter item to insert: ");
                scanf("%d", &item);
                
                insertFront(&myList, item);
                displayList(myList);                
                break;
            case 2:
                printf("REMOVE ELEMENT\n");
                printf("Enter item to remove: ");
                scanf("%d", &item);
                
                deleteItem(&myList, item);
                displayList(myList);
                break;
            case 3:
                printf("DISPLAY EVEN\n");
                NodePtr evenList = removeEven(&myList);
                displayList(evenList);
                break;        
            case 4:
                printf("DISPLAY LIST\n");
                displayList(myList);
                break;
            default:    
                printf("Invalid choice!!!\n");        
        }
        system("PAUSE");
        
    }while (choice != 0);
    printf("END OF PROGRAM!!!\n");
}

void insertFront(NodePtr *list, int item)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(NodeType));
    
    if(newNode != NULL)
    {
        newNode->data = item;
        newNode->next = *list;
        *list = newNode;
    }
    
}

void deleteItem(NodePtr *list, int item)
{
    NodePtr *trav;
    NodePtr temp;
    
    for(trav = list;*trav != NULL && (*trav)->data != item; trav = &(*trav)->next);
    
    if(*trav != NULL)
    {
        temp = *trav;
        *trav =(*trav)->next;
        free(temp);
    }
    
}

void displayList(NodePtr list)
{
    printf("{");
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("}\n");
}

NodePtr removeEven(NodePtr *list) {
    NodePtr removeData = NULL;
    NodePtr *trav;
    NodePtr temp;
    
    for (trav = list; *trav != NULL; ) {
        if (((*trav)->data % 2) == 0) {
            temp = *trav;
           *trav = (*trav)->next;
            temp->next = removeData;
            removeData = temp;
        }
        else
		{
			trav = &(*trav)->next;
		}
        
    }

    return removeData;
}

