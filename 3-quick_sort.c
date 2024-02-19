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
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: array of integers.
 * @size: size of the array.
 * @l: starting index of the subset to order.
 * @r: ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int l, int r)
{
	int *pivot, above, below;

	pivot = array + r;
	for (above = below = l; below < r; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_i(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_i(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @l: starting index of the array partition to order.
 * @r: ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int l, int r)
{
	int part;

	if (r - l > 0)
	{
		part = lomuto_partition(array, size, l, r);
		lomuto_sort(array, size, l, part - 1);
		lomuto_sort(array, size, part + 1, r);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

