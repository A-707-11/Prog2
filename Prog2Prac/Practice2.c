#include <stdio.h>
#include <stdlib.h>



struct Info{
	char fname[24];
	char mi;
	char lname[24];
	
};

void Display(struct Info X);
void Display_2(struct Info *Z);


int main ()
{
	struct Info Y = {"Arjoy", 'M', "Estiola"
	};
	
	printf("Name: %s %c %s\n", Y.fname, Y.mi, Y.lname);
	
	printf("Enter First Name: \n");
	fflush(stdin);
	scanf("%s", &Y.fname );
	
	printf("Enter Middle Initial: \n");
	fflush(stdin);
	scanf("%c", &Y.mi );
	
	printf("Enter Last Name: \n");
	fflush(stdin);
	scanf("%s", &Y.lname );
	
	Display(Y);
	Display_2(&Y);
}

void Display(struct Info X)
{
	
	
	printf("First Name: %s \n", X.fname);
	
	printf("Middle Initial: %c \n", X.mi);

	printf("Last Name: %s \n", X.lname);

	
	
}

void Display_2(struct Info *Z)
{
	printf("Fisrt Name: %s \n", (*Z).fname);
	
	printf("Middle Initial: %c \n", (*Z).mi);
	
	printf("Last Name: %s \n", (*Z).lname);
}
