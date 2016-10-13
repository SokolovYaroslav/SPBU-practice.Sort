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
	puts("\n");
	rewind(inputdata);
	int useless;
	fscanf(inputdata, "%d\n", &useless);
	arr *array;
	array = (arr*)malloc(sizeof(arr) * n);
	int k;
	for(i = 0; i != n; ++i)
	{
		k = 0;
		array[i] = (arr)malloc(a[i] + 1);
		while(((c = fgetc(inputdata)) != '\n') && (c != EOF))
		{
		array[i][k] = c;
		k++;
		}
		array[i][k] = '\0';
	}
	free(a);
	fclose(inputdata);
	quicksort(array, n - 1);
	FILE * outputdata;
	outputdata = fopen("outputdata.txt", "w");
	for(i = 0; i != n; ++i)
	{
		fputs(array[i], outputdata);
		fputc('\n', outputdata);
		free(array[i]);
	}
	fclose(outputdata);
	free(array);

	return 1;
}