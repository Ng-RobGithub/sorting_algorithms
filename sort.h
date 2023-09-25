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

/* 8. Heap sort */
void heap_sort(int *array, size_t size);

/* 9. Radix sort */
void radix_sort(int *array, size_t size);

/* 10. Bitonic sort */
void bitonic_sort(int *array, size_t size);

/* 11. Quick Sort - Hoare Partition scheme */
void quick_sort_hoare(int *array, size_t size);

/* 12. Dealer ( sort deck of cards) */
void sort_deck(deck_node_t **deck);

/* Print an array of integers */
void print_array(const int *array, size_t size);

/* Print a list of integers (used for linked list sorting) */
void print_list(const listint_t *list);

/* swap_nodes in a doubly linked list*/

/* Data structures (if needed) */

/* Define any data structures here if required for your project. */

#endif /* SORT_H */
