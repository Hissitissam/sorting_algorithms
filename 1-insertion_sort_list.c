#include "sort.h"

/**
 * swap_n - Swap two nodes in a  doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @first_n: A pointer to the first node to swap.
 * @second_n: The second node to swap.
 */

void swap_n(listint_t **head, listint_t **first_n, listint_t *second_n)
{
	(*first_n)->next = second_n->next;
	if (second_n->next != NULL)
		second_n->next->prev = *first_n;
	second_n->prev = (*first_n)->prev;
	second_n->next = *first_n;
	if ((*first_n)->prev != NULL)
		(*first_n)->prev->next = second_n;
	else
		*head = second_n;
	(*first_n)->prev = second_n;
	*first_n = second_n->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_n(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
