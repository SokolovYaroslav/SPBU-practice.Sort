#include <stdio.h>
#include <stdlib.h>
#include "arr_quick_sort.h"
#include "arr_swap.h"
#include "arr_compare_strings.h"

void arr_quick_sort(arr *array, int last)
{
	int l = 0;
	int r = last;
	arr opornel = array[r / 2];

	while(l <= r)
	{
		while(arr_compare_strings(array[l], opornel) == -1)
		{
			l++;
		}
		while(arr_compare_strings(array[r], opornel) == 1)
		{
			r--;
		}
		if(l <= r)
		{
			arr_swap(&array[l++], &array[r--]);
		}
	}
	
	if(r > 0)
	{
		arr_quick_sort(array, r);
	}
	if(l < last)
	{
		arr_quick_sort(array + l, last - l);
	}
}