#include<stdio.h>

void switchRows(void**mat, int row1, int row2);
void switchCols(int**mat, int col1, int col2, int numRows);
void printMat(int**mat, int rows, int cols);
void freeMatrix(int**mat, int rows);
void main()
{
	int **mat, rows, cols, i, j;
	printf("Please input the number of rows:\n");
	scanf("%d", &rows);
	printf("Please input the number of cols:\n");
	scanf("%d", &cols);
	mat = (int**)calloc(rows, sizeof(int*));//dynamically allocating the rows.
	for (i = 0; i < rows; i++)
	{
		mat[i] = (int*)calloc(cols, sizeof(int));//dynamically allocating the columns.
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mat[i][j] = i + j;
		}
	}
	printf("Before switching rows:\n");
	printMat(mat, rows, cols);
	switchRows(mat, 1, 3);
	printf("After switching rows:\n");
	printMat(mat, rows, cols);
	switchCols(mat, 1, 3,rows);
	printf("After switching Cols:\n");
	printMat(mat, rows, cols);
	freeMatrix(mat, rows);//freeing the matrice.
}

void switchRows(void**mat, int row1, int row2)
{
	void* tmp;
	tmp = mat[row1];
	mat[row1] = mat[row2];
	mat[row2] = tmp;
}
void switchCols(int**mat, int col1, int col2, int numRows)
{
	int tmp,i;
	for (i = 0; i < numRows; i++)
	{
		tmp = mat[i][col1];
		mat[i][col1] = mat[i][col2];
		mat[i][col2] = tmp;
	}
}
void printMat(int**mat, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%4d", mat[i][j]);
		}printf("\n");
	}
}
void freeMatrix(int**mat, int rows)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		free(mat[i]);//freeing the dynamic array of each row.
	}
	free(mat);
}