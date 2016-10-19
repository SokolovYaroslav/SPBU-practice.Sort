#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* arr;

#include "compareStrings.c"
#include "swap.c"
#include "bubblesort.c"
#include "insertsort.c"
#include "quicksort.c"
#include "MergeSort.c"

int main()
{
	int n0 = 0; 									//Number of strings
	int i = 0;

	FILE * inputdata;
	inputdata = fopen("inputdata.txt", "r");
	fscanf(inputdata, "%d\n", &n0);
	
	int *a;										//Massive with lenths of strings
	a = (int*)malloc(sizeof(int) * n0);
	
	int n = 0;
	n0--;									//Now we'll get more accurate value
	int c = 0;									//Count number and lenths of strings
	a[n] = 0;
	while((c = fgetc(inputdata)) != EOF)
	{
		if(n < n0)
		{
			if(c != '\n')
			{
				a[n]++;
			}
			else
			{
				n++;
				a[n] = 0;
			}
		}
		else if(n == n0)
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
		else
		{
			printf("Input number of strings less than real number of strings\n");
			free(a);
			fclose(inputdata);
			return 0;
		}
	}
	
	rewind(inputdata);							//Reopen file and move cursor
	int useless;
	fscanf(inputdata, "%d\n", &useless);

	arr *array;									//Select memory and get strings
	array = (arr*)malloc(sizeof(arr) * n);
	int k = 0;
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

	int choice = 0;								//Sort array
	printf("Choose algorithm of sorting\n"
		    "Bubblesort - 1\n"
		    "Insertsort - 2\n"
		    "Quicksort - 3\n"
		    "MergeSort - 4\n"
		    "Your choice is = ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: bubblesort(array, n); break;
		case 2: insertsort(array, n); break;
		case 3: quicksort(array, n - 1); break;
		case 4: MergeSort(array, n); break;
		default:
			printf("wrong answer, then algorithm will be Quicksort\n"); 
			quicksort(array, n - 1); break;
	}

	FILE * outputdata;							//Put sorted array in file
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