#include <stdio.h>


struct Info{
	char fname[24];
	char mi;
	char lname[24];
};
struct student{
	struct Info name; 
	int id;
	char gender;
};

void Display_1(struct student X);

int main ()
{
	struct student A = {.name={.fname = "Arjoy", .mi='M', .lname="Estiola"
	}, .id = 12345, .gender='M'};
	struct student B = {.name={.fname = "Joe", .mi='W', .lname="Bush"}
	, .id = 54321, .gender='M'};
	
	
	
	Display_1(A);
	
}

void Display_1(struct student X)
{
	printf("Name:   %s %c %s\n", X.name.fname, X.name.mi, X.name.lname);
	printf("ID no.: %d\n", X.id);
	printf("Gender: %c\n", X.gender);
}
