#include "sort.h"

/**
 * swap_in_array - Tries to swap ints in array parameter
 * 'array' that contains parameter 'size' ints.
 *
 * If the indexes are valid, it tries swapping
 * and returns EXIT_SUCCESS if successful.
 *
 * If the indexes aren't valid, return EXIT_FAILURE.
 *
 * If the array is somehow not as big as 'size' says,
 * undefined behaviour happens.
 *
 * @array: array to swap two ints in
 * @size: size of the array measured in ints
 * @a: index of int in array 'array' to swap
 * with int in array 'array' at index 'b'
 * @b: index of int in array 'array' to swap
 * with int in array 'array' at index 'a'
 *
 * Return: EXIT_SUCCESS if indexes are valid,
 * EXIT_FAILURE otherwise
 */
int swap_in_array(int *array, size_t size, size_t a, size_t b)
{
	int temp;

	if (a >= size || b >= size)
		return (1);

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;

	return (0);
}

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
