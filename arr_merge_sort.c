#include <stdio.h>
#include <stdlib.h>
#include "arr_merge_sort.h"
#include "arr_merge_sort_recurse.h"

int arr_merge_sort(arr *array, int number_of_strings)
{
	if(number_of_strings < 2)
	{
		return 1;
	}

	int position = 0;								//If position == 0, then sorted array located in array, else in additional_array
	int i = 0;
	arr *additional_array = (arr*)malloc(sizeof(arr) * number_of_strings);
	if(!additional_array)
	{
		printf("Can't malloc additional array in arr_merge_sort\n");
		return 0;
	}

	arr_merge_sort_recurse(array, additional_array, number_of_strings, &position);

	if(position == 1)								//We want move answer in array
	{
		for(i = 0; i < number_of_strings; i++)
		{
			array[i] = additional_array[i];
		}
	}
	free(additional_array);
}