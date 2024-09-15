#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	FILE *fh_output;
//	FILE *fh_output2;
//	int ch;
//	
	fh_output = fopen("io.txt", "w");
	
//	int input = 0;
//	
//	while (true)
//	{
//		printf("Enter #: ");
//		scanf("%d", &input);
//		if (input == -1)break;
//		else fprintf(fh_output, "%d\n", input);
//	}
	


	fputs("\nA string\n", fh_output);
	fputs("Hello World\n", fh_output);
	fputs("A string\n", fh_output);
	printf("\n");

	fprintf(fh_output, "\nData: %s\n\n", "Youtube.com");
	
	fclose(fh_output);

	fh_output = fopen("io.txt", "r");
	
	if (fh_output == NULL)
	{
		printf("Failed to open File\n");
	}
	
	while((ch = fgetc(fh_output)) != EOF)
	{
		putchar(ch);
	}
	
	
	return 0;
}
