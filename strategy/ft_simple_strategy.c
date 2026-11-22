/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_strategy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 18:38:21 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/15 17:07:03 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static t_list	*find_min(t_list *stack_a)
{
	t_list	*min;

	if (!stack_a)
		return (NULL);
	min = stack_a;
	while (stack_a)
	{
		if (stack_a->content < min->content)
			min = stack_a;
		stack_a = stack_a->next;
	}
	return (min);
}

static int	get_pos(t_list *stack, t_list *target)
{
	int	pos;

	pos = 0;
	while (stack != target)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	bring_to_top(t_list **stack_a, t_list *min)
{
	int	pos;
	int	size;

	pos = get_pos(*stack_a, min);
	size = ft_lstsize(*stack_a);
	if (pos > size / 2)
		pos = pos - size;
	while (pos > 0)
	{
		ft_rotate_a(stack_a);
		pos--;
	}
	while (pos < 0)
	{
		ft_reverse_rotate_a(stack_a);
		pos++;
	}
}

void	ft_selection_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (*stack_a)
	{
		min = find_min(*stack_a);
		bring_to_top(stack_a, min);
		ft_push_b(stack_a, stack_b);
	}
	while (*stack_b)
		ft_push_a(stack_a, stack_b);
}
