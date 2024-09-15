#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[30];

typedef struct {
String fname;
int idNum;
}Person;

typedef struct node{
    Person data;
    struct node *next;
}NodeType, *NodePtr;

void insertFront(NodePtr *list,Person p1);
//void deleteItem(NodePtr *list, Person item);
void displayList(NodePtr list);
//NodePtr removeEven(NodePtr *list);
void insertRear(NodePtr *list,Person p1);
//void insertAt(NodePtr *list,Person item, int pos);
//void updateAt(NodePtr *list,Person replaceData, Person item);
void populateData(Person *p1);

int main()
{
    String menu[7] = {"Add Item","Remove Item","Insert Rear","Display Even","Insert Position","Update Data","Display List"};
    int choice = 0, i, item, pos, rep;
    Person p1;
    NodePtr myList = NULL;
    NodePtr evenList;
   
   
    do {
        system("CLS");
        for(i = 0; i < 7; ++i)
        {
            printf("[%d] %s\n", i+1, menu[i]);
        }
        printf("Enter your choice <0 to EXIT>: ");
        scanf("%d", &choice);
        fflush(stdin);
       
        switch(choice)
        {
            case 0:
                printf("Thank you.\n");
                break;
            case 1:
                printf("ADD NAME\n");
                populateData(&p1);
                insertFront(&myList, p1);
                displayList(myList);                
                break;
//            case 2:
//                printf("REMOVE ELEMENT\n");
//                printf("Enter item to remove: ");
//                scanf("%d", &item);
//                
//                deleteItem(&myList, item);
//                displayList(myList);
//                break;
            case 3:
				printf("INSERT REAR\n");
	            printf("Enter item to insert at rear\n");
	            populateData(&p1);
	            insertRear(&myList, p1);
	            displayList(myList);
	            break;       
// 		   	case 4:
// 		   		printf("DISPLAY EVEN\n");
//                evenList = removeEven(&myList);
//                displayList(evenList);
//                break; 
// case 5:
//                printf("INSERT POSITION\n");
//                printf("Enter item to insert: ");
//                scanf("%d", &item);
//                printf("Enter Position: ");
//                scanf("%d", &pos);
//               insertAt(&myList, item,pos);
//                displayList(myList);
//                break;
// case 6:
//                printf("UPDATE DATA\n");
//                printf("Enter item to be updated: ");
//                scanf("%d", &item);
//                printf("Enter Replacement: ");
//                scanf("%d", &rep);
//               updateAt(&myList, rep,item);
//                displayList(myList);
//                break;                
//            case 7:
//                printf("DISPLAY LIST\n");
//                displayList(myList);
//                break;
            default:    
                printf("Invalid choice!!!\n");        
        }
        system("PAUSE");
       
    }while (choice != 0);
    printf("END OF PROGRAM!!!\n");
}

void insertFront(NodePtr *list,Person p1)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(NodeType));
   
   
    if(newNode != NULL)
    {
      newNode->data = p1;
      newNode->next = *list;
        *list = newNode;
    }
   
}

//void deleteItem(NodePtr *list, int item)
//{
//    NodePtr *trav;
//    NodePtr temp;
//    
//    for(trav = list;*trav != NULL && (*trav)->data != item; trav = &(*trav)->next);
//    
//    if(*trav != NULL)
//    {
//        temp = *trav;
//        *trav = (*trav)->next;
//        free(temp);
//    }
//    
//}

void displayList(NodePtr list)
{
    printf("{");
    while (list != NULL)
    {
        printf("Name: %s\n", list->data.fname);
        printf("ID: %d\n ", list->data.idNum);
        list = list->next;
    }
    printf("}\n");
}

//NodePtr removeEven(NodePtr *list)
//{
//    NodePtr removeData = NULL;
//    NodePtr *trav;
//    NodePtr temp;
//    
//    for(trav = list; *trav != NULL;)
// {
// if(((*trav)->data % 2) == 0)
//    {
//        temp = *trav;
//        *trav = (*trav)->next;
//        temp->next = removeData;
//        removeData = temp;
//    }
//    else
//    {
//     trav = &(*trav)->next;
// }
// }    
//    return removeData;
//}

void insertRear(NodePtr *list,Person p1)
{
	 NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
	 NodePtr current = *list;
	
	 newNode->data = p1;
	 newNode->next = NULL;
	 if(current = NULL)
	 {
		 newNode->next = *list;
		 *list = newNode;
	 }
	 else
	 {
		 while(current->next != NULL)
		 {
		 	current = current->next;
		 }
		 current->next = newNode;
	 }
}
//
//void insertAt(NodePtr *list,int item, int pos)
//{
// NodePtr current = *list;
// NodePtr prev = NULL;
// NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
// newNode->data = item;
// newNode->next = NULL;
//
// while(pos != 1)
// {
// prev = current;
// current = current->next;
// pos--;
// }
//
// if(prev == NULL)
// {
// newNode->next = *list;
// *list = newNode;
// }
// else
// {
// newNode->next = prev->next;
// prev->next = newNode;
// }
//
//}
//
//void updateAt(NodePtr *list, int replaceData, int item)
//{
// NodePtr current = *list;
//
// while(current->data != item)
// {
// current = current->next;
// }
// current->data = replaceData;
//}
//
void populateData(Person *p1)
{
	printf("Enter Name: ");
	gets(p1->fname);

	printf("Enter ID: ");
	scanf("%d", &p1->idNum);

}
