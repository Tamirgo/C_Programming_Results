#include<stdio.h>
#include<stdlib.h>
int* EvenOddSplit(int*arr, int size, int**arr2, int*Evensize, int*Oddsize);
void CapsSplitter(char* original, int size, char**lowcase, char**uppercase,int*lowersize,int*uppersize);
printArray(int *arr, int size);
printCharArray(char*arr, int size);
void main()
{
	//int arr[10] = { 5,28,12,13,9,11,20,16,45,44 },evensize,oddsize,*oddarr,*evenarr;
	//evenarr = EvenOddSplit(arr, 10, &oddarr, &evensize, &oddsize);
	//printf("Even Size:%d\n", evensize);
	//printf("Even Array:\n");
	//printArray(evenarr, evensize);
	//printf("Odd size: %d\n", oddsize);
	//printf("Odd array:\n");
	//printArray(oddarr, oddsize);
	//free(oddarr);
	//free(evenarr);
	char letters[10] = { 'a','c','D','u','Z','F','T','q','g','B' },*lowercase,*uppercase;
	int uppersize, lowersize;
	CapsSplitter(letters, 10, &lowercase, &uppercase, &lowersize, &uppersize);
	printCharArray(lowercase, lowersize);
	printCharArray(uppercase, uppersize);
	free(lowercase);
	free(uppercase);
}

int* EvenOddSplit(int*arr, int size, int**oddarr, int*Evensize, int*Oddsize)
{
	//going to split the original array into two arrays.
	int* evenarr, i;
	evenarr = (int*)calloc(size, sizeof(int));
	*oddarr = (int*)calloc(size, sizeof(int));
	*Evensize = *Oddsize = 0;//reseting them.
	for (i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)//even
		{
			evenarr[Evensize[0]++] = arr[i];
		}
		else//odd
		{
			oddarr[0][Oddsize[0]++] = arr[i];
		}
	}
	evenarr = (int*)realloc(evenarr, *Evensize * sizeof(int));
	*oddarr = (int*)realloc(*oddarr, *Oddsize * sizeof(int));
	return evenarr;
}

printArray(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%4d", arr[i]);
	}
	printf("\n");
}

void CapsSplitter(char* original, int size, char**lowcase, char**uppercase, int*lowersize, int*uppersize)
{
	int i;
	*uppercase = (char*)calloc(size, sizeof(char));//allocating
	*lowcase = (char*)calloc(size, sizeof(char));
	*lowersize = *uppersize = 0;//reseting.
	for (i = 0; i < size; i++)
	{
		if (original[i] >= 'a' && original[i] <= 'z')//lower case
		{
			lowcase[0][lowersize[0]++] = original[i];
		}
		else if (original[i] >= 'A' && original[i] <= 'Z')//uppercase
		{
			uppercase[0][uppersize[0]++] = original[i];
		}
		//no need for else since we don't want to do anything with non letter chars.
		
	}
	*lowcase = (char*)realloc(lowcase[0], *lowersize * sizeof(char));
	uppercase[0] = (char*)realloc(*uppercase, *uppersize * sizeof(char));

}
printCharArray(char*arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%4c", arr[i]);
	}
	printf("\n");
}
