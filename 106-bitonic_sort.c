/*
 * File: 106-bitonic_sort.c
 */

#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);

/**
 * swap_ints - Swaps two integers in the array
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
 * bitonic_merge - arrange a bitonic sequence inside the array of integers
 * @array: the array of integers.
 * @size: size of the array
 * @start: starting index of a sequence in array to sort.
 * @seq: size of the sequence to be sorted
 * @flow: a direction to be sort in
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - transform an array ofthe integers into a bitonic sequence
 * @array: the array of integers
 * @size: size of an array
 * @start: starting index of a block of the building bitonic sequence
 * @seq: size of a block of building bitonic sequence
 * @flow: a direction to sort bitonic sequence block in
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort -arrange an array ofthe integers in ascending
 *                order using the bitonic sort algor
 * @array:the  array of integers
 * @size: size of the array
 *
 * Description: returns the array after every swap. Only works for
 * size = 2^k where k >= 0
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}

