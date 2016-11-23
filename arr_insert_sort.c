#include <stdio.h>
#include <stdlib.h>
#include "arr_insert_sort.h"
#include "arr_compare_strings.h"

void arr_insert_sort(arr *array, int number_of_strings)
{
	int i = 0;
	arr x;
	int j = 0;

	for(i = 1; i < number_of_strings; i++)
	{
		x = array[i];
		j = i - 1;
		while((j > -1) && (arr_compare_strings(array[j], x) == 1))
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = x;
	}
}