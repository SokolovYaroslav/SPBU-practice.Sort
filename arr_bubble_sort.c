#include <stdio.h>
#include <stdlib.h>
#include "arr_bubble_sort.h"
#include "arr_compare_strings.h"
#include "arr_swap.h"

void arr_bubble_sort(arr *array, int n)
{
	int i = 0;
	int j = 0;

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(arr_compare_strings(array[j], array[j + 1]) == 1)
			{
				arr_swap(&array[j], &array[j + 1]);
			}
		}
	}
}