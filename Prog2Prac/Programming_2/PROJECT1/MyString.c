#include <stdio.h>
#include <stdlib.h>
#include "MyString.h"

int getLength(char a[])
{
	int i = 0;
	
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}

void copyString(char dest[], char src[])
{
	int i = 0;
	
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int compareString(char str1[], char str2[])
{
	int i = 0;
	int count = 0;

	while(str1[i] != '\0' || str2[i] != '\0' )
	{
		if(str1[i] != str2[i])
		{
			count++;
		}
		i++;
	}
	
	if (count == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}
void concatenateString(char str1[], char str2[])
{
	int i = 0;
	int len = getLength(str1);
			
	while(str2[i] != '\0')
	{
		str1[len + i] = str2[i];
		i++;
	}
	str2[i] = '\0';
}
void displayString(char str[])
{
	int i = 0;
	
	while(str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
} 
