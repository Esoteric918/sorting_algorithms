#include "sort.h"


void heapify(int *arr, size_t size)
{
	ssize_t strt = 0;

	strt = (size - 2) / 2;
	while (strt >= 0)
	{
		sift_down(arr, (size_t)strt, size - 1, size);
		if (strt)
			strt--;
		else
			break;
	}
}
/**
 * sift_down - sorts array
 * @arr: the input array
 * @strt: index start
 * @end: index end
 * @size: number of elements in array
 * Return: Nothing
 */
void sift_down(int *arr, size_t strt, size_t end, size_t size)
{
	size_t parent = 0, child = 0, swap = 0;

	parent = strt;
	while (2 * parent + 1 <= end)
	{
		child = 2 * parent + 1;
		swap = parent;
		if (arr[swap] < arr[child])
			swap = child;
		if (child + 1 <= end && arr[swap] < arr[child + 1])
			swap = child + 1;
		if (swap == parent)
			return;
		else if (parent != swap)
		{
			arr[parent] += arr[swap];
			arr[swap] = arr[parent] - arr[swap];
			arr[parent] -= arr[swap];
			print_array(arr, size);
			parent = swap;
		}
	}
}
/**
 * heap_sort
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t end = 0;

	if (size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end)
	{
		if (end)
		{
			array[0] += array[end];
			array[end] = array[0] - array[end];
			array[0] -= array[end];
			print_array(array, size);
		}
		end--;
		sift_down(array, 0, end, size);
	}
}
