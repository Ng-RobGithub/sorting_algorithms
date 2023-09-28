#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/* Function prototypes */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* 0. Bubble sort algorithm */
void bubble_sort(int *array, size_t size);

/* 1. Insertion sort algorithm */
void insertion_sort_list(listint_t **list);

/* 2. Selection sort algorithm */
void selection_sort(int *array, size_t size);

/* 3. Quick sort algorithm */
void quick_sort(int *array, size_t size);

/* 4. Shell sort - Knuth Sequence */
void shell_sort(int *array, size_t size);

/* 5. Cocktail shaker sort */
void cocktail_sort_list(listint_t **list);

/* 6.Counting sort */
void counting_sort(int *array, size_t size);

/*7. Merge sort */
void merge_sort(int *array, size_t size);
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);

/* 8. Heap sort */
void heap_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void heapify(int *array, size_t size, size_t n, size_t root);

/* 9. Radix sort */
void radix_sort(int *array, size_t size);

/* 10. Bitonic sort */
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
/* 11. Quick Sort - Hoare Partition scheme */
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_quick_sort(int *array, size_t size, int left, int right);

/* 12. Dealer ( sort deck of cards) */
void sort_deck(deck_node_t **deck);

/* Print an array of integers */
void print_array(const int *array, size_t size);

/* Print a list of integers (used for linked list sorting) */
void print_list(const listint_t *list);

/* swap_nodes in a doubly linked list*/

/* find_max_value - Finds the maximum value in an array of integers. */
int find_max_value(int *array, size_t size);
int get_max(int *array, size_t size);

/* create_counting_array - Creates a counting array for counting sort. */
int *create_counting_array(int *array, size_t size, int max_value);

/* update_cumulative_counts - Updates the cumulative counts in the counting array. */
void update_cumulative_counts(int *counting_array, int max_value);

/* create_sorted_array - Creates a sorted array using the counting array. */
int *create_sorted_array(int *array, size_t size, int *counting_array);

/* copy_sorted_array - Copies the sorted array back to the original array. */
void copy_sorted_array(int *array, int *sorted_array, size_t size);

/* Data structures (if needed) */

/* Define any data structures here if required for your project. */

#endif /* SORT_H */
