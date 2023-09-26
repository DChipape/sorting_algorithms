#include "sort.h"

/**
 * swap_nodes - Swap the two nodes in a listint_t doubly-linked list
 * @h: the pointer to a doubly-linked list head
 * @n1: A pointer to swap to a first node
 * @n2: another node to swap
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts or order the integers of
 * a doubly linked list
 *                       using the insertion sort algorithm
 * @list: A pointer that points to the head of a
 * doubly-linked list of the integers
 *
 * Description: return a list after every swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

