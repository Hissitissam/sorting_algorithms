#include "sort.h"

/**
 * swap_i - Swap two integers in an array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */

void swap_i(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Prints the array after each time swap.
 */

void selection_sort(int *array, size_t size)
{
	int *minim;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minim = array + i;
		for (j = i + 1; j < size; j++)
			minim = (array[j] < *minim) ? (array + j) : minim;

		if ((array + i) != minim)
		{
			swap_i(array + i, minim);
			print_array(array, size);
		}
	}
}

