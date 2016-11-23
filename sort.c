#include <stdio.h>
#include <stdlib.h>
#include "arr_get_array.h"
#include "arr_bubble_sort.h"
#include "arr_insert_sort.h"
#include "arr_quick_sort.h"
#include "arr_merge_sort.h"

typedef char* arr;

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Invalid arguments\n");
		return 0;
	}
	int number_of_strings = atoi(argv[1]);
	int i = 0;

	arr *main_array = arr_get_array(number_of_strings, argv[2]);
	if(!main_array)
	{
		return 0;
	}

	/*arr_bubble_sort(main_array, number_of_strings);*/
	/*arr_insert_sort(main_array, number_of_strings);*/
	if(number_of_strings < 16000)
	{
		if(!arr_merge_sort(main_array, number_of_strings))
		{
			return 0;
		}
	}
	else
	{
		arr_quick_sort(main_array, number_of_strings - 1);
	}

	for(i = 0; i < number_of_strings; i++)
	{
		printf("%s\n", main_array[i]);
		free(main_array[i]);
	}
	
	free(main_array);

	return 1;
}