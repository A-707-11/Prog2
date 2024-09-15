#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool makePalindrome(char *arr);

int main()
{
	char arr1[20];
	
	printf("Enter a string: \n");
	scanf("%[^\n]s", arr1);
	printf("Checking...:\n\n\n");
	
	if (makePalindrome(arr1) == true)
	{
		printf("Word is a Palindrome!");
	}
	else
	{
		printf("Word is not a palindrome. Converting it to a palindrome text....\n");
		printf("%s", arr1);
	}
	

}

bool makePalindrome(char *arr)
{
	char arr2[20];
	strcpy(arr2,strrev(arr));//tac
	if(strcmp(arr,strrev(arr2)) == 0)//cat
	{
		return true;
	}
	else
	{
		strrev(arr);
		strrev(arr2);
		strcat(arr,arr2); //
		return false;
	}
	return 0;
}
