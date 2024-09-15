#include <stdio.h>

union one{
	int a;
	int b;
};

int main()
{
	union one one;
	one.a = 5;
	one.b = 10;
	
	printf("%d", one.a);
}
