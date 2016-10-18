#include "MergeSortRecurse.c"

void MergeSort(arr *array, int n)
{
	if(n < 2)
	{
		return;
	}

	int pos = 0;
	int i = 0;
	arr *arrayB = (arr*)malloc(sizeof(arr) * n);

	MergeSortRecurse(array, arrayB, n, &pos);

	if(pos == 1)
	{
		for(i = 0; i < n; i++)
		{
		array[i] = arrayB[i];
		}
	}
	free(arrayB);
}