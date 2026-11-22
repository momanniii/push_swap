/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a_and_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgharaib <wgharaib@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 19:13:48 by wgharaib          #+#    #+#             */
/*   Updated: 2026/11/14 21:16:48 by wgharaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
	ft_print_op("ss");
}
