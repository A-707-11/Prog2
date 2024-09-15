#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char FName[20];
    char LName[20];
    char MI;
} StudName;

typedef struct {
    StudName name;
    int id;
    char course[5];
    int year;
} StudDetails;

typedef struct studtype {
    struct studtype* prev;
    StudDetails data;
    struct studtype* next;
} LIST;

void enroll(LIST** head);
LIST* retrieveGraduatingDCISMStuds(LIST** dcism_studs, LIST** graduating_studs);
void printGraduatingStuds(LIST* graduating_studs);
void displayDCISMStuds(LIST* head);

int main()
{
    LIST* dcism_studs = NULL;
    LIST* graduating_studs = NULL;
    int i;

    for (i = 0; i < 5; i++) {
        enroll(&dcism_studs);
    }

    displayDCISMStuds(dcism_studs);
    LIST* graduating = retrieveGraduatingDCISMStuds(&dcism_studs, &graduating_studs);

    printGraduatingStuds(graduating);
}

void enroll(LIST** head)
{
    LIST* newNode = malloc(sizeof(LIST));
    LIST* tail = NULL;

    if (newNode != NULL) {
        printf("\nENTER STUDENT DETAILS\n");
        printf("Last Name: ");
        gets(newNode->data.name.LName);
        printf("First Name: ");
        gets(newNode->data.name.FName);
        printf("Middle Initial: ");
        scanf(" %c", &newNode->data.name.MI);
        printf("ID: ");
        scanf("%d", &newNode->data.id);
        fflush(stdin);
        printf("Course: ");
        gets(newNode->data.course);
        printf("Year Level: ");
        scanf("%d", &newNode->data.year);
        fflush(stdin);

        if (*head == NULL) {
        	*head = newNode;
            newNode->prev = newNode;
            newNode->next = newNode;
        } else {
        	
            tail = (*head)->prev;
            newNode->next = *head;
            (*head)->prev = newNode;
            newNode->prev = tail;
            tail->next = newNode;
            
        }
    }
}

LIST* retrieveGraduatinDCISMStuds(LIST **dcism_studs, LIST **graduating_studs)
{
	LIST *current = *dcism_studs;
	LIST *prev = NULL;
	LIST *temp;
	
	while(current != NULL)
	{
		if((current)->data.year == 4 && ((strcmp((current)->data.course,"BSIT") == 0)||(strcmp((current)->data.course,"BSCS") == 0)||(strcmp((current)->data.course,"BSIS") == 0)))
		{
			if(prev == NULL)
			{
				*dcism_studs = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			temp = current;
			current = *dcism_studs;
			temp->next = *graduating_studs;
			*graduating_studs = temp;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	
	return *graduating_studs;
}

void printGraduatingStuds(LIST* graduating_studs)
{
    printf("-----------GRADUATING STUDENTS------------");
    LIST* current = graduating_studs;

    do {
        printf("\nName: %s %c %s\n", current->data.name.FName, current->data.name.MI, current->data.name.LName);
        printf("ID: %d\n", current->data.id);
        printf("Course: %s\n", current->data.course);
        printf("Year: %d\n\n", current->data.year);

        current = current->next;
    } while (current != graduating_studs);
}

void displayDCISMStuds(LIST* head)
{
    printf("-----------ENROLLED STUDENTS------------");
    LIST* current = head;

    do {
        printf("\nName: %s %c %s\n", current->data.name.FName, current->data.name.MI, current->data.name.LName);
        printf("ID: %d\n", current->data.id);
        printf("Course: %s\n", current->data.course);
        printf("Year: %d\n\n", current->data.year);

        current = current->next;
    } while (current != head);
}

