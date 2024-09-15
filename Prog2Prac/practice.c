#include <stdio.h>
#include <stdbool.h>

bool xo (const char* str)
{
	int i;
	int x_count = 0;
	int o_count = 0;
	
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == 'x' || str[i] == 'X')
		{
			x_count++;
		}
		else if (str[i] == 'o' || str[i] == 'O')
		{
			o_count++;
		}
	}

	if(x_count == o_count)
	{
		return true;
	}
	else
	return false;
}

int main()
{
	char str[] = "Xo";
	
	 xo(str) ? printf("true"):printf("false");
}
