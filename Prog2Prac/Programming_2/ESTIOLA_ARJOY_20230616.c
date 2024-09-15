#include <stdio.h>

#define BAR_CAPACITY 100

void line();
void registerBarHopperAges(int hopper_age[],int *count);
float computeAvergaeLegalAge();
int welcomeTheForties();
void TwentiesNightPromo();

int main()
{
	int barHopperAges[BAR_CAPACITY] = {0}, i;
	int count = 0;
	
	registerBarHopperAges(barHopperAges, &count);
	printf("  Current Count: %d\n", count);
	float b = computeAvergaeLegalAge(barHopperAges, &count);
	printf("        Average: %.2f\n\n", b);
	
	printf("Forties Count: %d\n\n", welcomeTheForties(barHopperAges, &count));
	for(i = 0; i < BAR_CAPACITY; i++)
	{
		if(barHopperAges[i] >= 40 && barHopperAges[i] <= 50 )
		{
			printf("Forties at [%d]\n", i);
		}
	}
	printf("\n");
	line();
	
	TwentiesNightPromo(barHopperAges);
	VIPPrioritySeating(barHopperAges, &count);
	for(i = 0; i < BAR_CAPACITY; i++)
	{
		printf("Seat[%d]: %d\n", i, barHopperAges[i]);
	}
	

}

void registerBarHopperAges(int hopper_ages[],int *count)
{
	int i;
	int *ptr = hopper_ages;
	
	for(i = 0; i < BAR_CAPACITY; i++)
	{
		printf("Enter your age: ");
		scanf("%d", ptr + i);
		
		if (ptr[i] == 0 || *count > BAR_CAPACITY)
		{
			break;
		}
		else if (ptr[i] < 13 || ptr[i] > 50)
		{
			i--;
			printf("\nError: Not Allowed!\n\n");
		}
		else if (ptr[i] >= 13 && ptr[i] <= 50)
		{
			ptr[(*count)++] = ptr[i];
		} 
	}
	printf("\n");
	line();
}

float computeAvergaeLegalAge(int *hopper_ages,int *count)
{
	int* ptr = hopper_ages;
	int i, num=0;
	float sum;
	for(i = 0; i < *count; i++)
	{
		if (ptr[i] > 17)
		{
			sum += *(ptr + i);
			num++;
		}	
	}
	
	if(num == 0)
	{
		return 100;
	}
	else
	{
		return sum/ num;	
	}
	line();
}

int welcomeTheForties(int *hopper_ages, int *count)
{
	int* ptr = hopper_ages;
	int size = 0, i; 
	
	for(i = 0; i < *count; i++)
	{
		if(ptr[i] >= 40 && ptr[i] <= 50)
		{
			size++;
		}
	}
	return size;
}

void TwentiesNightPromo(int *hopper_ages)
{
	int i, count = 0, twenties[count];
	int* ptr1 = hopper_ages;
	int* twPtr = twenties;
	
	for (i = 0; i < BAR_CAPACITY; i++)
	{
		if(*(ptr1+i) >= 20 && *(ptr1+i) <= 30)
		{
			twPtr[count++] = *(ptr1+i);
		}
	}

	printf("Guest in their 20's: \n\n");
	for (i = 0; i < count; i++)
	{
		printf("Twenties[%d]: %d\n\n", i, *(twPtr + i));
	}
	line();
}

int VIPPrioritySeating(int *hopper_ages, int *count)
{
	int age, ticNum, seat, i, temp;
	int *ptr = hopper_ages;
	
	printf("Please Enter Age: ");
	scanf("%d", &age);
	printf("Please Enter Ticket Number: ");
	scanf("%d", &ticNum);
	
	if (ticNum % 2 == 0)
	{
		for(i = 0; i < BAR_CAPACITY; i++)
		{
			if(ptr[i] == 0)
			{
				ptr[i] = age;
				return i;
			}
		}
	}
	else
	{
		printf("Select a seat: ");
		scanf("%d", &seat);
		if(ptr[seat] != 0)
		{
			temp = ptr[seat];
			ptr[seat] = age;
		}
		for(i = *count; i < BAR_CAPACITY; i++)
		{
			if (ptr[i] == 0)
			{
				ptr[i] = temp;
				return i;
			}
		}
	}	
}

void line()
{
	printf("--------------------------------------------\n\n");
}
