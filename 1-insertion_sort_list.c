#include "sort.h"
#include <stdio.h>

/**
 * swap_in_list - Swaps nodes '**node_a_pp'
 * with '**node_n_pp' in this project's doubly
 * linked list type,
 *
 * ASSUMING THAT NODE A IS ONE NODE CLOSER TO THE HEAD
 * THAN NODE B; THAT NODE A COMES BEFORE NODE B.
 *
 * The following code should do
 * something like this this:
 *
 * (HIGHER INDEXES ARE ALSO DISPLAYED HIGHER HERE)
 *
 * next_p?         = &{3, node_b_p, ?}
 * node_b_p        = &{2, node_a_p, next_p}
 * node_a_p        = &{1, prev_p,   node_b_p}
 * prev_p?         = &{0, ?,        node_a_p}
 *
 * (swap occurs)
 *
 * next_p?         = &{3, node_a_p, ?}
 * node_b_p        = &{2, prev_p,   node_a_p}
 * node_a_p        = &{1, node_b_p, next_p}
 * prev_p?         = &{0, ?,        node_b_p}
 *
 * which is equivalent to:
 *
 * next_p?         = &{3, node_a_p, ?}
 * node_a_p        = &{1, node_b_p, next_p}
 * node_b_p        = &{2, prev_p,   node_a_p}
 * prev_p?         = &{0, ?,        node_b_p}
 *
 * (Assuming that the names are pointers to
 * structs in the heap)
 *
 * We also don't know if the next_p and prev_p
 * pointers aren't NULL, so changing those
 * pointers is inside two if statements below.
 *
 * @node_a_pp: node WITH LOWER INDEX IN LIST
 * @node_b_pp: node WITH HIGHER INDEX IN LIST
 *
 * Return: nothing
 */
void swap_in_list(listint_t **node_a_pp, listint_t **node_b_pp)
{
	/* to ACCESS the NODES THEMSELVES in the heap */
	listint_t *prev_p = (*node_a_pp)->prev;
	listint_t *node_a_p = *node_a_pp;
	listint_t *node_b_p = *node_b_pp;
	listint_t *next_p = (*node_b_pp)->next;

	/* swap pointers */
	if (next_p)
		next_p->prev = node_a_p;
	node_b_p->next = node_a_p;
	node_b_p->prev = prev_p;
	node_a_p->next = next_p;
	node_a_p->prev = node_b_p;
	if (prev_p)
		prev_p->next = node_b_p;
}
/*
 * (it's here because Holerton's test
 * wouldn't compile 'swap.c')
 */

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

