void quicksort(arr *array, int last)
{
	int l = 0;
	int r = last;
	arr opornel = array[r / 2];
	while(l <= r)
	{
		while(compareStrings(array[l], opornel) == -1)
		{
			l++;
		}
		while(compareStrings(array[r], opornel) == 1)
		{
			r--;
		}
		if(l <= r)
		{
			swap(&array[l++], &array[r--]);
		}
	}
	if(r > 0)
	{
		quicksort(array, r);
	}
	if(l > last)
	{
		quicksort(array + l, last - l);
	}
}