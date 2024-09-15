#include <stdio.h>

int printMid(int start, int end)
{
	int i, sum = 0;
	
	for(i = start + 1; i < end; i++)
	{
		if((i % 2) == 0)
		{
			sum += i;
			printf("%d ", i);
		}
	}
	printf("\n");
	return sum;
}

int main()
{
	printf("%d", printMid(2,20));
}
