#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef char String[20];

typedef struct {
	String fname;
	int age;
	String brngy;
	int numID;
	char gender;
}StudInfo;

typedef struct node{
	StudInfo data;
	struct node* next;
}LIST;
