#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		prev = current->prev;

		while (prev != NULL && current->n < prev->n)
		{
			/* Swap current and prev nodes */
			if (next != NULL)
				next->prev = prev;
			prev->next = next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);

			/* Move current node backward */
			prev = current->prev;
		}

		current = next;
	}
}
