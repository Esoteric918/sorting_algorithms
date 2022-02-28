#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
ssize_t _partition(int *arr, ssize_t f, ssize_t l, size_t size);
void _qsort(int *arr, ssize_t f, ssize_t l, size_t size);
void merge_sort(int *array, size_t size);
void top_dwn_mrg_srt(int *arr, int *out_arr, size_t size);
void top_dwn_split_mrg(int *out_arr, size_t strt, size_t end, int *arr);
void top_dwn_mrg(int *arr, size_t strt, size_t mid, size_t end, int *out_arr);
void copy_array(int *arr, size_t strt, size_t end, int *out_arr);
void merge_up(int *arr, int n);
void merge_down(int *arr, int n);
void heap_sort(int *array, size_t size);
void sift_down(int *arr, size_t strt, size_t end, size_t size);
void heapify(int *arr, size_t size);
void radix_sort(int *array, size_t size);
void countingSort(int *array, size_t size, int *buff, int lsd);


#endif /* SORT_H */
