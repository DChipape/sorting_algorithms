#include "sort.h"

void swap_ints(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);

/**
 * swap_ints - change two integers in an array
 * @a: 1st  integer to swap.
 * @b: 2nd  integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort_hoare - Sort or order an array of integers in the ascending
 *                    order using the quicksort algor
 * @array: the array of integers
 * @size: size of the array
 *
 * Description:  employ the Hoare partition scheme. Prints
 * the array after eevery swap of two elements
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

/**
 * hoare_partition - arrange a subset of the array of integers
 *                   according to the hoare partition scheme
 * @array: an array of integers
 * @size: a size of the array
 * @left: The starting index of the subset to be ordered
 * @right: The ending index of the subset to be ordered
 *
 * Return: final partition index
 *
 * Description: Uses last element of the partition as a pivot
 * returns the array after every swap of two elements
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - apply the quicksort algorithm through the recursion
 * @array: the array of integers to be sorted
 * @size: a size of the array
 * @left: starting index of an array partition to be ordered
 * @right: ending index of an array partition to be ordered
 *
 * Description: Utilize the Hoare partition scheme
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

