#include <stdio.h>
#include <stdlib.h>
#include "arr_get_array.h"

array arr_get_array(int number_of_strings, char *file_name)
{
	int i = 0;
	array main_array;

	FILE * input_data;
	input_data = fopen(file_name, "r");
	if(input_data == NULL)
	{
		printf("Can't open input file\n");
		main_array = NULL;
		return main_array;
	}

	if(number_of_strings <= 0)
	{
		printf("Invalid input number of strings\n");
		fclose(input_data);
		main_array = NULL;
		return main_array;
	}
	//Massive with lenghs of strings
	int *lenght_of_strings;
	lenght_of_strings = (int*)malloc(sizeof(int) * (number_of_strings + 2));
	if(!lenght_of_strings)
	{
		printf("Can't malloc lenght_of_strings");
		fclose(input_data);
		main_array = NULL;
		return main_array;
	}
	//Count lenghs of strings
	int c = 0;	
	lenght_of_strings[0] = 0;				
	while((c = fgetc(input_data)) != EOF)
	{
		if(i < number_of_strings)
		{
			if(c != '\n')
			{
				lenght_of_strings[i]++;
			}
			else
			{
				i++;
				lenght_of_strings[i] = 0;
			}
		}
		else
		{
			printf("Invalid input number of strings\n");
			fclose(input_data);
			main_array = NULL;
			return main_array;
		}
	}
	if(ferror(input_data))
	{
		printf("An error occurred while reading the file\n");
		fclose(input_data);
		main_array = NULL;
		return main_array;
	}
	if(i < number_of_strings)
	{
		printf("Invalid input number of strings\n");
		fclose(input_data);
		main_array = NULL;
		return main_array;
	}
	
	rewind(input_data);
								
	main_array = (arr*)malloc(sizeof(arr) * number_of_strings);
	if(!main_array)
	{
		printf("Invalid input number of strings\n");
		fclose(input_data);
		main_array = NULL;
		return main_array;
	}
	int k = 0;
	for(i = 0; i != number_of_strings; ++i)
	{
		k = 0;
		main_array[i] = (arr)malloc(lenght_of_strings[i] + 1);
		if(!main_array[i])
		{
			printf("Can't malloc main_array[i]\n");
			fclose(input_data);
			main_array = NULL;
			return main_array;
		}
		while(((c = fgetc(input_data)) != '\n') && (c != EOF))
		{
			main_array[i][k] = c;
			k++;
		}
		if(ferror(input_data))
		{
			printf("An error occurred while reading the file\n");
			fclose(input_data);
			main_array = NULL;
			return main_array;
		}
		main_array[i][k] = '\0';
	}
	free(lenght_of_strings);
	fclose(input_data);

	return main_array;
}