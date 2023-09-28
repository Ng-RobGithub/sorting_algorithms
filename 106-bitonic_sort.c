#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Merge two halves of an array in ascending or descending
 * order.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int flow)
{
	size_t i,  jump;

	if (seq > 1)
	{
		jump = seq / 2;
		for (i = start; i < start + jump; i++)
		{
			if ((array[i] > array[i + jump]) == flow)
				swap(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sort_recursive - Recursive Bitonic Sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @asc: Flag to indicate sorting in ascending order (1 for ascending,
 * 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t size, int asc)
{
	size_t half;

	if (size > 1)
	{
		half = size / 2;
		bitonic_sort_recursive(array, half, 1);
		bitonic_sort_recursive(array + half, half, 0);
		bitonic_merge(array, size, 0, size, asc);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1);
}
