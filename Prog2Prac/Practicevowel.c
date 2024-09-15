#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>

int find_smallest_int(const int array[/* len */],int len)
{
  int i;
  int min_ndx = array[0];
 
  
  
  for(i=0; i<len; i++)
    {
    
	    if(array[i]<min_ndx)
	    {
	    	min_ndx = array[i];     
	    }
    	
        
    }
    return min_ndx;
}

int main()
{
    char str[] = "Object Oriented Programming";
    int n = strlen(str);
    int i, j = 0;
    char newStr[n];

    printf("%s\n", str);

    for (i = 0; i < n; i++)
    {
        if (tolower(str[i]) != 'a' && tolower(str[i]) != 'e' && tolower(str[i]) != 'i' && tolower(str[i]) != 'o' && tolower(str[i]) != 'u')
        {
        	
            newStr[j] = str[i];
            j++;
        }
    }

    newStr[j] = '\0'; // add null terminator to the end of the new string

    printf("%s\n", newStr);
    
    int num[] = {33,2,311,-225,65,46,74};

	int q = find_smallest_int(num,10);
	printf("%d", q);
    return 0;
}
