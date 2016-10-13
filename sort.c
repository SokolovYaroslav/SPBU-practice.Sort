#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* arr;

#include "compareStrings.c"
#include "swap.c"
#include "bubblesort.c"
#include "insertsort.c"
#include "quicksort.c"

int main()
{
	int n;
	int i;
	FILE * inputdata;
	inputdata = fopen("inputdata.txt", "r");
	fscanf(inputdata, "%d\n", &n);
	int *a;
	a = (int*)malloc(sizeof(int) * n);
	for(i = 0; i != n; ++i)
	{
		a[i] = 0;
	}
	n = 0;
	int c;
	while((c = fgetc(inputdata)) != EOF)
	{
		if(c != '\n')
		{
			a[n]++;
		}
		else
		{
			n++;
		}
	}
	for(i = 0; i != n; i++)
	{
		printf("%d ", a[i]);
	}
	puts("\n");
	rewind(inputdata);
	int useless;
	fscanf(inputdata, "%d\n", &useless);
	arr *array;
	array = (arr*)malloc(sizeof(arr) * n);
	for(i = 0; i != n; ++i)
	{
		array[i] = (arr)malloc(a[i] + 2);
		fgets(array[i], a[i] + 2, inputdata);
	}
	quicksort(array, n - 1);
	FILE * outputdata;
	outputdata = fopen("outputdata.txt", "w");
	for(i = 0; i != n; ++i)
	{
		fputs(array[i], outputdata);
	}

	return 1;
}