#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void DisplayArray(char arr[], int size);
void Copy(char src[]);
void input(int size);

int main ()
{
	char num[] = {'H','E','L','L','O'};
	char str[] = "Hello World";
	int n;
	
	
	DisplayArray(num,5);
	Copy(str);
	
	
	scanf("%d", &n);
	input(n);
}


// Concept: arrays in function parameter
void DisplayArray(char arr[], int size)
{
	int i;
	
	printf("Concept: Arrays in Function Parameter\n\n");
	for(i=0;i<size;i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
	printf("===========================\n");
}

// Function memcpy and memmov
void Copy(char src[])
{
	char dest[11];
	char dest2[6];
	
	printf("Function: memcpy and memove\n\n");
	// memcpy will copy a string from a source variable to the destination variable
	memcpy(dest, src, sizeof(char) * 11);
	printf("dest: %s\n", dest);
	//memcpy specific part of a string
	memcpy(dest2, src+6, sizeof(char) * 5);
	printf("dest2: %s\n", dest2);
	//memmove 
	memmove(dest, src, sizeof(char) * 11);
	printf("memmov: %s\n", dest);
	printf("===========================\n");
}

//Dynamic Memory Allocation: malloc, calloc, realloc, free
void input(int size)
{
	char *mal = (char*)malloc(size * sizeof(char));
	int i;
	
	for(i=0;i<size;i++)
	{
		printf("Input a Character: \n");
		fflush(stdin);
		scanf("%c", mal+i);
	}
	for(i=0;i<size;i++)
			{
				printf("malloc: %c\n", *(mal+i));
			}
	
	
	int *cal = (int*)calloc(size, sizeof(int));
	
	for(i=0;i<size;i++)
	{
		printf("Input a Number: \n");
		scanf("%d", cal+i);
	}
	for(i=0;i<size;i++)
			{
				printf("calloc: %d\n", *(cal+i));
			}
	
	int *realoc;
	char ans[4];
	
	printf("Type 'Yes' if you want to add 2 numbers to your calloc\n");
	printf("Type 'No' if you don't want to add 2 numbers to your calloc\n");
	
	scanf("%s", &ans);
	
	if (strcmp(ans, "Yes") == 0)
		{
			realoc = (int*)realloc(cal, (size+2) * sizeof(int));
			
			 for (i = size; i < size + 2; i++)
			{
				scanf("%d", realoc+i);
			}
			for(i=0;i<size+2;i++)
				{
					printf("Input a Number: \n");
					printf("realloc: %d\n", *(realoc+i));
				}	
			free(cal); // free the original memory block allocated by calloc
	    }
	    else
	    {
	        realoc = cal; // assign realoc to cal so that we don't lose the reference to the original memory block allocated by calloc
	        printf("Fine");
	    }
	
	    free(mal);
	    free(realoc);
				
}






