/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_normalization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:03:13 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/09 11:24:51 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	binary_search(int *sorted, int size, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (sorted[mid] == value)
			return (mid);
		else if (sorted[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	assign_index(t_list *a, int *sorted, int size)
{
	t_list	*current;

	current = a;
	while (current)
	{
		current->index = binary_search(sorted, size, current->content);
		current = current->next;
	}
}

int	normalize_stack(t_list *a)
{
	int	*sorted;
	int	*temp;
	int	size;

	if (!a)
		return (1);
	size = ft_lstsize(a);
	sorted = arr(a);
	if (!sorted)
		return (0);
	temp = malloc(sizeof(int) * size);
	if (!temp)
	{
		free(sorted);
		return (0);
	}
	merge_sort(sorted, temp, 0, size - 1);
	assign_index(a, sorted, size);
	free(sorted);
	free(temp);
	return (1);
}
