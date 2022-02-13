#include "sort.h"

/**
 * shell_sort - Sort an array with the Knuth sequence
 *
 * @array: The array to sort
 * @size: lenght of the array
 *
 * Return: Anything, cause void function
 */

void shell_sort(int *array, size_t size)
{
	int j, k;
	size_t i;
	size_t incr = 1;

	if (!array || size <= 1)
		return;

	while (incr <= (size - 1) / 9)
		incr = 3 * incr + 1;

	while (incr >= 1)
	{
		for (i = incr; i < size; i++)
		{
			k = array[i];
			for (j = i - incr; j >= 0 && k < array[j]; j = j - incr)
				array[j + incr] = array[j];
			array[j + incr] = k;
		}
		print_array(array, size);
		incr = incr / 3;
	}
}
