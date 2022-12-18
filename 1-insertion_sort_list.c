#include "sort.h"
#include <stdio.h>

void insertion_sort_list(listint_t **list)
{
	listint_t **start_of_mess = list;

	/*
	 * start start_of_mess at the head,
	 * and keep inserting the node at that
	 * "index" into its place in the previous
	 * nodes
	 */
	while (*start_of_mess)
	{
		listint_t **prev = &(*start_of_mess)->prev;
		listint_t **next = &(*start_of_mess)->next;

		while (*prev && (*prev)->n > (*start_of_mess)->n)
		{
			swap_in_list(prev, start_of_mess);
			print_list(*list);

			prev = &(*start_of_mess)->prev;

			printf("*start_of_mess: %p, *prev: %p, *next: %p\n",
					(void *)*start_of_mess,
					(void *)*prev,
					(void *)*next);
		}

		start_of_mess = next;
	}
}

