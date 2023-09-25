#include "sort.h"

void swap_ints(int *a, int *b);
void heapify(int *array, size_t size, size_t index);
void heap_sort(int *array, size_t size);


/**
 * swap - Swap two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - Rearranges the elements of an array into a max-heap.
 * @array: The input array.
 * @size: The size of the heap.
 * @index: The index to start the heapify process from.
 */
void heapify(int *array, size_t size, size_t index)
{
	size_t largest, left, right;

	largest = index;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 * @array: The input array.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0);
	}
}
