#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void inputSudoku(int sudoku[][3],int row,int col); 
void outputSudoku(int sudoku[][3],int row, int col);
bool checkSudoku(int sudoku[][3],int row, int col);
 
int main(void)
{
 	int sudoku[3][3] = {0};
 	int i, j;
 	
 	for(i = 0; i < 3; i++)
 	{
 		for(j = 0; j < 3; j++)
 		{
 			inputSudoku(sudoku,i,j);
		}
		 		
	}

 	outputSudoku(sudoku,3,3);
 	printf("\n%s", checkSudoku(sudoku,3,3)? "true" : "false");
 
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

bool checkSudoku(int sudoku[][3], int row, int col)
{
	int i, j, k, l;
    int count = 0;
    int* values = malloc(row * col * sizeof(int));  

    printf("\n");
    for (i = 0; i < row; i++) 
	{
        for (j = 0; j < col; j++) 
		{
            for (k = i; k < row; k++) 
			{  
                for (l = (k == i) ? j + 1 : 0; l < col; l++) 
				{  
                    if (sudoku[i][j] == sudoku[k][l]) 
					{
                        values[count++] = sudoku[i][j];
                    }
                }
            }
        }
    }

    if (count != 0)
	{
        printf("The repeating values are: ");
        for (i = 0; i < count; i++) {
            printf("%d ", values[i]);
        }
        printf("\n");
        return false;
    } else 
	{
        return true;
    }
}


