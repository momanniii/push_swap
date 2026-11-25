/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 23:02:37 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/23 22:35:06 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

static void	radix_pass(t_list **a, t_list **b, int bit)
{
	int	size;
	int	i;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			ft_push_b(a, b);
		else
			ft_rotate_a(a);
		i++;
	}
	while (*b)
		ft_push_a(a, b);
}

void	radix_sort(t_list **a, t_list **b)
{
	int	max_index;
	int	max_bits;
	int	bit;

	if (!a || !*a)
		return ;
	max_index = ft_lstsize(*a) - 1;
	max_bits = 0;
	bit = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit);
		bit++;
	}
}
