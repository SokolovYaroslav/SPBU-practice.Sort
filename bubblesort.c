void bubblesort(arr *array, int n)
{
	int i;
	int j;
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(compareStrings(array[j], array[j + 1]) == 1)
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}