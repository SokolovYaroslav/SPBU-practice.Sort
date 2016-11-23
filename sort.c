#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"
#include "insertsort.h"
#include "quicksort.h"
#include "MergeSort.h"

typedef char* arr;

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Invalid arguments\n");
		return 0;
	}
	int n = atoi(argv[1]);
	int i = 0;

	FILE * inputdata;
	inputdata = fopen(argv[2], "r");
	if(inputdata == NULL)
	{
		printf("Can't open input file\n");
		return 0;
	}

	if(n <= 0)
	{
		printf("Invalid input number of strings\n");
		fclose(inputdata);
		return 0;
	}
	//Massive with lenghs of strings
	int *a;
	a = (int*)malloc(sizeof(int) * (n + 2));
	//Count lenghs of strings
	int c = 0;	
	a[0] = 0;				
	while((c = fgetc(inputdata)) != EOF)
	{
		if(i <= n)
		{
			if(c != '\n')
			{
				a[i]++;
			}
			else
			{
				i++;
				a[i] = 0;
			}
		}
	}
	
	rewind(inputdata);

	arr *array;									
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

	int choice = 0;
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

	for(i = 0; i < n; i++)
	{
		printf("%s\n", array[i]);
		free(array[i]);
	}
	
	free(array);

	return 1;
}