#ifndef MYHEADER_H
#define MYHEADER_H

typedef struct node {
	int data;
	struct node *next;
}NodeType, *NodePtr;

void insertFront(NodePtr *list, int item);
void display(NodePtr list);

int getSum(NodePtr list);
float getAverage(NodePtr list);
int countFactors(NodePtr list, int value);
void doubleOddNumbers(NodePtr list);
void deleteFront(NodePtr *list);
void deleteEnd(NodePtr *list);

NodePtr getAllEven(NodePtr list);
NodePtr lowerThan(NodePtr list, int data);

#endif
