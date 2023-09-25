#include "sort.h"

/**
 * print_counting_array - Prints the counting array.
 * @counting_array: The counting array.
 * @max_value: The maximum value in the original array.
 */
void print_counting_array(int *counting_array, int max_value)
{
	/* Implementation of printing the counting array */
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max_value;
	int *counting_array;
	int *sorted_array;

	if (array == NULL || size < 2)
		return;

	if (array == NULL || size < 2)
		return;

	max_value = find_max_value(array, size);
	*counting_array = create_counting_array(array, size, max_value);

	if (counting_array == NULL)
		return;

	update_cumulative_counts(counting_array, max_value);
	*sorted_array = create_sorted_array(array, size, counting_array);

	if (sorted_array == NULL)
	{
		free(counting_array);
		return;
	}

	copy_sorted_array(array, sorted_array, size);
	print_counting_array(counting_array, max_value);

	free(counting_array);
	free(sorted_array);
}
