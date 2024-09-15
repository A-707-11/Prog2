#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = "the big brown fox jumps over samantha.";
	char a[] = "samantha loves big a big brown fox."
	char del[] = " .";
	
	char *word = strtok(s,del);
	char *word2 = strtok
	
	while (word != NULL && )
	{
		printf("%s\n", word);
		word = strtok(NULL,del);
	}
}
