void insertsort(arr *array, int n)
{
	int i = 0;
	arr x;
	int j = 0;

	for(i = 1; i < n; i++)
	{
		x = array[i];
		j = i - 1;
		while((j > -1) && (compareStrings(array[j], x) == 1))
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = x;
	}
}