#include <stdio.h>
#define BAR_CAPACITY 5

int bar_hopper_count = 0;

void registerBarHopperAges(int hopperAge[], int count) {
	int *ptr = hopperAge;
	int guestAge;
	int i;
	int countGuest = 0;
	
	printf("Enter your age\n");
	for (i = 0; i < BAR_CAPACITY; i++) {
		printf("Guest age %d: ", count + 1);
		scanf("%d", &guestAge);
		
		if (guestAge == 0) {
			return;
		}
		else if (guestAge < 13 || guestAge > 50 ) {
			printf("Not Allowed\n");
		} else if (guestAge >= 13 && guestAge <= 50) {
			ptr[count++] = guestAge;
		}
	}
}

float computeAverageLegalAge(int *hopperAges) {
	int i;
	float sum = 0;
	int count = 0;
	float legalAgeFinder = 0;
	for (i = 0; i < BAR_CAPACITY; i++) {
		if (*(hopperAges+i) > 17)
		{
			sum += *(hopperAges+i);
			count++;
			legalAgeFinder++;
		} 
	}
	if (legalAgeFinder == 0) {
		return 100;
	}
	
	return sum / legalAgeFinder; 
	
}

int welcomeTheForties(int *hopperAges) {
	int i;
	int fortiesCounter = 0;
	
	printf("Guest in their Forties: \n");
	for (i = 0; i < BAR_CAPACITY; i++) {
		if (*(hopperAges + i) >= 40 && *(hopperAges + i) < 50)
		{
			printf("Seat number: %d\n", i);
			fortiesCounter++;
		}
	}
	return fortiesCounter;
}

void TwentiesNightPromo(int *hopperAges) {
	int i, j;
	int twentiesCounter = 0;
	int twenties[twentiesCounter];
	printf("Guests in their twenties: \n");
	for (i = 0; i < BAR_CAPACITY; i++) {
		if (*(hopperAges + i) >= 20 && (*(hopperAges + i)) < 30)
		{
			twenties[twentiesCounter] = *(hopperAges + i); 
//			twenties[twentiesCounter++] = *(hopperAges +i);
//			printf("twenties[%d]: %d\n", i, twenties[i]);
			twentiesCounter++;
		}
	}
	printf("\n%d\n", twentiesCounter);
//	int twenties[twentiesCounter];
	int *twPtr = twenties;
	for (j = 0; j < twentiesCounter; j++) {
		printf("twenties[%d]: %d\n", j, *(twPtr+j));
//		printf("twenties[%d]: %d\n", j, twenties[j]);
	}
	
}

int VIPPrioritySeating(int *hopperAges) {
	int ticketNum;
	int age;
	int seatNum;
	int i;
	
	printf("Enter your age: ");
	scanf("%d", &age);
	printf("Enter your ticket number: ");
	scanf("%d", &ticketNum);
	
	if (ticketNum % 2 != 0) {
		printf("Choose your desired seat number: ");
		scanf("%d", &seatNum);
		*(hopperAges + seatNum) = age;
	} else {
		for (i = 0; i < BAR_CAPACITY; i++) {
			if (*(hopperAges + i) == 0)
			{
				*(hopperAges +i) = age;
				return seatNum = i;
			}
		}
	}
	return seatNum;
	
	
	// store the guest's age to the index of the chosen seat num
	// if the element is vacant (value == 0)
	// If the ticket number is even store the age to the first vacant seat number
	// Return the seat number
	// display the returned seat number and the age of the new guest in main
	
	/* Modify this so that if the VIP will choose a seat that is already occupied
	It will transfer the one who is seated to that chosen seat to the first vacant
	seat and Transfer the VIP to that chosen seat
	*/
	
	
}




int main() {
	int barHopperAges[BAR_CAPACITY] = {0}, i;
	
	registerBarHopperAges(barHopperAges, bar_hopper_count);
	printf("Show ages: \n");
	for (i = 0; i < BAR_CAPACITY; i++) {
		printf("Hopperage[%d]: %d\n", i, barHopperAges[i]);
	}
	
	// Compute the average of all the legal age
	float legalAgeAverage;
	printf("\nCompute Average of Legal Ages:\n");
	legalAgeAverage = computeAverageLegalAge(barHopperAges);
	printf("%.1f\n", legalAgeAverage); 
	
	// Guests in their forties
	int guestsInForties = welcomeTheForties(barHopperAges);
	printf("The total of guest in their forties is %d\n", guestsInForties);
	
	printf("\n");
	// Guests in their twenties
	TwentiesNightPromo(barHopperAges);
	
	// VIP Priority Seating
	int VIPSeating;
	VIPSeating = VIPPrioritySeating(barHopperAges);
	printf("Seat[%d]: %d", VIPSeating, barHopperAges[VIPSeating]);
	
	
	
	
	return 0;
	
}
