#include "sort.h"

/**
 *swap - swap number in array
 *@xp: number of array
 *@yp: number of array
 *
 *Return: No return
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 *selection_sort - sort array by number of elements in array
 *@array: array to sort
 *@size: size of array
 *
 *Return: No return
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, num;


	for (i = 0; i < size - 1; i++)
	{
		num = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[num])
			{
				num = j;
			}
		}
		if (num != i)
		{
			swap(&array[i], &array[num]);
			print_array(array, size);
		}
	}
}
