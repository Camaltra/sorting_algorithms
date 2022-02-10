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
void swap(listint_t *current, listint_t *prev, listint_t **list)
{
    listint_t *tmp;

    tmp = prev->prev;
    if (tmp)
        tmp->next = current;
    else
        *list = current;

    current->prev = tmp;

    prev->prev = current;
    prev->next = current->next;
    current->next = prev;
    if(prev->next != NULL)
        prev->next->prev = prev;
    else
        prev->next = NULL;
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
void insertion_sort_list(listint_t **list)
{
    listint_t *browse = NULL;

    if (!list || !*list)
        return;

    browse = (*list)->next;
    while (browse)
    {
        while (browse->prev && browse->prev->n > browse->n)
        {
            swap(browse, browse->prev, list);
            print_list(*list);
        }
        browse = browse->next;
    }
}

