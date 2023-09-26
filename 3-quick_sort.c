#include "sort.h"

void swap_ints(int *a, int *b);
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t size, int left, int right);
int lomuto_partition(int *array, size_t size, int left, int right);

/**
 * swap_ints - Switch two integers in the array
 * @a: 1st integer to be swapped
 * @b: 2nd integer to be swapped
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort - group an array of integers in ascending
 *              order using the quicksort algor
 * @array: the array of integers
 * @size: size of an array.
 *
 * Description: utilize the Lomuto partition scheme. returns
 *              the array after every change of two elements
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_partition - arranges a subset of an
 * array of the integers according to
 *                    the lomuto partition scheme
 * @array: an array of integers
 * @size: size of an array
 * @left: a starting index of the subset to order
 * @right: an ending index of the subset to order
 *
 * Return: final partition index
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - apply the quicksort algorithm through recursion
 * @array: the array of integers to be sorted
 * @size: The size of the array.
 * @left: starting index of the array partition to be ordered
 * @right: ending index of an array partition tobe ordered
 *
 * Description: Utilizes the Lomuto partition scheme
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

