#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	NodePtr mylist = NULL;
	
	display(mylist);
	
	insertFront(&mylist, 7);
	display(mylist);
	insertFront(&mylist, 10);
	display(mylist);
	insertFront(&mylist, 10);
	display(mylist);
	insertFront(&mylist, 20);
	display(mylist);
	
	NodePtr lowerList = lowerThan(mylist, 10);
	display(lowerList);
	
//	deleteFront(&mylist);
//	display(mylist);
//	deleteEnd(&mylist);
//	display(mylist);

//	doubleOddNumbers(mylist);
//	display(mylist);

	NodePtr evenList = getAllEven(mylist);
	printf("\nEVEN LIST\n");
	display(evenList);
	
	printf("%d\n", getSum(mylist));
	printf("%.2f\n", getAverage(mylist));
	printf("%d\n", countFactors(mylist, 2));
	
	
	
	
	return 0;
}
