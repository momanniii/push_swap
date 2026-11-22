/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_strategy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 21:48:49 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/04 19:28:42 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	push_chunks(t_list **stack_a, t_list **stack_b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= pushed)
		{
			ft_push_b(stack_a, stack_b);
			ft_rotate_b(stack_b);
			pushed++;
		}
		else if ((*stack_a)->index <= pushed + chunk)
		{
			ft_push_b(stack_a, stack_b);
			pushed++;
		}
		else
			ft_rotate_a(stack_a);
	}
}

static int	get_pos(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != value)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	rotate_b_to_top(t_list **stack_b, int pos, int size)
{
	int	i;

	i = 0;
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			ft_rotate_b(stack_b);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			ft_reverse_rotate_b(stack_b);
			i++;
		}
	}
}

void	ft_chunked_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk;

	chunk = ft_sqrt(ft_lstsize(*stack_a)) * 3 / 2;
	if (chunk < 1)
		chunk = 1;
	push_chunks(stack_a, stack_b, chunk);
	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		rotate_b_to_top(stack_b, get_pos(*stack_b, size - 1), size);
		ft_push_a(stack_a, stack_b);
	}
}
