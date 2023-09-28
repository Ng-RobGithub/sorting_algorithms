#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 * according to the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	above = left - 1;
	below = right + 1;

	while (1)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above >= below)
			return (below);

		swap_ints(array + above, array + below);
		print_array(array, size);
	}
}

/**
 * hoare_quick_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_quick_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int part;

		part = hoare_partition(array, size, left, right);
		hoare_quick_sort(array, size, left, part);
		hoare_quick_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quick_sort(array, size, 0, size - 1);
}
