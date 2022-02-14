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
* partition - Create a partion of the list, sort it using a pivot
*
* @arr: The array to sort
* @low: The idx of the first elem of the array
* @high: The last elem of the array
* @size: The global size of the array
*
* Return: Anything, cause void function
*/
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low, j = high - 1;

	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i >= j)
		{
			if (i != high)
			{
			swap(arr, high, i);
			print_array(arr, size);
			}
			break;
		}
		else if (i < j)
		{
			swap(arr, i, j);
			print_array(arr, size);
		}
	}
	return (j);

}

/**
* quickSort - Sort an array using Quick sort algo
*
* @arr: The array to sort
* @low: The idx of the first elem of the array
* @high: The last elem of the array
* @size: The global size of the array
*
* Return: Anything, cause void function
*/
void quickSort(int *arr, int low, int high, int size)
{
	int pi;

	if (high > low)
	{
		pi = partition(arr, low, high, size);

		quickSort(arr, low, pi, size);
		quickSort(arr, pi + 1, high, size);
	}
}

/**
* quick_sort_hoare - Land into the recursive function of quicksort
*
* @array: The array to sort
* @size: The size of the array
*
* Return: Anything, cause void function
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quickSort(array, 0, size - 1, size);
}
