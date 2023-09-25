#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max, min;
	size_t i, range;
	int *counting_array, *output_array;

	if (array == NULL || size < 2)
		return;

	max = min = array[0];

	/* Find the minimum and maximum values in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}

	/* Calculate the range of values */
	range = max - min + 1;

	/* Allocate memory for the counting array */
	counting_array = malloc(range * sizeof(int));
	if (counting_array == NULL)
		return;

	/* Initialize the counting array with zeros */
	for (i = 0; i < range; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each value in the array */
	for (i = 0; i < size; i++)
		counting_array[array[i] - min]++;

	/* Update the counting array with cumulative counts */
	for (i = 1; i < range; i++)
		counting_array[i] += counting_array[i - 1];

	/* Allocate memory for the output array */
	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}

	/* Build the output array using the counting array */
	for (i = size - 1; i < (size_t)-1; i--)
	{
		output_array[counting_array[array[i] - min] - 1] = array[i];
		counting_array[array[i] - min]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	/* Print the counting array (optional) */
	print_array(counting_array, range);

	/* Free dynamically allocated memory */
	free(counting_array);
	free(output_array);
}
