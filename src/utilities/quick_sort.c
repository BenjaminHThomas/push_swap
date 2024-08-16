/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:57:09 by bthomas           #+#    #+#             */
/*   Updated: 2024/06/12 14:20:05 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= pivot && i <= high - 1)
			i++;
		while (arr[j] > pivot && j >= low + 1)
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[low], &arr[j]);
	return (j);
}

void	quicksort(int *arr, int low, int high)
{
	int	partition_idx;

	if (low < high)
	{
		partition_idx = partition(arr, low, high);
		quicksort(arr, low, partition_idx - 1);
		quicksort(arr, partition_idx + 1, high);
	}
}
