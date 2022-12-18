#include "sort.h"

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

	for (; start_index < size; start_index++)
	{
		size_t index_of_smallest = start_index;
		size_t index = start_index;

		for (; index < size; index++)
		{
			if (array[index] < array[index_of_smallest])
				index_of_smallest = index;
		}

		swap_in_array(array, size, start_index, index_of_smallest);
		print_array(array, size);
	}
}

