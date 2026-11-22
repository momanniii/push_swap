/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:03:08 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/09 11:25:07 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static void	copy_back(int *arr, int *temp, int left, int right)
{
	int	p;

	p = left;
	while (p <= right)
	{
		arr[p] = temp[p];
		p++;
	}
}

static void	merge_halves(int *arr, int *temp, t_merge_state *s, int right)
{
	while (s->i <= s->mid && s->j <= right)
	{
		if (arr[s->i] <= arr[s->j])
		{
			temp[s->k] = arr[s->i];
			s->i++;
		}
		else
		{
			temp[s->k] = arr[s->j];
			s->j++;
		}
		s->k++;
	}
}

static void	merge_remaining(int *arr, int *temp, t_merge_state *s, int right)
{
	while (s->i <= s->mid)
	{
		temp[s->k] = arr[s->i];
		s->i++;
		s->k++;
	}
	while (s->j <= right)
	{
		temp[s->k] = arr[s->j];
		s->j++;
		s->k++;
	}
}

static void	merge(int *arr, int *temp, int left, int right)
{
	t_merge_state	s;

	s.mid = left + (right - left) / 2;
	s.i = left;
	s.j = s.mid + 1;
	s.k = left;
	merge_halves(arr, temp, &s, right);
	merge_remaining(arr, temp, &s, right);
	copy_back(arr, temp, left, right);
}

void	merge_sort(int *arr, int *temp, int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	mid = left + (right - left) / 2;
	merge_sort(arr, temp, left, mid);
	merge_sort(arr, temp, mid + 1, right);
	merge(arr, temp, left, right);
}
