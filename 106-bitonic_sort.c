
#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two elements in an array.
 * @array: The array containing the elements.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 */
void swap(int *array, int i, int j)
{
	if (array[i] != array[j])
	{
		array[i] ^= array[j];
		array[j] ^= array[i];
		array[i] ^= array[j];
	}
}

/**
 * bitonic_merge - Merge two halves of an array in a bitonic manner.
 * @array: The array to be merged.
 * @size: The size of the array.
 * @start: The starting index of the subarray.
 * @seq: The size of the subarray.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, int dir)
{
	size_t k, half;

	if (seq > 1)
	{
		half = seq / 2;
		for (k = start; k < start + half; k++)
		{
			if ((array[k] > array[k + half]) == dir)
				swap(array, k, k + half);

			printf("Merging [%lu/%lu] (%s):\n", seq, size, dir ? "UP" : "DOWN");
			print_array(array, size);
		}
		bitonic_merge(array, size, start, half, dir);
		bitonic_merge(array, size, start + half, half, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sort a bitonic sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @start: The starting index of the subarray.
 * @seq: The size of the subarray.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t size, size_t start, size_t seq,
		int dir)
{
	size_t half;

	if (seq > 1)
	{
		half = seq / 2;
		bitonic_sort_recursive(array, size, start, half, 1);
		bitonic_sort_recursive(array, size, start + half, half, 0);
		bitonic_merge(array, size, start, seq, dir);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 0, size, 1);
}
