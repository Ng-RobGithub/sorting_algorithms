#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		sorted = current->prev;
		while (sorted != NULL && sorted->n > current->n)
		{
			/* Swap current and sorted nodes */
			temp = current->next;
			if (temp != NULL)
				temp->prev = sorted;
			sorted->next = temp;
			current->next = sorted;
			current->prev = sorted->prev;
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			sorted->prev = current;

			/* Update the list head if needed */
			if ((*list)->prev != NULL)
				*list = (*list)->prev;

			/* Print the list after each swap */
			print_list(*list);
			sorted = current->prev;
		}
		current = current->next;
	}
}
