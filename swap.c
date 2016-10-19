void swap(arr *a,arr *b)
{
	arr tmp = *a;
	*a = *b;
	*b = tmp;
}