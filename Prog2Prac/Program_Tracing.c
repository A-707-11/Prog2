#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "Hello World";
	char str2[] = "Youtube.com";
	

//	strcat(str1,str2 + 4);
//	puts(str1);
	strcpy(str1 + 4,str2 + 4);
	puts(str1);
}
