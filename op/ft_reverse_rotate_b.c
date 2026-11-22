/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:20:29 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/14 21:22:05 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_reverse_rotate_b(t_list **stack_b)
{
	if (do_reverse_rotate(stack_b))
		ft_print_op("rrb");
}
