#include "sort.h"

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

