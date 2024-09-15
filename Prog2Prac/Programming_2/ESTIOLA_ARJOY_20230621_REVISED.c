#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool makePalindrome(char *arr);
int count(char a[], char c);
void trimLeftRight(char a[]);
bool toggle(char a[]);

int main ()
{
	char str[100];
	char n; 
   
	printf("Enter a string: \n");
	scanf("%[^\n]s", str);
	fflush(stdin);
	
	//makePalindrome
	if (makePalindrome(str) == true)
	{
		printf("Word is a Palindrome!\n");
	}
	else
	{
		printf("\nWord is not a palindrome. Converting it to a palindrome text....\n");
		printf("%s\n\n", str);
	}
	
	//count
	printf("Enter a character to be searched: \n");
	scanf("%c", &n);
	if(isalpha(n) == 0)
	{
		printf("The character is not a letter.\n\n");
	}
	else
	{
		printf("The letter exists %d times in the string.\n", count(str, n));
	}
	
	//trimLeftRight
	trimLeftRight(str);
	printf("\nTrimmed String: |%s|\n", str);
	
	//toggle
	if(toggle(str) != 0)
	{
		printf("Toggled: |%s|\n", str);
	}
	else
	{
		printf("\nToggle operation is not successful.");
	}

}

bool makePalindrome(char *arr)
{
	char arr2[20];
	strcpy(arr2,strrev(arr));
	if(strcmp(arr,strrev(arr2)) == 0)
	{
		return true;
	}
	else
	{
		strrev(arr);
		strrev(arr2);
		strcat(arr,arr2);
		return false;
	}
	return 0;
}

int count(char a[], char c)
{
	int count = 0, i = 0;
	
	while (a[i] != '\0')
	{
		if(a[i] == c)
		{
			count++;
		}
		i++;
	}
		return count;				
}

void trimLeftRight(char a[])
{
	int i, c, b;
	int length = strlen(a);

	for(i = 0; i < length; i++)
	{
		if (isalnum(a[i]))
		{
			c = i;
			break;
		}			
	}
	
	for(i = length; i > 0; i--)
	{
		if(isalnum(a[i]))
		{
			b = i;
			break;
		}
	}
	
	for(i = 0; i < length; i++)
 	{
		a[i] = a[c];
		c++;
		a[b+1] = '\0';
	}
}

bool toggle(char a[])
{
	int i, count = 0;
	int length = strlen(a);

	for(i = 0; i < length; i++)
	{
		if(!isalpha(a[i]))
		{
			count++;
		}
		else if(isupper(a[i]))
		{
			a[i] = tolower(a[i]);
		}
		else
		{
			a[i] = toupper(a[i]);
		}		
	}	
	
	if(count == length)
	{
		return false;
	}
	else
	{
		return true;
	}
}


