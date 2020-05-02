#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 
int** initiateLowerTri(int size);
int lowerTriValue(int**lowerTri, int row, int col);
void printLowerTri(int**lowerTri, int size);
int** initiateUpperTri(int size);
int upperTriValue(int**upperTri, int row, int col);
void printUpperTri(int**upperTri, int size);


void main()
{
	//int** lowerTri;
	//lowerTri = initiateLowerTri(5);
	//printLowerTri(lowerTri, 5);
	int**upperTri;
	upperTri = initiateUpperTri(5);
	printUpperTri(upperTri, 5);
}


int** initiateLowerTri(int size)
{
	//dynamically allocate the matrice:
	int** lowerTri, i, j;
	srand(time(0));
	lowerTri = (int**)malloc(size * sizeof(int*));//allocate size amount of arrays.
	for (i = 0; i < size; i++)
	{
		/* for each row we will have more and more values.*/
		lowerTri[i] = (int*)malloc((i + 1) * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j<=i;j++)
		{
			lowerTri[i][j] = rand()%20+1;//24534579283742398%20 = 1-20
		}
	}
	return lowerTri;
}
int lowerTriValue(int**lowerTri, int row, int col)
{
	if (col > row)
	{
		return 0;
	}
	else
	{
		return lowerTri[row][col];
	}
}
void printLowerTri(int**lowerTri, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%4d", lowerTriValue(lowerTri, i, j));
		}printf("\n");
	}
}
int** initiateUpperTri(int size)
{
	//dynamically allocate the matrice:
	int** upperTri, i, j,tmp = size;
	srand(time(0));
	upperTri = (int**)malloc(size * sizeof(int*));//allocate size amount of arrays.
	for (i = 0; i < size; i++)
	{
		upperTri[i] = (int*)malloc(tmp * sizeof(int));//tmp will help us create each array with the right size. size,size-1,size-2...1.
		tmp--;
	}
	for (i = 0; i < size; i++)
	{
		for (j = size - 1; j >= 0; j--)
		{
			upperTri[i][j] = rand() % 20 + 1;//so we can get values between 1 - 20.
		}
	}
	return upperTri;
}
int upperTriValue(int**upperTri, int row, int col)
{
	if (col < row)
	{
		return 0;
	}
	else
	{
		return upperTri[row][col];
	}
}
void printUpperTri(int**upperTri, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%4d", upperTriValue(upperTri, i, j));
		}printf("\n");
	}
}