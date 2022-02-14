#include "deck.h"

/**
* swap - Swap node of a double linked list
*
* @current: The current node
* @prev: The previous node
* @list: The pointer to the linked list
*
* Return: Anything, cause void function
*/
void swap(deck_node_t *current, deck_node_t *prev, deck_node_t **list)
{
	deck_node_t *tmp;

	tmp = prev->prev;
	if (tmp)
		tmp->next = current;
	else
		*list = current;

	current->prev = tmp;

	prev->prev = current;
	prev->next = current->next;
	current->next = prev;
	if (prev->next)
		prev->next->prev = prev;
	else
		prev->next = NULL;
}

/**
* cardValue - Calcule the value of the card
*
* @node: The node that contain the card
*
* Return: The value of the card
*/
int cardValue(deck_node_t *node)
{
	char *deck[14] = {"Ace", "1", "2", "3", "4", "5", "6",
					"7", "8", "9", "10", "Jack", "Queen", "King"};
	int valueCard = 0;
	int i;

	for (i = 0; deck[i]; i++)
	{
		if (strcmp(node->card->value, deck[i]) == 0)
		{
			valueCard += i;
			break;
		}
	}
	if (strcmp(deck[i], "King") == 0 &&
		(node->card->kind == 1 || node->card->kind == 2))
		valueCard -= 1;
	return (valueCard + ((node->card->kind) * 13));
}

/**
* sort_deck - Sort a double linked list by comparing each
* elem with the previous
*
* @deck: The linked list to sort
*
* Return: Anything, cause void function
*/
void sort_deck(deck_node_t **deck)
{
	deck_node_t *browse = NULL;

	if (!deck || !*deck)
		return;

	browse = (*deck)->next;
	while (browse)
	{
		while (browse->prev && cardValue(browse->prev) > cardValue(browse))
			swap(browse, browse->prev, deck);
		browse = browse->next;
	}
}
