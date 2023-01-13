#include "sort.h"
#include <limits.h>

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
/*
 * it was copied here from 'swap.c'
 * to pass the Holberton checks
 */

/**
 * selection_sort - Uses selection sort to
 * sort the int array 'array' of size_t
 * 'size'.
 *
 * 'size' MUST BE THE ACTUAL SIZE OF THE ARRAY.
 *
 * @array: array to sort with selection sort
 * @size: size of array 'array'
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t start_index = 0;

	if (!array)
		return;

	for (; start_index < size; start_index++)
	{
		size_t index_of_smallest = start_index;
		size_t index = start_index;

		int sorted = 1;

		for (; index < size; index++)
		{
			/*
			 * all it takes is two wrong items to have
			 * to start in the next round
			 */
			if (index > 0 && array[index - 1] > array[index])
				sorted = 0;

			if (array[index] < array[index_of_smallest])
				index_of_smallest = index;
		}
		swap_in_array(array, size, start_index, index_of_smallest);
		print_array(array, size);

		/*
		 * all of the items were in order,
		 * we're off work early
		 */
		if (sorted)
			return;
	}
}

