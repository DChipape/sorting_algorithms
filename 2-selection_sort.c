#include "sort.h"

/**
 * swap_ints - change two integers in the array
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - arrange the array of integers in ascending order
 *                  using the selection sort algor
 * @array: the array of integers
 * @size: size of an array
 *
 * Description: returns the array after every swap
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}

