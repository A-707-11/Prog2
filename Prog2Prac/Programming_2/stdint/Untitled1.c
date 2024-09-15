#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
	char sentence[50];
}WORD;

char *reverseWord(char str[]);

int main ()
{
	WORD str;
	
	strcpy(str.sentence,"The boy is not a girl.");
	
	printf("%s\n", str.sentence);
	reverseWord(str.sentence);
	printf("%s", str.sentence);
}

char *reverseWord(char str[])
{
	int len = strlen(str);
	int i, j;
	char temp[50];
	
	for(i = 0; i < len; i++)
	{
		for(j = 0; i < len; j++, i++)
		{
			if(str[i] == ' ' || str[i] == '.')
			{
				break;
			}
			else
			{
				temp[j] = str[i];
			}
		}
		
		while(j > 0)
		{
			j--;
			str[i - j - 1] = temp[j];
		}
		
	}
}

