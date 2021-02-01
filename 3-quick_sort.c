#include "sort.h"

void swap_double(int *array, size_t size, int *a, int *b)
{
	int t = *a; 
    	*a = *b; 
    	*b = t; 
	print_array((const int *)array, size);

}

int partition(int *array, ssize_t low, ssize_t high, size_t size) 
{ 
    int pivot = array[high];    // pivot 
    int i, j;  // Index of smaller element 
  
    for (j = i= low; j < high; j++) 
    { 
        // If current element is smaller than the pivot 
        if (array[j] < pivot) 
        { 
                // increment index of smaller element 
            swap_double(array, size, &array[j], &array[i++]);
        } 
    } 
    swap_double(array, size, &array[i], &array[high]); 
    
    return (i); 
} 

void quick_sort_lomuto(int *array, ssize_t low, ssize_t high, size_t size) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        size_t pi = partition(array, low, high, size); 
  
        // Separately sort elements before 
        // partition and after partition 
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