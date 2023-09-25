#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;
	int swapped;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		curr = *list;

		while (curr->next != NULL)
		{
			if (curr->n > curr->next->n)
			{
				/* Swap nodes */
				if (curr->prev != NULL)
					curr->prev->next = curr->next;
				else
					*list = curr->next;
				curr->next->prev = curr->prev;
				tmp = curr->next->next;
				curr->next->next = curr;
				curr->prev = curr->next;
				curr->next = tmp;
				if (tmp != NULL)
					tmp->prev = curr;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				curr = curr->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		curr = curr->prev;

		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				/* Swap nodes */
				if (curr->next != NULL)
					curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				tmp = curr->prev->prev;
				curr->prev->prev = curr;
				curr->next = curr->prev;
				curr->prev = tmp;
				if (tmp != NULL)
					tmp->next = curr;
				else
					*list = curr;
				swapped = 1;
				print_list(*list);
			}
			else
			{
				curr = curr->prev;
			}
		}
	} while (swapped);
}
