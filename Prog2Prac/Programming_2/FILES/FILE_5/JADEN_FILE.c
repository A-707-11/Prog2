#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    int ID;
} details;

typedef struct node {
    details data;
    struct node* next;
} List;

void writeToFile(char fileName[], char mode[], details* record);
void *readFromFile(char fileName[], char mode[]);
void createNode(List **head, details data);
void displayList(List *head);

int main(){
	int i;
	List *head = NULL;
    details record[5] = {
        {"John", 20, 1001},
        {"James", 18, 1002},
        {"Jeff", 22, 1003},
        {"Jesse", 15, 1004},
        {"Ryan", 28, 1005}
    };

    writeToFile("exercise.txt", "w", record);

    details *fRecord = readFromFile("exercise.txt", "r");
    

	
	for(i = 0; i<5; i++){
		createNode(&head, fRecord[i]);	
	}
	
	displayList(head);

    return 0;
}


void writeToFile(char fileName[], char mode[], details *record){
    int i = 0;
    FILE* fp;
    
    fp = fopen(fileName, mode);
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
	
    fwrite(&record[i++], sizeof(details), 5, fp);
        
    fclose(fp);
}


void *readFromFile(char fileName[], char mode[]){
    FILE* fp;
    int i = 0;
    details* fRecord;

    fp = fopen(fileName, mode);

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
	
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp)/sizeof(details);
	rewind(fp);
	
    fRecord = (details*)malloc(sizeof(details) * size);
	
    fread(&fRecord[i++], sizeof(details), size, fp);
    
    fclose(fp);
    
    return fRecord;
}

void createNode(List **head, details data){
	
	List *newNode = (List*)malloc(sizeof(List));
	newNode->data = data;
	
	if(newNode != NULL){
		newNode->next = *head;
		*head = newNode;
	}
	else{
		printf("Node not created\n");
	}
}


void displayList(List *head){
	
	while(head != NULL){
		printf("%s\n", head->data.name);
		head = head->next;
	}
}
