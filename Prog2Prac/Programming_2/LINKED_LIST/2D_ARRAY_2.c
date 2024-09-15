#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void inputSudoku(int sudoku[][3],int row,int col); 
void outputSudoku(int sudoku[][3],int row, int col);
bool checkSudoku(int sudoku[][3],int row, int col);
 
int main(void)
{
 	int sudoku[3][3][3] = {0};
 	int i, j;
 	
// 	for(i = 0; i < 3; i++)
// 	{
// 		for(j = 0; j < 3; j++)
// 		{
// 			outputSudoku(sudoku,3,3);
//		}
//		 		
//	}

 	outputSudoku(sudoku,3,3);
 	
 
    return (0);
}

void inputSudoku(int sudoku[][3],int row,int col)
{
	printf("Enter Numder for Position [%d][%d]: ", row, col);
	scanf("%d", &sudoku[row][col]);
//	outputSudoku(sudoku,3,3);
}

void outputSudoku(int sudoku[][3],int row, int col)
{
	int i, j;
	
	printf("\n");
	for(i = 0; i < row; i++)
 	{
 		for(j = 0; j < col; j++)
 		{
 			printf(" [%d]", sudoku[i][j]);
		}
		printf("\n\n");	 		
	}
}
