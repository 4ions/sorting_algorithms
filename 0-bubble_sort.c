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
 *bubble_sort - Function that sorts an array in ascending order
 *@array: array to sort in ascending order
 *@size: number of elements to sort
 *
 *Return: No return value
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;/** O(1)*/

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)/** O(n)*/
	{
		for (j = 0; j < size - i - 1; j++)/** O(n*n)*/
		{
			/** Check if next number is greater*/
			if (array[j] > array[j + 1])/** O(n*n)*/
			{
				/** If number is greater, swap number*/
				swap(&array[j], &array[j + 1]);/** O(n*n)*/
				print_array(array, size);/** O(n*n)*/
				/** "check"  keep the loop going*/
			}
		}

	}
} /**  1 + 1 + n + n + n*n + n*n + n*n + n*n n*n + n +  n*/
/** = 5n^2 + 3n + 2 = O(n^2) */
