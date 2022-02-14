#include "sort.h"

/**
* searchMax - Search the max of an array
*
* @array: The given array
* @size: The size
*
* Return: The max
*/
int searchMax(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
* memInit - Init the memory of the array;
* fill all the value to 0
*
* @array: The given array
* @size: The size of the array
*
* Return: Anything, cause void function
*/
void memInit(int *array, size_t size)
{
	size_t i;

	for (i = 0; i <= size; i++)
		array[i] = 0;
}

/**
* counting_sort - Sort an array using the counting sort
* methode
*
* @array: The array to sort
* @size: The size of the array
*
* Return: Anything, cause void function
*/
void counting_sort(int *array, size_t size)
{
	size_t max = array[0], i;
	int *arrayCounter = NULL, *output;

	max = searchMax(array, size);
	output = malloc(sizeof(int) * size);
	arrayCounter = malloc(sizeof(int) * max + 1);
	if (!arrayCounter || !output)
		return;
	memInit(arrayCounter, max);

	for (i = 0; i < size; i++)
		arrayCounter[array[i]]++;

	for (i = 1; i <= max; i++)
		arrayCounter[i] += arrayCounter[i - 1];

	print_array(arrayCounter, max + 1);

	for (i = size - 1; (int)i >= 0; i++)
	{
		output[arrayCounter[array[i]] - 1] = array[i];
		arrayCounter[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(arrayCounter);
}
