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
	int n; 										//Number of strings
	int i;

	FILE * inputdata;
	inputdata = fopen("inputdata.txt", "r");
	fscanf(inputdata, "%d\n", &n);
	
	int *a;										//Massive with lenths of strings
	a = (int*)malloc(sizeof(int) * n);
	
	n = 0;										//Now we'll get more accurate value
	int c;										//Count number and lenths of strings
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
	
	rewind(inputdata);							//Reopen file and move cursor
	int useless;
	fscanf(inputdata, "%d\n", &useless);

	arr *array;									//Select memory and get strings
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

	int choice;									//Sort array
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