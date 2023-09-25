#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max = 0;
	size_t i;
	int *counting_array, *output_array;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array of size (max + 1) */
	counting_array = malloc(sizeof(int) * (max + 1));
	if (counting_array == NULL)
		return;

	/* Initialize the counting array with zeros */
	for (i = 0; i <= (size_t)max; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each element in the original array */
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	/* Update the counting array to store the cumulative count */
	for (i = 1; i <= (size_t)max; i++)
		counting_array[i] += counting_array[i - 1];

	/* Create the output array and place elements in their sorted order */
	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	/* Print the counting array (optional) */
	printf("Counting array:");
	for (i = 0; i <= (size_t)max; i++)
		printf(" %d", counting_array[i]);
	printf("\n");

	/* Free dynamically allocated memory */
	free(counting_array);
	free(output_array);
}
