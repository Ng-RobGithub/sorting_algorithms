#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merge two sub-arrays into a single sorted array.
 * @array: Pointer to the original array.
 * @left: Pointer to the left sub-array.
 * @left_size: Number of elements in the left sub-array.
 * @right: Pointer to the right sub-array.
 * @right_size: Number of elements in the right sub-array.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k++] = left[i++];
		} else
		{
			array[k++] = right[j++];
		}
	}

	while (i < left_size)
	{
		array[k++] = left[i++];
	}

	while (j < right_size)
	{
		array[k++] = right[j++];
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	if (size <= 1)
	{
		return; /* Base case: already sorted */
	}

	size_t mid;

	mid = size / 2;
	int *left = malloc(mid * sizeof(int));
	int *right = malloc((size - mid) * sizeof(int));

	if (left == NULL || right == NULL)
	{
		/* Handle memory allocation failure */
		if (left != NULL)
		{
			free(left);
		}
		if (right != NULL)
		{
			free(right);
		}
		return;
	}
	/* Copy data to left and right arrays */
	for (size_t i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}
	for (size_t i = mid; i < size; i++)
	{
		right[i - mid] = array[i];
	}
	/* Recursively sort left and right arrays */
	merge_sort(left, mid);
	merge_sort(right, size - mid);

	/* Merge sorted arrays back into the original array */
	merge(array, left, mid, right, size - mid);

	/* Free dynamically allocated memory */
	free(left);
	free(right);
}
