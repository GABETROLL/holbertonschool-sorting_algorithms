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

/**
 * insertion_sort_list - Sorts the linked list
 * using the Insertion Sort algorithm,
 * using the 'swap_in_list' function above.
 *
 * @list: list to sort
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	/*
	 * the node that's currently being inserted,
	 * 2, in this example:
	 * (each line is one iteration)
	 * 3, 4, 5, 2
	 * 3, 4, 2, 5
	 * 3, 2, 4, 5
	 * 2, 3, 4, 5
	 * God loves you!
	 */
	listint_t **inserted_node = list;

	while (*inserted_node)
	{
		/*
		 * for inserting nodes with
		 * low values from the mess at high indexes
		 */
		listint_t **prev = &(*inserted_node)->prev;
		/* for going to the next node */
		listint_t **next = &(*inserted_node)->next;

		while (*prev && (*prev)->n > (*inserted_node)->n)
		{
			/*
			 * We have to keep track of the location of the
			 * inserted node itself, instead of the pointer's
			 * location, since we're supposed to follow the
			 * inserted node to the next swap iteration in this loop.
			 */
			listint_t *inserted_node_copy = *inserted_node;

			swap_in_list(prev, inserted_node);
			print_list(*list);

			prev = &(inserted_node_copy->prev);
			inserted_node = &inserted_node_copy;
		}
		inserted_node = next;
	}
}
