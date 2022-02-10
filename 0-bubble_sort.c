#include "sort.h"

/**
* swap - Swap two element of an array,
* the one given by the index, and the one after
*
* @array: The array to do some operation
* @idx: The idx to swap
*
* Return: Anything, cause void function
*/
void swap(int *array, int idx)
{
    int tmp;

    tmp = array[idx];
    array[idx] = array[idx + 1];
    array[idx + 1] = tmp;
}

/**
* bubble_sort - Sort a given array by using the bubble
* sorting algo | Print each time the array, after sorting
*
* @array: The array to sort
* @size: The size of the array
*
* Return: Anything, cause void function
*/
void bubble_sort(int *array, size_t size)
{
    int i, j, sorted;

    for (i = size - 1; i > 0; i--)
    {
        sorted = 1;
        for (j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array, j);
                sorted = 0;
                print_array(array, size);
            }
        }
        if (sorted)
            break;
    }
}

