#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in the array
 * Return: Index of the pivot element after partitioning
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int temp;
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the Quick sort algorithm
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		size_t pivot = lomuto_partition(array, low, high, size);

		if (pivot != 0)
			quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
