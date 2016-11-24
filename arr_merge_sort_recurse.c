#include <stdio.h>
#include <stdlib.h>
#include "arr_merge_sort_recurse.h"
#include "arr_merge.h"
#include "arr_compare_strings.h"
#include "arr_swap.h"

void arr_merge_sort_recurse(arr *array, arr *additional_array, int number_of_strings, int *position)
{
	*position = 0;

	if(number_of_strings < 2)
	{
		return;
	}
	else if(number_of_strings == 2)
	{
		if(arr_compare_strings(array[0], array[1]) == 1)
		{
			arr_swap(&array[0], &array[1]);
		}
	}

	int mid = number_of_strings / 2;
	int first_posotion = 0;
	int second_position = 0;

	arr_merge_sort_recurse(array, additional_array, mid, &first_posotion);
	arr_merge_sort_recurse(array + mid, additional_array + mid, number_of_strings - mid, &second_position);

	if(first_posotion != second_position)							//Prepare for arr_merge. Both of answers must locate in same array
	{
		if(first_posotion == 0)
		{
			for(int i = mid; i < number_of_strings; i++)
			{
				array[i] = additional_array[i];
			}
		}
		else
		{
			for(int i = mid; i < number_of_strings; i++)
			{
				additional_array[i] = array[i];
			}
		}
	}

	if(first_posotion == 0)
	{
		arr_merge(array, mid, array + mid, number_of_strings - mid, additional_array);
		*position = 1;
	}
	else
	{
		arr_merge(additional_array, mid, additional_array + mid, number_of_strings - mid, array);
		*position = 0;
	}
}