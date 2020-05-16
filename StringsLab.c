#include<stdio.h>
int isPalindrom(char* myString);
void countChars(char*myString, int*lowercase, int*uppercase, int*digits, int*other);
void deleteSpaces(char*mystring);
int charPosition(char*str, char c);
void swapStrings(char* str1, char*str2);
void main()
{
	char mystr1[50],mystr2[50];
	int uppercase,lowercase,digits,other;
	gets(mystr1);
	gets(mystr2);
	swapStrings(mystr1, mystr2);
	puts(mystr1);
	puts(mystr2);
}
int isPalindrom(char* myString)
{
	//we want to know where is the start and where is the end of the string.
	char* start, *end,temp;
	int pali = 1,lenght = strlen(myString);//lenght keeps the size of the stirng without \0.
	start = myString;
	end = myString + (lenght - 1);
	while (start < end)
	{//swapping.
		if (pali == 1 && *start != *end)
		{
			pali = 0;
		}
		temp = *start;
		*start = *end;
		*end = temp;
		start++; end--;
	}
	return pali;
}
void countChars(char*myString, int*lowercase, int*uppercase, int*digits, int*other)
{
	char* stringPtr = myString;//pointer which will point to the string in the main.
	*lowercase = *uppercase = *digits = *other = 0;//reseting the counters;
	while (*stringPtr != '\0')
	{
		//checking for each character:
		if (*stringPtr >= 'a' && *stringPtr <= 'z')//lower case char.
		{
			(*lowercase)++;//incremening.
		}
		else if (*stringPtr >= 'A' && *stringPtr <= 'Z')//upper case
		{
			uppercase[0]++;
		}
		else if (*stringPtr >= '0' && *stringPtr <= '9')//digit
		{
			(*digits)++;
		}
		else
		{
			other[0]++;
		}
		stringPtr++;
	}
}
void deleteSpaces(char*mystring)
{
	int i, j;
	i = 1;
	j = 0;
	while (mystring[i] != '\0')
	{
		if (mystring[i - 1] != ' ' || mystring[i] != ' ')//not in a space sequence
		{
			j++;
			mystring[j] = mystring[i];
		}
		i++;
	}
	mystring[++j] = '\0';
}
int charPosition(char*str, char c)
{
	int i;
	i = strlen(str)-1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return i;
		}
		i--;
	}
	return -1;
}
void swapStrings(char* str1, char*str2)
{
	char*p, *q,tmp,*tmpPtr;//p will point to str1, q will point to str2. tmpPtr will be a pointer which will help us keep track of where to put \0 in the end.
	p = str1;
	q = str2;
	while (*p != 0 && *q != 0)//swapping the strings as long as neigher of them are at the end.
	{
		tmp = *p;
		*p = *q;
		*q = tmp;
		p++; q++;
	}
	if (*p == '\0'&& *q != '\0')//str1 is shorter => we need to complete it with the rest of str2.
	{
		tmpPtr = q;
		while (*tmpPtr != '\0')
		{
			*p = *tmpPtr;
			p++; tmpPtr++;//nwo this temp pointer will be incremented and q will keep poiting to where i need to input \0.
		}
		
	}
	else if (*q == '\0'&& *p != '\0')//str2 is shorter => we need to complete it with the rest of str1.
	{
		tmpPtr = p;
		while (*tmpPtr != '\0')
		{
			*q = *tmpPtr;
			q++; tmpPtr++;//nwo this temp pointer will be incremented and q will keep poiting to where i need to input \0.
		}
		
	}
	*p = *q = '\0';// this will "cut" the string in the right position.

}