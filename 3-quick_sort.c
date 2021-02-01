#include "sort.h"

/**
 *swap_double - swap two numbers
 *@array: array to sort
 *@size: size of the array
 *@a: number to swap
 *@b: number to swap
 *
 *Return: No return
 */

void swap_double(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int t = *a;
		*a = *b;
		*b = t;
		print_array((const int *)array, size);
	}
}

/**
 *partition - partition the array
 *@array: array to sort
 *@low: low of the array
 *@high: high of the array
 *@size: size of the array
 *
 *Return: No return
 */

int partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	int i, j;

	for (j = i = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_double(array, size, &array[j], &array[i++]);
		}
	}
	swap_double(array, size, &array[i], &array[high]);

	return (i);
}

/**
 *quick_sort_lomuto - sort a list
 *@array: array to sort
 *@low: low of the array
 *@high: high of the array
 *@size: size of the array
 *
 *Return: No return
 */

void quick_sort_lomuto(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{

		size_t pi = partition(array, low, high, size);

		quick_sort_lomuto(array, low, pi - 1, size);
		quick_sort_lomuto(array, pi + 1, high, size);
	}
}

/**
 *quick_sort - sort a list with quick_sort
 *@array: array to sort by quick_sort
 *@size: size of the array
 *
 *Return: No return
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quick_sort_lomuto(array, 0, size - 1, size);
}
