#include "sort.h"

/**
* swap - Swap two element of an array,
* the one given by the index, and the one after
*
* @array: The array to do some operation
* @idx1: The idx to swap
* @idx2: The idx to swap
*
* Return: Anything, cause void function
*/
void swap(int *array, int idx1, int idx2)
{
	int tmp;

	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
}

/**
* shell_sort - Sort an array using shell algorithm
*
* @array: Array to sort
* @size: Size of the array
*
* Return: Anything, cause void function
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i;
	int j, k;

	if (!array || size <= 1)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			k = array[i];
			j = i - gap;
			while (j >= 0 && k < array[j])
			{
				array[j + gap] = array[j];
				j -= gap;
			}
			array[j + gap] = k;
		}
		print_array(array, size);
		gap = gap / 3;
	}
}
