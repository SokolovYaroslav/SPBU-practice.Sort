#include <stdio.h>
#include <stdlib.h>
#include "arr_swap.h"

void arr_swap(arr *a,arr *b)
{
	arr tmp = *a;
	*a = *b;
	*b = tmp;
}