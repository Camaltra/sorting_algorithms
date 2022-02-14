#include "sort.h"

/**
* mergeArray - Merge two sorted sub array into a sorted one
*
* @array: The parent array
* @arrayBuff: To contain the array before fill it
* @low: The lower index, as left elem of the sub array
* @middle: The middle of the sub array
* @high: The higher index, as right elem of the sub array
*
* Return: Anything, cause void function
*/
void mergeArray(int *array, int *arrayBuff, size_t low, size_t middle,
size_t high)
{
	size_t i = low, j = middle, k = low;

	printf("Merging...\n[left]: ");
	print_array(array + low, middle - low);

	printf("[right]: ");
	print_array(array + middle, high - middle);

	while (k < high)
	{
		if (i < middle && (j >= high || array[i] <= array[j]))
		{
			arrayBuff[k] = array[i];
			i++;
		}
		else
		{
			arrayBuff[k] = array[j];
			j++;
		}
		k++;
	}
	for (i = low; i < high; i++)
		array[i] = arrayBuff[i];

	printf("[Done]: ");
	print_array(array + low, high - low);
}

/**
* mergeSortRec - Recusive function to Divide and Conquer the array
*
* @array: The parent array
* @arrayBuff: To contain the array before fill it
* @low: The lower index, as left elem of the sub array
* @high: The higher index, as right elem of the sub array
*
* Return: Anything, cause void function
*/
void mergeSortRec(int *array, int *arrayBuff, size_t low, size_t high)
{
	size_t middle;

	if ((high - low) > 1)
	{
		middle = low + (high - low) / 2;
		mergeSortRec(array, arrayBuff, low, middle);
		mergeSortRec(array, arrayBuff, middle, high);
		mergeArray(array, arrayBuff, low, middle, high);
	}
}

/**
* merge_sort - Sort an array using the merge sort
* methode
*
* @array: The array to sort
* @size: The size of the array
*
* Return: Anything, cause void function
*/
void merge_sort(int *array, size_t size)
{
	int *arrayBuff;

	if (!array || size <= 1)
		return;

	arrayBuff = malloc(sizeof(int) * size);
	if (!arrayBuff)
		return;

	mergeSortRec(array, arrayBuff, 0, size);

	free(arrayBuff);
}
