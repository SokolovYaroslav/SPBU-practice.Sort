#include <stdio.h>
#include <stdlib.h>
#include "swap.h"

void swap(arr *a,arr *b)
{
	arr tmp = *a;
	*a = *b;
	*b = tmp;
}