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
/*
 * (it's here because the 'swap.c' file wouldn't be compiled
 * by the Holberton test)
 */

/**
 * bubble_sort - Bubble sort algorithm
 * that sorts array parameter 'array' of
 * size 'size'
 *
 * @array: array to sort with Bubble sort
 * @size: size of array
 *
 * (WRONG SIZE LEADS TO UNDEFINED BEHAVIOR)
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t end = size - 1;

	for (; end; end--)
	{
		size_t index = 0;
		/*
		 * true until we find out
		 * two ints are out of order
		 */
		int all_sorted = 1;

		for (; index < end; index++)
		{
			if (array[index] > array[index + 1])
			{
				all_sorted = 0;

				swap_in_array(array, size, index, index + 1);
				print_array(array, size);
			}
		}

		if (all_sorted)
			break;
	}
}

