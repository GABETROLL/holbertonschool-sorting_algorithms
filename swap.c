#include "sort.h"

/**
 * swap - Tries to swap ints in array parameter
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
int swap(int *array, size_t size, size_t a, size_t b)
{
	int temp;

	if (a >= size || b >= size)
		return (1);

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;

	return (0);
}

