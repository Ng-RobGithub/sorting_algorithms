#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of non-negative integers
 * using the Counting sort algorithm. It assumes that the input array
 * contains only non-negative numbers.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *sorted_array;
	int max_value = 0, i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the input array */
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Create a counting array of size (max_value + 1) and initialize to 0 */
	counting_array = malloc(sizeof(int) * (max_value + 1));
	if (counting_array == NULL)
		return;

	for (i = 0; i <= max_value; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each element in the input array */
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]]++;

	/* Update the counting array to store the cumulative counts */
	for (i = 1; i <= max_value; i++)
		counting_array[i] += counting_array[i - 1];

	/* Create a sorted array using the counting array */
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(counting_array);
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		sorted_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	/* Print the counting array as per the requirement */
	printf("Array after counting:\n");
	print_array(counting_array, max_value + 1);

	/* Free dynamically allocated memory */
	free(counting_array);
	free(sorted_array);
}
