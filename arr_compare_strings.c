#include <stdio.h>
#include <stdlib.h>
#include "arr_compare_strings.h"

int arr_compare_strings(arr a, arr b)
{
	int i = 0;

	while((a[i] != '\0') && (b[i] != '\0'))
	{
		if(a[i] > b[i])
		{
			return 1;
		}
		else if (a[i] < b[i])
		{
			return -1;
		}
		i++;
	}

	if(a[i] == '\0')
	{
		if(b[i] == '\0')
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
}