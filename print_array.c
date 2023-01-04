#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

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
