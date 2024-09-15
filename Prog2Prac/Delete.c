#include <stdio.h>
#define MAX_SCORES 10

void chooseChoice (int *choice);
void displayArray (int a[], int size);
void inputScore (int a[], int size);
float average (int a[], int size);
int min (int a[], int size);
int retrieve (int pos, int a[], int size);
int retrieve_last (int a[], int size);
int retrieve_first (int a[]);
int search (int X, int a[], int size);

int main () {
	
	int scores[MAX_SCORES];
	int i, user_choice, position, value;
	
	for (i=0; i<MAX_SCORES; scores[i] = 0, i++) {}
	printf("\t  !!! All values have been initialized to -1 !!!\n\n");
	chooseChoice(&user_choice);
	
	while (user_choice != 0) 
	{
		switch (user_choice) {
			case 1: //Display Scores
				displayArray(scores, MAX_SCORES);
				inputScore(scores, MAX_SCORES);
				printf("\nNEW SCORES: \n"); displayArray(scores, MAX_SCORES);
				break;
			case 2: //Input Scores
				inputScore(scores, MAX_SCORES);
				printf("\nNEW SCORES: \n"); displayArray(scores, MAX_SCORES);
				break;
			case 3: //Average
				printf("The total average of the array is: %.2f\n\n", average(scores, MAX_SCORES));
				break;
			case 4: //Minimum
				printf("The minimum score found in the array is: %d\n\n", min(scores, MAX_SCORES));
				break;
			case 5: //Retrieve (index)
				do {
					printf("Enter the index you wish to find [MAXIMUM IS %d, MINIMUM IS 0]: ", MAX_SCORES-1); 
					scanf("%d", &position);
				} while (position < 0 || position >= MAX_SCORES);
				((retrieve(position, scores, MAX_SCORES)) == -1) ? printf("The position does not exist or the score is -1\n") : printf("The index contains the score: %d\n", retrieve(position, scores, MAX_SCORES));
				break;
			case 6: //Retrieve first (index value)
				printf("The first score is: %d\n", retrieve_first(scores));
				break;
			case 7: //Search for value
				printf("Enter the value to search for: "); scanf("%d", &value);
				((search(value, scores, MAX_SCORES)) == -1) ? printf("The score does not exist or the score is -1\n") : printf("%d is in the score list\n", search(value, scores, MAX_SCORES));
				break;
			case 8: //Retrieve last (index value)
				printf("The last score is: %d\n", retrieve_last(scores, MAX_SCORES));				
				break;
			default:
				printf("Invalid choice!");
				break;
		}
		printf("\n");
		chooseChoice(&user_choice);
	} 
	return 0;
}

void chooseChoice (int *choice) {
	printf("\t\t----------MENU CHOICE----------\n");
	printf("[1]Display Score   [2]Input Score   [3]Average   [4]Minimum\n[5]Retrieve   [6]Retrieve First   [7]Search   [8]Retrieve Last");
	printf("\n\t\tIf done, use [0] to exit the function\n\t\t------------------------------\n\n");
	printf("SELECT A NUMBER: ");
	scanf("%d", choice);
}

void displayArray (int a[], int size) {
	int i;
	for (i=0; i<size; printf("Scores[%d]: %d\n", i, a[i]), i++) {}
}

void inputScore (int a[], int size) {
	int i;
	printf("\nINPUT THE SCORES: \n");
	for (i=0; i<size; printf("Scores[%d]: ", i), scanf("%d", &a[i]), i++) {}
}

float average (int a[], int size) {
	int i;
	float ave = 0.00;
	
	for (i=0; i<size; ave+=(*(a+i)), i++) {}
	ave = ave / size;
	return ave;
}

int min (int a[], int size) {
	int i = 0, minimum = a[i];
	
	while (i<size) {
		if (a[i] < minimum && a[i]!=minimum) {
			minimum = a[i];
		}
		i++;
	}
	
	return minimum;
}

int retrieve (int pos, int a[], int size) {
	//!(pos>=0 && pos<size)
	if (pos>=0 && pos<size) {
		return a[pos];
	} else {
		return -1;
	}
}

int retrieve_last (int a[], int size) {
	return a[size-1];
}

int retrieve_first (int a[]) {
	return a[0];
}

int search (int X, int a[], int size) {
	int i;
	for (i=0; i<size && a[i] != X; i++) {}
	
	if (i == size) {
		return -1;
	} else {
		return a[i];
	}
}
