#include "Merge.c"

void MergeSortRecurse(arr *array, arr *arrayB, int n, int *pos)
{
	*pos = 0;

	if(n < 2)
	{
		return;
	}

	int mid = n / 2;
	int pos0;
	int pos1;

	MergeSortRecurse(array, arrayB, mid, &pos0);
	MergeSortRecurse(array + mid, arrayB + mid, n - mid, &pos1);

	if(pos0 != pos1)
	{
		if(pos0 == 0)
		{
			for(int i = mid; i < n; i++)
			{
				array[i] = arrayB[i];
			}
		}
		else
		{
			for(int i = mid; i < n; i++)
			{
				arrayB[i] = array[i];
			}
		}
	}

	if(pos0 == 0)
	{
		merge(array, mid, array + mid, n - mid, arrayB);
		*pos = 1;
	}
	else
	{
		merge(arrayB, mid, arrayB + mid, n - mid, array);
		*pos = 0;
	}
}