#include "sort.h"

/**
 * selection_sort - Sort an array by comparing each
 * elem witch the row of the array
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
