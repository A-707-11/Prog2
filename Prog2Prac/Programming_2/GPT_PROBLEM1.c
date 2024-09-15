#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	int emp_id;
	char department[20];
	float salary;
}Employee;

void ask_user();
void display_emp();
float ave_salary();
Employee* above_ave(Employee p[], int *n, float ave);
void line();

int main()
{
	int n;
	Employee *person1;
	
	printf("Enter the number of employees: ");
	scanf("%d", &n);
	fflush(stdin);
	person1 = (Employee*)malloc(sizeof(Employee) * n);
	ask_user(person1, n);
	line();
	display_emp(person1, n);
	line();
	printf("Average Salary of All Employees: %.2f\n", ave_salary(person1, n));
	Employee* catcher = above_ave(person1, &n, ave_salary(person1, n));
	display_emp(*catcher, n);
	free(person1);
}

void ask_user(Employee *p, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("Enter Employee Name: ");
		gets((p+i)->name);
		printf("Enter Employee ID: ");
		scanf("%d", &(p+i)->emp_id);
		fflush(stdin);
		printf("Enter Employee Department: ");
		gets((p+i)->department);
		printf("Enter Employee Salary: ");
		scanf("%f", &(p+i)->salary);
		fflush(stdin);
		printf("\n");	
	}	
}

void display_emp(Employee *p, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("Employee Name: %s\n", (p+i)->name);
		printf("Employee ID: %d\n", (p+i)->emp_id);
		printf("Employee Department: %s\n", (p+i)->department);
		printf("Employee Salary: %.2f\n", (p+i)->salary);
		printf("\n");	
	}	
}

float ave_salary(Employee *p, int n)
{
	int i;
	float ave;
	for(i = 0; i < n; i++)
	{
		ave += (p+i)->salary;
	}
	return ave/n;
}

Employee* above_ave(Employee p[], int *n, float ave)
{
	int count = 0;
	int i;
	Employee* ptr = (Employee*)malloc(sizeof(Employee) * (*n));

	for(i = 0; i < *n; i++)
	{
		if((p+i)->salary > ave)
		{
			strcpy((ptr+count)->name, (p+i)->name);
			(ptr+count)->emp_id = (p+i)->emp_id;
			strcpy((ptr+count)->department, (p+i)->department);
			(ptr+count)->salary = (p+i)->salary;
			count++;
		}
	}
	*n = count;
	return ptr;
}

void line()
{
	printf("\n\n-------------------------------------------\n\n");
}
