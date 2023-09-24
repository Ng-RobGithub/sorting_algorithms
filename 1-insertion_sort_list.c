#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort
 * @list: A pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* Swap current and current->prev nodes */
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;

			if (current->prev == NULL)
				*list = current;

			if (current->next->next != NULL)
				current->next->next->prev = current->next;
			print_list(*list);
		}

		current = temp;
	}
}
