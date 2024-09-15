#include <stdio.h>

void display(int arr[], int len);
void deleteElement(int arr[], int *len, int num);

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int len = sizeof(arr)/sizeof(int);
	int i;
	
	display(arr,len);
	deleteElement(arr,&len,5);
	display(arr,len);
	
}

void display(int arr[], int len)
{
	int i;
	
	for(i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void deleteElement(int arr[], int *len, int num)
{
    int i, j;

    for (i = 0; i < *len; i++)
    {
        if (arr[i] == num)
        {
            for (j = i; j < *len - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*len)--;
            i--;
        }
    }
}


