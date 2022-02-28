#include "sort.h"

/**
 * getMax - Function to get the largest element from an array
 * @arr: array
 * @n: size of array
 *
 * Return: int
 */

int getMax(int arr[], int n)
{
	int i;
	int max = arr[0];

	for (i = 1; i < n ; ++i)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
 * countingSort - sorts the arr in LSD
 *@array: array to be sorted
 *@size: size of the array
 *@lsd: least signifcant digit
 *@buff: a buffer to store sorted array
 */

void countingSort(int *array, size_t size, int *buff, int lsd)
{
	int arrCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t idx;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (idx = 0; idx < size; idx++)
	{
		arrCount[(array[idx] / lsd) % 10]++;
	}
	for (idx = 1; idx < 10; idx++)
	{
		arrCount[idx] += arrCount[idx - 1];
	}
	for (idx = size - 1; (int)idx >= 0; idx--)
	{
		buff[arrCount[(array[idx] / lsd) % 10] - 1] = array[idx];
		arrCount[(array[idx] / lsd) % 10]--;
	}

	for (idx = 0; idx < size; ++idx)
		array[idx] = buff[idx];
}


/**
 * radix_sort - sorts an array
 *
 * @array: the arr to be sorted
 * @size: the size of the arr
 *
 * Returns: a sorted array
 */

void radix_sort(int *array, size_t size)
{
	int max, *temp, lsd;

	if (array == NULL || size < 2)
	{
		return;
	}

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	max = getMax(array, size);
	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		countingSort(array, size, temp, lsd);
		print_array(array, size);
	}
	free(temp);
}
